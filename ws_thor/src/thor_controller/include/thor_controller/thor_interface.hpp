#ifndef THOR_INTERFACE_H
#define THOR_INTERFACE_H

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

namespace thor_controller
{

using CallbackReturn = rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;

/**
 * Gryphon Hardware Interface — ros2_control plugin
 *
 * Controls the Gryphon 5-DOF robotic arm via GRBL firmware running on an Arduino Mega.
 * Protocol: GRBL G-code over serial @ 115200 baud (same as Thor ControlPCB).
 *
 * Joint mapping (6 joints: joint_1..5 + gripper):
 *   joint_1  → GRBL axis A  (waist)
 *   joint_2  → GRBL axis B  (shoulder, motor 2)
 *   joint_2  → GRBL axis C  (shoulder mirror, motor 3 — must equal B)
 *   joint_3  → GRBL axis D  (elbow)
 *   joint_4  → GRBL axis X  (wrist pitch)
 *   joint_5  → GRBL axes Y+Z (differential wrist roll — 2 motors)
 *   gripper  → GRBL M3 S255 / M5  (pneumatic valve ON/OFF)
 *
 * Open-loop: no position feedback from Arduino.
 * Position states mirror commands after each write.
 */
class ThorInterface : public hardware_interface::SystemInterface
{
public:
  ThorInterface();
  virtual ~ThorInterface();

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
  LibSerial::SerialPort thor_;   ///< Serial connection to Arduino Mega
  std::string port_;             ///< Serial port (e.g. /dev/ttyACM0)

  // 6 joints: joint_1, joint_2, joint_3, joint_4, joint_5, gripper
  std::vector<double> position_commands_;  ///< Commands from ros2_control (radians)
  std::vector<int>    curr_angles_;        ///< Current GRBL angles (degrees, 7 motors + 1 gripper)
  std::vector<int>    prev_angles_;        ///< Previous GRBL angles (for change detection)
  std::vector<double> position_states_;   ///< State feedback (mirrors commands — open-loop)

  // Thread-safe queue for external hardware commands via /hardware_command topic
  rclcpp::Node::SharedPtr command_node_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr command_subscription_;
  std::queue<std::string> command_queue_;
  std::mutex queue_mutex_;

  void commandCallback(const std_msgs::msg::String::SharedPtr msg);
};

} // namespace thor_controller

#endif  // THOR_INTERFACE_H