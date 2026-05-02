#include "thor_controller/thor_interface.hpp"
#include <hardware_interface/types/hardware_interface_type_values.hpp>
#include <pluginlib/class_list_macros.hpp>

namespace thor_controller
{

ThorInterface::ThorInterface()
{
}

ThorInterface::~ThorInterface()
{
  if (thor_.IsOpen()) {
    try {
      thor_.Close();
    } catch (...) {
      RCLCPP_FATAL_STREAM(rclcpp::get_logger("ThorInterface"),
        "Something went wrong while closing connection with port " << port_);
    }
  }
}

// ---------------------------------------------------------------------------
// on_init — called once when the hardware plugin is loaded
// ---------------------------------------------------------------------------
CallbackReturn ThorInterface::on_init(const hardware_interface::HardwareInfo &hardware_info)
{
  CallbackReturn result = hardware_interface::SystemInterface::on_init(hardware_info);
  if (result != CallbackReturn::SUCCESS) {
    return result;
  }

  // Read serial port param from URDF xacro
  try {
    port_ = info_.hardware_parameters.at("port");
  } catch (const std::out_of_range &) {
    RCLCPP_FATAL(rclcpp::get_logger("ThorInterface"),
      "No 'port' parameter provided in URDF hardware tag! Aborting.");
    return CallbackReturn::FAILURE;
  }

  // Reserve storage for 6 joints: joint_1..5 + gripper
  // Internally we track 7 GRBL motor angles (shoulder has 2 motors: B & C)
  const size_t n_joints = info_.joints.size(); // expected: 6
  position_commands_.assign(n_joints, 0.0);
  position_states_.assign(n_joints, 0.0);
  curr_angles_.assign(8, 0);   // 7 GRBL axes (A B C D X Y Z) + 1 gripper deg
  prev_angles_.assign(8, 0);

  RCLCPP_INFO_STREAM(rclcpp::get_logger("ThorInterface"),
    "on_init — joints: " << n_joints << ", port: " << port_);

  // Internal ROS2 node for receiving raw hardware commands on /hardware_command
  command_node_ = rclcpp::Node::make_shared("gryphon_hardware_command_listener");
  command_subscription_ = command_node_->create_subscription<std_msgs::msg::String>(
    "/hardware_command", rclcpp::QoS(10),
    std::bind(&ThorInterface::commandCallback, this, std::placeholders::_1));
  RCLCPP_INFO(rclcpp::get_logger("ThorInterface"), "Subscribed to /hardware_command");

  return CallbackReturn::SUCCESS;
}

// ---------------------------------------------------------------------------
// export_state_interfaces — expose position states to ros2_control
// ---------------------------------------------------------------------------
std::vector<hardware_interface::StateInterface> ThorInterface::export_state_interfaces()
{
  std::vector<hardware_interface::StateInterface> state_interfaces;
  for (size_t i = 0; i < info_.joints.size(); i++) {
    state_interfaces.emplace_back(
      info_.joints[i].name, hardware_interface::HW_IF_POSITION, &position_states_[i]);
  }
  return state_interfaces;
}

// ---------------------------------------------------------------------------
// export_command_interfaces — expose position commands from ros2_control
// ---------------------------------------------------------------------------
std::vector<hardware_interface::CommandInterface> ThorInterface::export_command_interfaces()
{
  std::vector<hardware_interface::CommandInterface> command_interfaces;
  for (size_t i = 0; i < info_.joints.size(); i++) {
    command_interfaces.emplace_back(
      info_.joints[i].name, hardware_interface::HW_IF_POSITION, &position_commands_[i]);
  }
  return command_interfaces;
}

// ---------------------------------------------------------------------------
// on_activate — open serial port and wait for GRBL to boot
// ---------------------------------------------------------------------------
CallbackReturn ThorInterface::on_activate(const rclcpp_lifecycle::State & /*previous_state*/)
{
  RCLCPP_INFO(rclcpp::get_logger("ThorInterface"), "Starting Gryphon hardware ...");

  // Initialize all joints to zero position
  const size_t n_joints = info_.joints.size();
  position_commands_.assign(n_joints, 0.0);
  position_states_.assign(n_joints, 0.0);
  curr_angles_.assign(8, 0);
  prev_angles_.assign(8, 0);

  try {
    thor_.Open(port_);
    thor_.SetBaudRate(LibSerial::BaudRate::BAUD_115200);
    // Wait 2 s for GRBL to initialise and send its welcome message
    std::this_thread::sleep_for(std::chrono::seconds(2));
  } catch (...) {
    RCLCPP_FATAL_STREAM(rclcpp::get_logger("ThorInterface"),
      "Failed to open serial port " << port_);
    return CallbackReturn::FAILURE;
  }

  RCLCPP_INFO(rclcpp::get_logger("ThorInterface"),
    "Gryphon hardware started — ready to accept commands on port %s", port_.c_str());
  return CallbackReturn::SUCCESS;
}

// ---------------------------------------------------------------------------
// on_deactivate — close serial port cleanly
// ---------------------------------------------------------------------------
CallbackReturn ThorInterface::on_deactivate(const rclcpp_lifecycle::State & /*previous_state*/)
{
  RCLCPP_INFO(rclcpp::get_logger("ThorInterface"), "Stopping Gryphon hardware ...");

  command_subscription_.reset();

  if (thor_.IsOpen()) {
    try {
      thor_.Close();
    } catch (...) {
      RCLCPP_FATAL_STREAM(rclcpp::get_logger("ThorInterface"),
        "Failed to close serial port " << port_);
    }
  }

  RCLCPP_INFO(rclcpp::get_logger("ThorInterface"), "Gryphon hardware stopped.");
  return CallbackReturn::SUCCESS;
}

// ---------------------------------------------------------------------------
// read — open-loop: mirror position_commands_ into position_states_
//         Also drain any external /hardware_command messages.
// ---------------------------------------------------------------------------
hardware_interface::return_type ThorInterface::read(
  const rclcpp::Time & /*time*/, const rclcpp::Duration & /*period*/)
{
  // Open-loop: no position feedback from the Gryphon Arduino.
  // Reflect last written commands back as the current state so that
  // ros2_control considers the trajectory executed.
  position_states_ = position_commands_;

  // Spin the internal node to collect any incoming /hardware_command messages
  rclcpp::spin_some(command_node_);

  // Drain and send any queued external commands over serial
  {
    std::lock_guard<std::mutex> lock(queue_mutex_);
    while (!command_queue_.empty()) {
      std::string command = command_queue_.front();
      command_queue_.pop();
      RCLCPP_INFO(rclcpp::get_logger("ThorInterface"),
        "Executing external command: %s", command.c_str());
      try {
        thor_.Write(command + "\r\n");
      } catch (const std::exception &e) {
        RCLCPP_ERROR(rclcpp::get_logger("ThorInterface"),
          "Failed to send command '%s': %s", command.c_str(), e.what());
      }
    }
  }

  return hardware_interface::return_type::OK;
}

// ---------------------------------------------------------------------------
// commandCallback — thread-safe enqueue for /hardware_command topic
// ---------------------------------------------------------------------------
void ThorInterface::commandCallback(const std_msgs::msg::String::SharedPtr msg)
{
  std::lock_guard<std::mutex> lock(queue_mutex_);
  command_queue_.push(msg->data);
  RCLCPP_DEBUG(rclcpp::get_logger("ThorInterface"),
    "Queued external command: %s", msg->data.c_str());
}

// ---------------------------------------------------------------------------
// write — convert ros2_control joint positions (rad) → GRBL G-code → serial
//
// Joint index mapping (matches URDF joint order):
//   [0] joint_1  → GRBL A  (waist)
//   [1] joint_2  → GRBL B & C  (shoulder — dual motor, B must equal C)
//   [2] joint_3  → GRBL D  (elbow)
//   [3] joint_4  → GRBL X  (wrist pitch)
//   [4] joint_5  → GRBL Y & Z  (differential wrist roll)
//   [5] gripper  → M3 S255 / M5  (pneumatic valve ON/OFF)
//
// Angle convention (degrees, matching Thor ControlPCB firmware):
//   art1 = joint_1 offset to Thor home: -90 + (cmd + π/2) * 180/π
//   art2 = joint_2 inverted:             90 - (cmd + π/2) * 180/π
//   art3 = joint_3 inverted:             90 - (cmd + π/2) * 180/π
//   art4 = joint_4 direct:               cmd * 180/π
//   art5 = joint_5 inverted:            -cmd * 180/π
//   Differential wrist (2 GRBL axes):
//     m_art5 (GRBL Y) = art5 + 2*art6   (where art6=0 for this arm)
//     m_art6 (GRBL Z) = -art5 + 2*art6
//   Pneumatic valve (binary):
//     gripper_cmd ≠ 0  → M3 S255  (valve ON, grip)
//     gripper_cmd = 0  → M5       (valve OFF, release)
// ---------------------------------------------------------------------------
hardware_interface::return_type ThorInterface::write(
  const rclcpp::Time & /*time*/, const rclcpp::Duration & /*period*/)
{
  // --- Arm joint angles (degrees) ---
  // joint_1 (waist)
  int art1 = -90 + static_cast<int>(((position_commands_[0] + (M_PI / 2)) * 180) / M_PI);
  // joint_2 (shoulder, dual-motor — B & C must be equal)
  int art2 = 90 - static_cast<int>(((position_commands_[1] + (M_PI / 2)) * 180) / M_PI);
  // joint_3 (elbow)
  int art3 = 90 - static_cast<int>(((position_commands_[2] + (M_PI / 2)) * 180) / M_PI);
  // joint_4 (wrist pitch)
  int art4 = static_cast<int>((position_commands_[3] * 180) / M_PI);
  // joint_5 (wrist roll, differential)
  int art5 = static_cast<int>((-position_commands_[4] * 180) / M_PI);

  // Differential wrist: GRBL Y & Z
  // art6 = 0 (Gryphon has no 6th wrist joint)
  const int art6 = 0;
  int m_art5 = art5 + 2 * art6;   // GRBL Y
  int m_art6 = -art5 + 2 * art6;  // GRBL Z

  // Pneumatic gripper: binary valve control (ON / OFF)
  // Any non-zero gripper command → valve ON (grip)
  // Zero gripper command → valve OFF (release)
  int valve_state = (std::abs(position_commands_[5]) > 0.01) ? 1 : 0;

  // curr_angles_ layout (8 entries):
  //   [0] A (art1)   [1] B (art2)   [2] C (art2, =B)   [3] D (art3)
  //   [4] X (art4)   [5] Y (m_art5) [6] Z (m_art6)     [7] valve (0/1)
  curr_angles_ = {art1, art2, art2, art3, art4, m_art5, m_art6, valve_state};

  // Skip if nothing changed (reduces serial traffic)
  if (curr_angles_ == prev_angles_) {
    return hardware_interface::return_type::OK;
  }

  // --- Send arm move command if any motor axis changed ---
  bool arm_changed =
    curr_angles_[0] != prev_angles_[0] ||
    curr_angles_[1] != prev_angles_[1] ||
    curr_angles_[3] != prev_angles_[3] ||
    curr_angles_[4] != prev_angles_[4] ||
    curr_angles_[5] != prev_angles_[5] ||
    curr_angles_[6] != prev_angles_[6];

  if (arm_changed) {
    std::string msg = "G0 ";
    msg += "A" + std::to_string(art1)  + " ";
    msg += "B" + std::to_string(art2)  + " ";
    msg += "C" + std::to_string(art2)  + " ";  // C must equal B (dual-motor shoulder)
    msg += "D" + std::to_string(art3)  + " ";
    msg += "X" + std::to_string(art4)  + " ";
    msg += "Y" + std::to_string(m_art5) + " ";
    msg += "Z" + std::to_string(m_art6) + "\r\n";

    try {
      RCLCPP_INFO_STREAM(rclcpp::get_logger("ThorInterface"), "→ " << msg);
      thor_.Write(msg);
    } catch (...) {
      RCLCPP_ERROR_STREAM(rclcpp::get_logger("ThorInterface"),
        "Failed to send arm command: " << msg);
      return hardware_interface::return_type::ERROR;
    }
  }

  // --- Send pneumatic valve command if changed ---
  bool gripper_changed = (curr_angles_[7] != prev_angles_[7]);

  if (gripper_changed) {
    std::string msg;
    if (valve_state == 1) {
      msg = "M3 S255\r\n";  // Valve ON → gripper closes
    } else {
      msg = "M5\r\n";       // Valve OFF → gripper opens
    }
    try {
      RCLCPP_INFO_STREAM(rclcpp::get_logger("ThorInterface"),
        "→ Valve " << (valve_state ? "ON" : "OFF") << " : " << msg);
      thor_.Write(msg);
    } catch (...) {
      RCLCPP_ERROR_STREAM(rclcpp::get_logger("ThorInterface"),
        "Failed to send valve command: " << msg);
      return hardware_interface::return_type::ERROR;
    }
  }

  prev_angles_ = curr_angles_;
  return hardware_interface::return_type::OK;
}

} // namespace thor_controller

PLUGINLIB_EXPORT_CLASS(thor_controller::ThorInterface, hardware_interface::SystemInterface)