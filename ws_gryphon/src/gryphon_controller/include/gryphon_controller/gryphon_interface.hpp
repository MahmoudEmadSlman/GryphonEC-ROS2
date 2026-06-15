#ifndef GRYPHON_INTERFACE_H
#define GRYPHON_INTERFACE_H

#include <rclcpp/rclcpp.hpp>
#include <hardware_interface/system_interface.hpp>
#include <libserial/SerialPort.h>
#include <rclcpp_lifecycle/state.hpp>
#include <rclcpp_lifecycle/node_interfaces/lifecycle_node_interface.hpp>
#include <std_msgs/msg/string.hpp>

#include <vector>
#include <string>
#include <mutex>
#include <queue>
#include <memory>
#include <thread>
#include <atomic>

namespace gryphon_controller
{

using CallbackReturn = rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;

/**
 * Gryphon Hardware Interface — ros2_control plugin
 *
 * Controls the Gryphon 5-DOF robotic arm via custom Arduino firmware.
 * Protocol: Text commands over serial @ 115200 baud.
 *
 * Open-loop stepper control — no encoders.
 * Position feedback is derived from step counters in the Arduino firmware.
 *
 * Joint mapping (6 joints: joint_1..5 + gripper):
 *   joint_1  → Motor 1  (waist)
 *   joint_2  → Motor 2  (shoulder)
 *   joint_3  → Motor 3  (elbow)
 *   joint_4  → J4: both wrist motors same direction
 *   joint_5  → J5: wrist motors in opposite directions
 *   gripper  → Relay on Pin 42  (ON/OFF)
 *
 * Arduino sends "POS:<d1>,<d2>,<d3>,<d4>,<d5>" every 20ms (from step counters).
 */
class GryphonInterface : public hardware_interface::SystemInterface
{
public:
  GryphonInterface();
  virtual ~GryphonInterface();

  // Lifecycle callbacks
  virtual CallbackReturn on_activate(const rclcpp_lifecycle::State &previous_state) override;
  virtual CallbackReturn on_deactivate(const rclcpp_lifecycle::State &previous_state) override;

  // hardware_interface::SystemInterface
  virtual CallbackReturn on_init(const hardware_interface::HardwareInfo &hardware_info) override;
  virtual std::vector<hardware_interface::StateInterface> export_state_interfaces() override;
  virtual std::vector<hardware_interface::CommandInterface> export_command_interfaces() override;
  virtual hardware_interface::return_type read(const rclcpp::Time &time, const rclcpp::Duration &period) override;
  virtual hardware_interface::return_type write(const rclcpp::Time &time, const rclcpp::Duration &period) override;

private:
  /// Serial connection to Arduino Mega (unique_ptr so we can destroy it
  /// safely inside a try-catch, preventing LibSerial's destructor from
  /// propagating exceptions and crashing the process).
  std::unique_ptr<LibSerial::SerialPort> gryphon_;
  std::string port_;                ///< Serial port (e.g. /dev/ttyACM0)
  std::atomic<bool> arduino_connected_{false};  ///< true when serial is open & ready

  // 6 joints: joint_1..5 + gripper
  std::vector<double> position_commands_;  ///< Commands from ros2_control (radians)
  std::vector<double> position_states_;    ///< Estimated position from Arduino step counters (radians)

  // Previous command cache (to detect changes and reduce serial traffic)
  std::vector<double> prev_commands_;

  // Previous gripper state
  int prev_gripper_state_;

  // Serial receive buffer (accumulate chars until newline)
  std::string serial_rx_buf_;

  // Thread-safe queue for external hardware commands via /hardware_command topic
  rclcpp::Node::SharedPtr command_node_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr command_subscription_;
  std::queue<std::string> command_queue_;
  std::mutex queue_mutex_;

  void commandCallback(const std_msgs::msg::String::SharedPtr msg);

  /// Parse a "POS:<d1>,<d2>,<d3>,<d4>,<d5>" line and update position_states_
  void parsePositionReport(const std::string &line);

  /// Process all complete lines waiting in the serial buffer
  void drainSerial();

  /// Send a raw string over serial
  void sendCommand(const std::string &cmd);
};

} // namespace gryphon_controller

#endif  // GRYPHON_INTERFACE_H