// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from thor_msgs:msg/IKGoal.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "thor_msgs/msg/detail/ik_goal__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace thor_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void IKGoal_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) thor_msgs::msg::IKGoal(_init);
}

void IKGoal_fini_function(void * message_memory)
{
  auto typed_message = static_cast<thor_msgs::msg::IKGoal *>(message_memory);
  typed_message->~IKGoal();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember IKGoal_message_member_array[2] = {
  {
    "pose",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Pose>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(thor_msgs::msg::IKGoal, pose),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "gripperbase_to_armgearright",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(thor_msgs::msg::IKGoal, gripperbase_to_armgearright),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers IKGoal_message_members = {
  "thor_msgs::msg",  // message namespace
  "IKGoal",  // message name
  2,  // number of fields
  sizeof(thor_msgs::msg::IKGoal),
  IKGoal_message_member_array,  // message members
  IKGoal_init_function,  // function to initialize message memory (memory has to be allocated)
  IKGoal_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t IKGoal_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &IKGoal_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace thor_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<thor_msgs::msg::IKGoal>()
{
  return &::thor_msgs::msg::rosidl_typesupport_introspection_cpp::IKGoal_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, thor_msgs, msg, IKGoal)() {
  return &::thor_msgs::msg::rosidl_typesupport_introspection_cpp::IKGoal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
