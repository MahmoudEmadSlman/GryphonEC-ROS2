// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from thor_msgs:msg/IKGoal.idl
// generated code does not contain a copyright notice

#ifndef THOR_MSGS__MSG__DETAIL__IK_GOAL__TRAITS_HPP_
#define THOR_MSGS__MSG__DETAIL__IK_GOAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "thor_msgs/msg/detail/ik_goal__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace thor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const IKGoal & msg,
  std::ostream & out)
{
  out << "{";
  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
    out << ", ";
  }

  // member: gripperbase_to_armgearright
  {
    out << "gripperbase_to_armgearright: ";
    rosidl_generator_traits::value_to_yaml(msg.gripperbase_to_armgearright, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const IKGoal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const IKGoal & msg, bool use_flow_style = false)
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
  const thor_msgs::msg::IKGoal & msg,
  std::ostream & out, size_t indentation = 0)
{
  thor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use thor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const thor_msgs::msg::IKGoal & msg)
{
  return thor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<thor_msgs::msg::IKGoal>()
{
  return "thor_msgs::msg::IKGoal";
}

template<>
inline const char * name<thor_msgs::msg::IKGoal>()
{
  return "thor_msgs/msg/IKGoal";
}

template<>
struct has_fixed_size<thor_msgs::msg::IKGoal>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<thor_msgs::msg::IKGoal>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct is_message<thor_msgs::msg::IKGoal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // THOR_MSGS__MSG__DETAIL__IK_GOAL__TRAITS_HPP_
