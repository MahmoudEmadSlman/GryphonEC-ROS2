// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from thor_msgs:msg/IKGoal.idl
// generated code does not contain a copyright notice

#ifndef THOR_MSGS__MSG__DETAIL__IK_GOAL__BUILDER_HPP_
#define THOR_MSGS__MSG__DETAIL__IK_GOAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "thor_msgs/msg/detail/ik_goal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace thor_msgs
{

namespace msg
{

namespace builder
{

class Init_IKGoal_gripperbase_to_armgearright
{
public:
  explicit Init_IKGoal_gripperbase_to_armgearright(::thor_msgs::msg::IKGoal & msg)
  : msg_(msg)
  {}
  ::thor_msgs::msg::IKGoal gripperbase_to_armgearright(::thor_msgs::msg::IKGoal::_gripperbase_to_armgearright_type arg)
  {
    msg_.gripperbase_to_armgearright = std::move(arg);
    return std::move(msg_);
  }

private:
  ::thor_msgs::msg::IKGoal msg_;
};

class Init_IKGoal_pose
{
public:
  Init_IKGoal_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IKGoal_gripperbase_to_armgearright pose(::thor_msgs::msg::IKGoal::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_IKGoal_gripperbase_to_armgearright(msg_);
  }

private:
  ::thor_msgs::msg::IKGoal msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::thor_msgs::msg::IKGoal>()
{
  return thor_msgs::msg::builder::Init_IKGoal_pose();
}

}  // namespace thor_msgs

#endif  // THOR_MSGS__MSG__DETAIL__IK_GOAL__BUILDER_HPP_
