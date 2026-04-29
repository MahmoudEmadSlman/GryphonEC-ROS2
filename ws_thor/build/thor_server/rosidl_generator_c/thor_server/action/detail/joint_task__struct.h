// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from thor_server:action/JointTask.idl
// generated code does not contain a copyright notice

#ifndef THOR_SERVER__ACTION__DETAIL__JOINT_TASK__STRUCT_H_
#define THOR_SERVER__ACTION__DETAIL__JOINT_TASK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/JointTask in the package thor_server.
typedef struct thor_server__action__JointTask_Goal
{
  float joint1_deg;
  float joint2_deg;
  float joint3_deg;
  float joint4_deg;
  float joint5_deg;
  float gripper_joint_deg;
} thor_server__action__JointTask_Goal;

// Struct for a sequence of thor_server__action__JointTask_Goal.
typedef struct thor_server__action__JointTask_Goal__Sequence
{
  thor_server__action__JointTask_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} thor_server__action__JointTask_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/JointTask in the package thor_server.
typedef struct thor_server__action__JointTask_Result
{
  bool success;
} thor_server__action__JointTask_Result;

// Struct for a sequence of thor_server__action__JointTask_Result.
typedef struct thor_server__action__JointTask_Result__Sequence
{
  thor_server__action__JointTask_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} thor_server__action__JointTask_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/JointTask in the package thor_server.
typedef struct thor_server__action__JointTask_Feedback
{
  int32_t percentage;
} thor_server__action__JointTask_Feedback;

// Struct for a sequence of thor_server__action__JointTask_Feedback.
typedef struct thor_server__action__JointTask_Feedback__Sequence
{
  thor_server__action__JointTask_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} thor_server__action__JointTask_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "thor_server/action/detail/joint_task__struct.h"

/// Struct defined in action/JointTask in the package thor_server.
typedef struct thor_server__action__JointTask_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  thor_server__action__JointTask_Goal goal;
} thor_server__action__JointTask_SendGoal_Request;

// Struct for a sequence of thor_server__action__JointTask_SendGoal_Request.
typedef struct thor_server__action__JointTask_SendGoal_Request__Sequence
{
  thor_server__action__JointTask_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} thor_server__action__JointTask_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/JointTask in the package thor_server.
typedef struct thor_server__action__JointTask_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} thor_server__action__JointTask_SendGoal_Response;

// Struct for a sequence of thor_server__action__JointTask_SendGoal_Response.
typedef struct thor_server__action__JointTask_SendGoal_Response__Sequence
{
  thor_server__action__JointTask_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} thor_server__action__JointTask_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/JointTask in the package thor_server.
typedef struct thor_server__action__JointTask_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} thor_server__action__JointTask_GetResult_Request;

// Struct for a sequence of thor_server__action__JointTask_GetResult_Request.
typedef struct thor_server__action__JointTask_GetResult_Request__Sequence
{
  thor_server__action__JointTask_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} thor_server__action__JointTask_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "thor_server/action/detail/joint_task__struct.h"

/// Struct defined in action/JointTask in the package thor_server.
typedef struct thor_server__action__JointTask_GetResult_Response
{
  int8_t status;
  thor_server__action__JointTask_Result result;
} thor_server__action__JointTask_GetResult_Response;

// Struct for a sequence of thor_server__action__JointTask_GetResult_Response.
typedef struct thor_server__action__JointTask_GetResult_Response__Sequence
{
  thor_server__action__JointTask_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} thor_server__action__JointTask_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "thor_server/action/detail/joint_task__struct.h"

/// Struct defined in action/JointTask in the package thor_server.
typedef struct thor_server__action__JointTask_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  thor_server__action__JointTask_Feedback feedback;
} thor_server__action__JointTask_FeedbackMessage;

// Struct for a sequence of thor_server__action__JointTask_FeedbackMessage.
typedef struct thor_server__action__JointTask_FeedbackMessage__Sequence
{
  thor_server__action__JointTask_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} thor_server__action__JointTask_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // THOR_SERVER__ACTION__DETAIL__JOINT_TASK__STRUCT_H_
