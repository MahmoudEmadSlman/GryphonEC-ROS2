// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from thor_server:action/PoseTask.idl
// generated code does not contain a copyright notice

#ifndef THOR_SERVER__ACTION__DETAIL__POSE_TASK__STRUCT_H_
#define THOR_SERVER__ACTION__DETAIL__POSE_TASK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/PoseTask in the package thor_server.
typedef struct thor_server__action__PoseTask_Goal
{
  float x;
  float y;
  float z;
  float roll;
  float pitch;
  float yaw;
} thor_server__action__PoseTask_Goal;

// Struct for a sequence of thor_server__action__PoseTask_Goal.
typedef struct thor_server__action__PoseTask_Goal__Sequence
{
  thor_server__action__PoseTask_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} thor_server__action__PoseTask_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/PoseTask in the package thor_server.
typedef struct thor_server__action__PoseTask_Result
{
  bool success;
} thor_server__action__PoseTask_Result;

// Struct for a sequence of thor_server__action__PoseTask_Result.
typedef struct thor_server__action__PoseTask_Result__Sequence
{
  thor_server__action__PoseTask_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} thor_server__action__PoseTask_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/PoseTask in the package thor_server.
typedef struct thor_server__action__PoseTask_Feedback
{
  int32_t percentage;
} thor_server__action__PoseTask_Feedback;

// Struct for a sequence of thor_server__action__PoseTask_Feedback.
typedef struct thor_server__action__PoseTask_Feedback__Sequence
{
  thor_server__action__PoseTask_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} thor_server__action__PoseTask_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "thor_server/action/detail/pose_task__struct.h"

/// Struct defined in action/PoseTask in the package thor_server.
typedef struct thor_server__action__PoseTask_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  thor_server__action__PoseTask_Goal goal;
} thor_server__action__PoseTask_SendGoal_Request;

// Struct for a sequence of thor_server__action__PoseTask_SendGoal_Request.
typedef struct thor_server__action__PoseTask_SendGoal_Request__Sequence
{
  thor_server__action__PoseTask_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} thor_server__action__PoseTask_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/PoseTask in the package thor_server.
typedef struct thor_server__action__PoseTask_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} thor_server__action__PoseTask_SendGoal_Response;

// Struct for a sequence of thor_server__action__PoseTask_SendGoal_Response.
typedef struct thor_server__action__PoseTask_SendGoal_Response__Sequence
{
  thor_server__action__PoseTask_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} thor_server__action__PoseTask_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/PoseTask in the package thor_server.
typedef struct thor_server__action__PoseTask_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} thor_server__action__PoseTask_GetResult_Request;

// Struct for a sequence of thor_server__action__PoseTask_GetResult_Request.
typedef struct thor_server__action__PoseTask_GetResult_Request__Sequence
{
  thor_server__action__PoseTask_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} thor_server__action__PoseTask_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "thor_server/action/detail/pose_task__struct.h"

/// Struct defined in action/PoseTask in the package thor_server.
typedef struct thor_server__action__PoseTask_GetResult_Response
{
  int8_t status;
  thor_server__action__PoseTask_Result result;
} thor_server__action__PoseTask_GetResult_Response;

// Struct for a sequence of thor_server__action__PoseTask_GetResult_Response.
typedef struct thor_server__action__PoseTask_GetResult_Response__Sequence
{
  thor_server__action__PoseTask_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} thor_server__action__PoseTask_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "thor_server/action/detail/pose_task__struct.h"

/// Struct defined in action/PoseTask in the package thor_server.
typedef struct thor_server__action__PoseTask_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  thor_server__action__PoseTask_Feedback feedback;
} thor_server__action__PoseTask_FeedbackMessage;

// Struct for a sequence of thor_server__action__PoseTask_FeedbackMessage.
typedef struct thor_server__action__PoseTask_FeedbackMessage__Sequence
{
  thor_server__action__PoseTask_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} thor_server__action__PoseTask_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // THOR_SERVER__ACTION__DETAIL__POSE_TASK__STRUCT_H_
