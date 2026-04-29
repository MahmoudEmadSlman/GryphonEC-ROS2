// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from thor_msgs:msg/IKGoal.idl
// generated code does not contain a copyright notice

#ifndef THOR_MSGS__MSG__DETAIL__IK_GOAL__STRUCT_H_
#define THOR_MSGS__MSG__DETAIL__IK_GOAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/IKGoal in the package thor_msgs.
typedef struct thor_msgs__msg__IKGoal
{
  geometry_msgs__msg__Pose pose;
  double gripperbase_to_armgearright;
} thor_msgs__msg__IKGoal;

// Struct for a sequence of thor_msgs__msg__IKGoal.
typedef struct thor_msgs__msg__IKGoal__Sequence
{
  thor_msgs__msg__IKGoal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} thor_msgs__msg__IKGoal__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // THOR_MSGS__MSG__DETAIL__IK_GOAL__STRUCT_H_
