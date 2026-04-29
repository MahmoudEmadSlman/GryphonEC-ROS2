// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from thor_msgs:msg/CartesianGoal.idl
// generated code does not contain a copyright notice

#ifndef THOR_MSGS__MSG__DETAIL__CARTESIAN_GOAL__BUILDER_HPP_
#define THOR_MSGS__MSG__DETAIL__CARTESIAN_GOAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "thor_msgs/msg/detail/cartesian_goal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace thor_msgs
{

namespace msg
{

namespace builder
{

class Init_CartesianGoal_avoid_collisions
{
public:
  explicit Init_CartesianGoal_avoid_collisions(::thor_msgs::msg::CartesianGoal & msg)
  : msg_(msg)
  {}
  ::thor_msgs::msg::CartesianGoal avoid_collisions(::thor_msgs::msg::CartesianGoal::_avoid_collisions_type arg)
  {
    msg_.avoid_collisions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::thor_msgs::msg::CartesianGoal msg_;
};

class Init_CartesianGoal_jump_threshold
{
public:
  explicit Init_CartesianGoal_jump_threshold(::thor_msgs::msg::CartesianGoal & msg)
  : msg_(msg)
  {}
  Init_CartesianGoal_avoid_collisions jump_threshold(::thor_msgs::msg::CartesianGoal::_jump_threshold_type arg)
  {
    msg_.jump_threshold = std::move(arg);
    return Init_CartesianGoal_avoid_collisions(msg_);
  }

private:
  ::thor_msgs::msg::CartesianGoal msg_;
};

class Init_CartesianGoal_max_step
{
public:
  explicit Init_CartesianGoal_max_step(::thor_msgs::msg::CartesianGoal & msg)
  : msg_(msg)
  {}
  Init_CartesianGoal_jump_threshold max_step(::thor_msgs::msg::CartesianGoal::_max_step_type arg)
  {
    msg_.max_step = std::move(arg);
    return Init_CartesianGoal_jump_threshold(msg_);
  }

private:
  ::thor_msgs::msg::CartesianGoal msg_;
};

class Init_CartesianGoal_gripperbase_to_armgearright
{
public:
  explicit Init_CartesianGoal_gripperbase_to_armgearright(::thor_msgs::msg::CartesianGoal & msg)
  : msg_(msg)
  {}
  Init_CartesianGoal_max_step gripperbase_to_armgearright(::thor_msgs::msg::CartesianGoal::_gripperbase_to_armgearright_type arg)
  {
    msg_.gripperbase_to_armgearright = std::move(arg);
    return Init_CartesianGoal_max_step(msg_);
  }

private:
  ::thor_msgs::msg::CartesianGoal msg_;
};

class Init_CartesianGoal_end_pose
{
public:
  explicit Init_CartesianGoal_end_pose(::thor_msgs::msg::CartesianGoal & msg)
  : msg_(msg)
  {}
  Init_CartesianGoal_gripperbase_to_armgearright end_pose(::thor_msgs::msg::CartesianGoal::_end_pose_type arg)
  {
    msg_.end_pose = std::move(arg);
    return Init_CartesianGoal_gripperbase_to_armgearright(msg_);
  }

private:
  ::thor_msgs::msg::CartesianGoal msg_;
};

class Init_CartesianGoal_start_pose
{
public:
  Init_CartesianGoal_start_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CartesianGoal_end_pose start_pose(::thor_msgs::msg::CartesianGoal::_start_pose_type arg)
  {
    msg_.start_pose = std::move(arg);
    return Init_CartesianGoal_end_pose(msg_);
  }

private:
  ::thor_msgs::msg::CartesianGoal msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::thor_msgs::msg::CartesianGoal>()
{
  return thor_msgs::msg::builder::Init_CartesianGoal_start_pose();
}

}  // namespace thor_msgs

#endif  // THOR_MSGS__MSG__DETAIL__CARTESIAN_GOAL__BUILDER_HPP_
