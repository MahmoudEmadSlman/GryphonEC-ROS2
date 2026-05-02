// NOTE: This node is now OPTIONAL. The GryphonInterface hardware plugin subscribes
// directly to /hardware_command via an internal node and a thread-safe queue.
// This node is kept only for logging/monitoring purposes.
// You can safely remove it from your launch files.

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class HardwareCommandNode : public rclcpp::Node
{
public:
  HardwareCommandNode() : Node("hardware_command_node")
  {
    using std::placeholders::_1;
    subscription_ = this->create_subscription<std_msgs::msg::String>(
      "/hardware_command", 10,
      std::bind(&HardwareCommandNode::command_callback, this, _1));

    RCLCPP_INFO(this->get_logger(),
      "Hardware command monitor started. "
      "NOTE: GryphonInterface now subscribes directly to /hardware_command. "
      "This node is optional and only logs commands for debugging.");
  }

private:
  void command_callback(const std_msgs::msg::String::SharedPtr msg)
  {
    RCLCPP_INFO(this->get_logger(), "Command received: '%s'", msg->data.c_str());
    // No file writing - GryphonInterface handles commands directly via ROS2 subscription
  }

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<HardwareCommandNode>());
  rclcpp::shutdown();
  return 0;
}