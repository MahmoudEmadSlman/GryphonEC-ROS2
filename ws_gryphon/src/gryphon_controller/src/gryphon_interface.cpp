#include "gryphon_controller/gryphon_interface.hpp"
#include <hardware_interface/types/hardware_interface_type_values.hpp>
#include <pluginlib/class_list_macros.hpp>
#include <sstream>
#include <cmath>

namespace gryphon_controller {

GryphonInterface::GryphonInterface() : prev_gripper_state_(-1) {}

GryphonInterface::~GryphonInterface() {
  if (gryphon_.IsOpen()) {
    try {
      gryphon_.Close();
    } catch (...) {
      RCLCPP_FATAL_STREAM(
          rclcpp::get_logger("GryphonInterface"),
          "Something went wrong while closing connection with port " << port_);
    }
  }
}

// ---------------------------------------------------------------------------
// on_init — called once when the hardware plugin is loaded
// ---------------------------------------------------------------------------
CallbackReturn GryphonInterface::on_init(
    const hardware_interface::HardwareInfo &hardware_info) {
  CallbackReturn result =
      hardware_interface::SystemInterface::on_init(hardware_info);
  if (result != CallbackReturn::SUCCESS) {
    return result;
  }

  // Read serial port param from URDF xacro
  try {
    port_ = info_.hardware_parameters.at("port");
  } catch (const std::out_of_range &) {
    RCLCPP_FATAL(
        rclcpp::get_logger("GryphonInterface"),
        "No 'port' parameter provided in URDF hardware tag! Aborting.");
    return CallbackReturn::FAILURE;
  }

  // Reserve storage for 6 joints: joint_1..5 + gripper
  const size_t n_joints = info_.joints.size(); // expected: 6
  position_commands_.assign(n_joints, 0.0);
  position_states_.assign(n_joints, 0.0);
  prev_commands_.assign(n_joints, 0.0);
  prev_gripper_state_ = -1;

  RCLCPP_INFO_STREAM(rclcpp::get_logger("GryphonInterface"),
                     "on_init — joints: " << n_joints << ", port: " << port_);

  // Internal ROS2 node for receiving raw hardware commands on /hardware_command
  command_node_ =
      rclcpp::Node::make_shared("gryphon_hardware_command_listener");
  command_subscription_ =
      command_node_->create_subscription<std_msgs::msg::String>(
          "/hardware_command", rclcpp::QoS(10),
          std::bind(&GryphonInterface::commandCallback, this,
                    std::placeholders::_1));
  RCLCPP_INFO(rclcpp::get_logger("GryphonInterface"),
              "Subscribed to /hardware_command");

  return CallbackReturn::SUCCESS;
}

// ---------------------------------------------------------------------------
// export_state_interfaces — expose position states to ros2_control
// ---------------------------------------------------------------------------
std::vector<hardware_interface::StateInterface>
GryphonInterface::export_state_interfaces() {
  std::vector<hardware_interface::StateInterface> state_interfaces;
  for (size_t i = 0; i < info_.joints.size(); i++) {
    state_interfaces.emplace_back(info_.joints[i].name,
                                  hardware_interface::HW_IF_POSITION,
                                  &position_states_[i]);
  }
  return state_interfaces;
}

// ---------------------------------------------------------------------------
// export_command_interfaces — expose position commands from ros2_control
// ---------------------------------------------------------------------------
std::vector<hardware_interface::CommandInterface>
GryphonInterface::export_command_interfaces() {
  std::vector<hardware_interface::CommandInterface> command_interfaces;
  for (size_t i = 0; i < info_.joints.size(); i++) {
    command_interfaces.emplace_back(info_.joints[i].name,
                                    hardware_interface::HW_IF_POSITION,
                                    &position_commands_[i]);
  }
  return command_interfaces;
}

// ---------------------------------------------------------------------------
// on_activate — open serial port and wait for Arduino to boot
// ---------------------------------------------------------------------------
CallbackReturn GryphonInterface::on_activate(
    const rclcpp_lifecycle::State & /*previous_state*/) {
  RCLCPP_INFO(rclcpp::get_logger("GryphonInterface"),
              "Starting Gryphon hardware ...");

  // Initialize all joints to zero position
  const size_t n_joints = info_.joints.size();
  position_commands_.assign(n_joints, 0.0);
  position_states_.assign(n_joints, 0.0);
  prev_commands_.assign(n_joints, 0.0);
  prev_gripper_state_ = -1;
  serial_rx_buf_.clear();

  try {
    gryphon_.Open(port_);
    gryphon_.SetBaudRate(LibSerial::BaudRate::BAUD_115200);
    // Wait for Arduino to reset and send "RDY"
    std::this_thread::sleep_for(std::chrono::seconds(2));
  } catch (...) {
    RCLCPP_FATAL_STREAM(rclcpp::get_logger("GryphonInterface"),
                        "Failed to open serial port " << port_);
    return CallbackReturn::FAILURE;
  }

  // Drain any boot messages
  drainSerial();

  RCLCPP_INFO(rclcpp::get_logger("GryphonInterface"),
              "Gryphon hardware started — ready on port %s", port_.c_str());
  return CallbackReturn::SUCCESS;
}

// ---------------------------------------------------------------------------
// on_deactivate — close serial port cleanly
// ---------------------------------------------------------------------------
CallbackReturn GryphonInterface::on_deactivate(
    const rclcpp_lifecycle::State & /*previous_state*/) {
  RCLCPP_INFO(rclcpp::get_logger("GryphonInterface"),
              "Stopping Gryphon hardware ...");

  command_subscription_.reset();

  if (gryphon_.IsOpen()) {
    try {
      // Send emergency stop before closing
      sendCommand("STP");
      gryphon_.Close();
    } catch (...) {
      RCLCPP_FATAL_STREAM(rclcpp::get_logger("GryphonInterface"),
                          "Failed to close serial port " << port_);
    }
  }

  RCLCPP_INFO(rclcpp::get_logger("GryphonInterface"),
              "Gryphon hardware stopped.");
  return CallbackReturn::SUCCESS;
}

// ---------------------------------------------------------------------------
// read — parse encoder feedback from Arduino, drain external commands
// ---------------------------------------------------------------------------
hardware_interface::return_type
GryphonInterface::read(const rclcpp::Time & /*time*/,
                       const rclcpp::Duration & /*period*/) {
  // Read and parse all available serial data (POS reports, OK, ERR, etc.)
  drainSerial();

  // Spin the internal node to collect any incoming /hardware_command messages
  rclcpp::spin_some(command_node_);

  // Drain and send any queued external commands over serial
  {
    std::lock_guard<std::mutex> lock(queue_mutex_);
    while (!command_queue_.empty()) {
      std::string command = command_queue_.front();
      command_queue_.pop();
      RCLCPP_INFO(rclcpp::get_logger("GryphonInterface"),
                  "Executing external command: %s", command.c_str());
      sendCommand(command);
    }
  }

  return hardware_interface::return_type::OK;
}

// ---------------------------------------------------------------------------
// write — convert ros2_control joint positions (rad) → Arduino MOV command
//
// Joint index mapping (matches URDF joint order):
//   [0] joint_1  → Motor 1  (waist)
//   [1] joint_2  → Motor 2  (shoulder)
//   [2] joint_3  → Motor 3  (elbow)
//   [3] joint_4  → Motor 4  (diff wrist pitch — Arduino handles kinematics)
//   [4] joint_5  → Motor 5  (diff wrist roll  — Arduino handles kinematics)
//   [5] gripper  → Relay    (GRP:0 / GRP:1)
// ---------------------------------------------------------------------------
hardware_interface::return_type
GryphonInterface::write(const rclcpp::Time & /*time*/,
                        const rclcpp::Duration & /*period*/) {

  // --- Check if arm joints changed ---
  bool arm_changed = false;
  for (int i = 0; i < 5; i++) {
    if (std::abs(position_commands_[i] - prev_commands_[i]) > 1e-4) {
      arm_changed = true;
      break;
    }
  }

  if (arm_changed) {
    // Convert radians → degrees for all 5 joints
    std::ostringstream oss;
    oss << "MOV:";
    for (int i = 0; i < 5; i++) {
      double deg = position_commands_[i] * 180.0 / M_PI;
      oss << std::fixed;
      oss.precision(2);
      oss << deg;
      if (i < 4) oss << ",";
    }

    try {
      std::string msg = oss.str();
      RCLCPP_INFO_STREAM(rclcpp::get_logger("GryphonInterface"), "→ " << msg);
      sendCommand(msg);
    } catch (...) {
      RCLCPP_ERROR(rclcpp::get_logger("GryphonInterface"),
                   "Failed to send MOV command");
      return hardware_interface::return_type::ERROR;
    }

    for (int i = 0; i < 5; i++) {
      prev_commands_[i] = position_commands_[i];
    }
  }

  // --- Gripper (relay ON/OFF) ---
  int gripper_state = (std::abs(position_commands_[5]) > 0.01) ? 1 : 0;

  if (gripper_state != prev_gripper_state_) {
    std::string msg = "GRP:" + std::to_string(gripper_state);
    try {
      RCLCPP_INFO_STREAM(rclcpp::get_logger("GryphonInterface"),
                         "→ Gripper " << (gripper_state ? "ON" : "OFF")
                                      << " : " << msg);
      sendCommand(msg);
    } catch (...) {
      RCLCPP_ERROR(rclcpp::get_logger("GryphonInterface"),
                   "Failed to send GRP command");
      return hardware_interface::return_type::ERROR;
    }
    prev_gripper_state_ = gripper_state;
  }

  return hardware_interface::return_type::OK;
}

// ---------------------------------------------------------------------------
// commandCallback — thread-safe enqueue for /hardware_command topic
// ---------------------------------------------------------------------------
void GryphonInterface::commandCallback(
    const std_msgs::msg::String::SharedPtr msg) {
  std::lock_guard<std::mutex> lock(queue_mutex_);
  command_queue_.push(msg->data);
  RCLCPP_DEBUG(rclcpp::get_logger("GryphonInterface"),
               "Queued external command: %s", msg->data.c_str());
}

// ---------------------------------------------------------------------------
// parsePositionReport — parse "POS:<d1>,<d2>,<d3>,<d4>,<d5>" → radians
// ---------------------------------------------------------------------------
void GryphonInterface::parsePositionReport(const std::string &line) {
  // Expected format: "POS:12.34,56.78,90.12,34.56,78.90"
  if (line.size() < 5) return;

  std::string data = line.substr(4); // skip "POS:"
  std::istringstream iss(data);
  std::string token;
  int idx = 0;

  while (std::getline(iss, token, ',') && idx < 5) {
    try {
      double deg = std::stod(token);
      double rad = deg * M_PI / 180.0;
      position_states_[idx] = rad;
    } catch (...) {
      // Skip malformed values
    }
    idx++;
  }

  // Gripper state: keep mirroring the command (relay has no feedback)
  if (info_.joints.size() > 5) {
    position_states_[5] = position_commands_[5];
  }
}

// ---------------------------------------------------------------------------
// drainSerial — read all available bytes, split into lines, process each
// ---------------------------------------------------------------------------
void GryphonInterface::drainSerial() {
  try {
    while (gryphon_.IsOpen() && gryphon_.IsDataAvailable()) {
      char c;
      gryphon_.ReadByte(c, 0); // non-blocking read

      if (c == '\n' || c == '\r') {
        if (!serial_rx_buf_.empty()) {
          // Process the complete line
          if (serial_rx_buf_.rfind("POS:", 0) == 0) {
            parsePositionReport(serial_rx_buf_);
          } else if (serial_rx_buf_ == "OK") {
            // Command acknowledged — no action needed
          } else if (serial_rx_buf_.rfind("ERR:", 0) == 0) {
            RCLCPP_WARN_STREAM(rclcpp::get_logger("GryphonInterface"),
                               "← ERROR: " << serial_rx_buf_);
          } else if (serial_rx_buf_.rfind("HMD:", 0) == 0) {
            RCLCPP_INFO_STREAM(rclcpp::get_logger("GryphonInterface"),
                               "← Homing done: " << serial_rx_buf_);
          } else if (serial_rx_buf_.rfind("HOM_", 0) == 0) {
            RCLCPP_INFO_STREAM(rclcpp::get_logger("GryphonInterface"),
                               "← " << serial_rx_buf_);
          } else if (serial_rx_buf_ == "RDY") {
            RCLCPP_INFO(rclcpp::get_logger("GryphonInterface"),
                        "← Arduino ready");
          } else {
            RCLCPP_DEBUG_STREAM(rclcpp::get_logger("GryphonInterface"),
                                "← " << serial_rx_buf_);
          }
          serial_rx_buf_.clear();
        }
      } else {
        serial_rx_buf_ += c;
      }
    }
  } catch (...) {
    // Ignore read errors (timeout, etc.)
  }
}

// ---------------------------------------------------------------------------
// sendCommand — write a command string + newline to serial
// ---------------------------------------------------------------------------
void GryphonInterface::sendCommand(const std::string &cmd) {
  if (gryphon_.IsOpen()) {
    gryphon_.Write(cmd + "\n");
  }
}

} // namespace gryphon_controller

PLUGINLIB_EXPORT_CLASS(gryphon_controller::GryphonInterface,
                       hardware_interface::SystemInterface)