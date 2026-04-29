// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from thor_msgs:msg/CartesianGoal.idl
// generated code does not contain a copyright notice

#ifndef THOR_MSGS__MSG__DETAIL__CARTESIAN_GOAL__STRUCT_H_
#define THOR_MSGS__MSG__DETAIL__CARTESIAN_GOAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'start_pose'
// Member 'end_pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/CartesianGoal in the package thor_msgs.
typedef struct thor_msgs__msg__CartesianGoal
{
  geometry_msgs__msg__Pose start_pose;
  geometry_msgs__msg__Pose end_pose;
  double gripperbase_to_armgearright;
  double max_step;
  double jump_threshold;
  bool avoid_collisions;
} thor_msgs__msg__CartesianGoal;

// Struct for a sequence of thor_msgs__msg__CartesianGoal.
typedef struct thor_msgs__msg__CartesianGoal__Sequence
{
  thor_msgs__msg__CartesianGoal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} thor_msgs__msg__CartesianGoal__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // THOR_MSGS__MSG__DETAIL__CARTESIAN_GOAL__STRUCT_H_
