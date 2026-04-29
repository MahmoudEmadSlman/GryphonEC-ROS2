// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from thor_msgs:msg/CartesianGoal.idl
// generated code does not contain a copyright notice

#ifndef THOR_MSGS__MSG__DETAIL__CARTESIAN_GOAL__TRAITS_HPP_
#define THOR_MSGS__MSG__DETAIL__CARTESIAN_GOAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "thor_msgs/msg/detail/cartesian_goal__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'start_pose'
// Member 'end_pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace thor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CartesianGoal & msg,
  std::ostream & out)
{
  out << "{";
  // member: start_pose
  {
    out << "start_pose: ";
    to_flow_style_yaml(msg.start_pose, out);
    out << ", ";
  }

  // member: end_pose
  {
    out << "end_pose: ";
    to_flow_style_yaml(msg.end_pose, out);
    out << ", ";
  }

  // member: gripperbase_to_armgearright
  {
    out << "gripperbase_to_armgearright: ";
    rosidl_generator_traits::value_to_yaml(msg.gripperbase_to_armgearright, out);
    out << ", ";
  }

  // member: max_step
  {
    out << "max_step: ";
    rosidl_generator_traits::value_to_yaml(msg.max_step, out);
    out << ", ";
  }

  // member: jump_threshold
  {
    out << "jump_threshold: ";
    rosidl_generator_traits::value_to_yaml(msg.jump_threshold, out);
    out << ", ";
  }

  // member: avoid_collisions
  {
    out << "avoid_collisions: ";
    rosidl_generator_traits::value_to_yaml(msg.avoid_collisions, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CartesianGoal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: start_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_pose:\n";
    to_block_style_yaml(msg.start_pose, out, indentation + 2);
  }

  // member: end_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "end_pose:\n";
    to_block_style_yaml(msg.end_pose, out, indentation + 2);
  }

  // member: gripperbase_to_armgearright
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gripperbase_to_armgearright: ";
    rosidl_generator_traits::value_to_yaml(msg.gripperbase_to_armgearright, out);
    out << "\n";
  }

  // member: max_step
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_step: ";
    rosidl_generator_traits::value_to_yaml(msg.max_step, out);
    out << "\n";
  }

  // member: jump_threshold
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "jump_threshold: ";
    rosidl_generator_traits::value_to_yaml(msg.jump_threshold, out);
    out << "\n";
  }

  // member: avoid_collisions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "avoid_collisions: ";
    rosidl_generator_traits::value_to_yaml(msg.avoid_collisions, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CartesianGoal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace thor_msgs

namespace rosidl_generator_traits
{

[[deprecated("use thor_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const thor_msgs::msg::CartesianGoal & msg,
  std::ostream & out, size_t indentation = 0)
{
  thor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use thor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const thor_msgs::msg::CartesianGoal & msg)
{
  return thor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<thor_msgs::msg::CartesianGoal>()
{
  return "thor_msgs::msg::CartesianGoal";
}

template<>
inline const char * name<thor_msgs::msg::CartesianGoal>()
{
  return "thor_msgs/msg/CartesianGoal";
}

template<>
struct has_fixed_size<thor_msgs::msg::CartesianGoal>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<thor_msgs::msg::CartesianGoal>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct is_message<thor_msgs::msg::CartesianGoal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // THOR_MSGS__MSG__DETAIL__CARTESIAN_GOAL__TRAITS_HPP_
