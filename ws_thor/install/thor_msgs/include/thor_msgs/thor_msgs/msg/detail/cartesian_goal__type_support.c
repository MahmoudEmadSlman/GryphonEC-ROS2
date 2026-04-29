// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from thor_msgs:msg/CartesianGoal.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "thor_msgs/msg/detail/cartesian_goal__rosidl_typesupport_introspection_c.h"
#include "thor_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "thor_msgs/msg/detail/cartesian_goal__functions.h"
#include "thor_msgs/msg/detail/cartesian_goal__struct.h"


// Include directives for member types
// Member `start_pose`
// Member `end_pose`
#include "geometry_msgs/msg/pose.h"
// Member `start_pose`
// Member `end_pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void thor_msgs__msg__CartesianGoal__rosidl_typesupport_introspection_c__CartesianGoal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  thor_msgs__msg__CartesianGoal__init(message_memory);
}

void thor_msgs__msg__CartesianGoal__rosidl_typesupport_introspection_c__CartesianGoal_fini_function(void * message_memory)
{
  thor_msgs__msg__CartesianGoal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember thor_msgs__msg__CartesianGoal__rosidl_typesupport_introspection_c__CartesianGoal_message_member_array[6] = {
  {
    "start_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(thor_msgs__msg__CartesianGoal, start_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "end_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(thor_msgs__msg__CartesianGoal, end_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gripperbase_to_armgearright",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(thor_msgs__msg__CartesianGoal, gripperbase_to_armgearright),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "max_step",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(thor_msgs__msg__CartesianGoal, max_step),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "jump_threshold",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(thor_msgs__msg__CartesianGoal, jump_threshold),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "avoid_collisions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(thor_msgs__msg__CartesianGoal, avoid_collisions),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers thor_msgs__msg__CartesianGoal__rosidl_typesupport_introspection_c__CartesianGoal_message_members = {
  "thor_msgs__msg",  // message namespace
  "CartesianGoal",  // message name
  6,  // number of fields
  sizeof(thor_msgs__msg__CartesianGoal),
  thor_msgs__msg__CartesianGoal__rosidl_typesupport_introspection_c__CartesianGoal_message_member_array,  // message members
  thor_msgs__msg__CartesianGoal__rosidl_typesupport_introspection_c__CartesianGoal_init_function,  // function to initialize message memory (memory has to be allocated)
  thor_msgs__msg__CartesianGoal__rosidl_typesupport_introspection_c__CartesianGoal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t thor_msgs__msg__CartesianGoal__rosidl_typesupport_introspection_c__CartesianGoal_message_type_support_handle = {
  0,
  &thor_msgs__msg__CartesianGoal__rosidl_typesupport_introspection_c__CartesianGoal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_thor_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, thor_msgs, msg, CartesianGoal)() {
  thor_msgs__msg__CartesianGoal__rosidl_typesupport_introspection_c__CartesianGoal_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  thor_msgs__msg__CartesianGoal__rosidl_typesupport_introspection_c__CartesianGoal_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!thor_msgs__msg__CartesianGoal__rosidl_typesupport_introspection_c__CartesianGoal_message_type_support_handle.typesupport_identifier) {
    thor_msgs__msg__CartesianGoal__rosidl_typesupport_introspection_c__CartesianGoal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &thor_msgs__msg__CartesianGoal__rosidl_typesupport_introspection_c__CartesianGoal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
