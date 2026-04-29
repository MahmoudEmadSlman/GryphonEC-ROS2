// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from thor_server:action/PoseTask.idl
// generated code does not contain a copyright notice

#ifndef THOR_SERVER__ACTION__DETAIL__POSE_TASK__FUNCTIONS_H_
#define THOR_SERVER__ACTION__DETAIL__POSE_TASK__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "thor_server/msg/rosidl_generator_c__visibility_control.h"

#include "thor_server/action/detail/pose_task__struct.h"

/// Initialize action/PoseTask message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * thor_server__action__PoseTask_Goal
 * )) before or use
 * thor_server__action__PoseTask_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_Goal__init(thor_server__action__PoseTask_Goal * msg);

/// Finalize action/PoseTask message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_Goal__fini(thor_server__action__PoseTask_Goal * msg);

/// Create action/PoseTask message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * thor_server__action__PoseTask_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
thor_server__action__PoseTask_Goal *
thor_server__action__PoseTask_Goal__create();

/// Destroy action/PoseTask message.
/**
 * It calls
 * thor_server__action__PoseTask_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_Goal__destroy(thor_server__action__PoseTask_Goal * msg);

/// Check for action/PoseTask message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_Goal__are_equal(const thor_server__action__PoseTask_Goal * lhs, const thor_server__action__PoseTask_Goal * rhs);

/// Copy a action/PoseTask message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_Goal__copy(
  const thor_server__action__PoseTask_Goal * input,
  thor_server__action__PoseTask_Goal * output);

/// Initialize array of action/PoseTask messages.
/**
 * It allocates the memory for the number of elements and calls
 * thor_server__action__PoseTask_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_Goal__Sequence__init(thor_server__action__PoseTask_Goal__Sequence * array, size_t size);

/// Finalize array of action/PoseTask messages.
/**
 * It calls
 * thor_server__action__PoseTask_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_Goal__Sequence__fini(thor_server__action__PoseTask_Goal__Sequence * array);

/// Create array of action/PoseTask messages.
/**
 * It allocates the memory for the array and calls
 * thor_server__action__PoseTask_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
thor_server__action__PoseTask_Goal__Sequence *
thor_server__action__PoseTask_Goal__Sequence__create(size_t size);

/// Destroy array of action/PoseTask messages.
/**
 * It calls
 * thor_server__action__PoseTask_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_Goal__Sequence__destroy(thor_server__action__PoseTask_Goal__Sequence * array);

/// Check for action/PoseTask message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_Goal__Sequence__are_equal(const thor_server__action__PoseTask_Goal__Sequence * lhs, const thor_server__action__PoseTask_Goal__Sequence * rhs);

/// Copy an array of action/PoseTask messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_Goal__Sequence__copy(
  const thor_server__action__PoseTask_Goal__Sequence * input,
  thor_server__action__PoseTask_Goal__Sequence * output);

/// Initialize action/PoseTask message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * thor_server__action__PoseTask_Result
 * )) before or use
 * thor_server__action__PoseTask_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_Result__init(thor_server__action__PoseTask_Result * msg);

/// Finalize action/PoseTask message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_Result__fini(thor_server__action__PoseTask_Result * msg);

/// Create action/PoseTask message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * thor_server__action__PoseTask_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
thor_server__action__PoseTask_Result *
thor_server__action__PoseTask_Result__create();

/// Destroy action/PoseTask message.
/**
 * It calls
 * thor_server__action__PoseTask_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_Result__destroy(thor_server__action__PoseTask_Result * msg);

/// Check for action/PoseTask message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_Result__are_equal(const thor_server__action__PoseTask_Result * lhs, const thor_server__action__PoseTask_Result * rhs);

/// Copy a action/PoseTask message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_Result__copy(
  const thor_server__action__PoseTask_Result * input,
  thor_server__action__PoseTask_Result * output);

/// Initialize array of action/PoseTask messages.
/**
 * It allocates the memory for the number of elements and calls
 * thor_server__action__PoseTask_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_Result__Sequence__init(thor_server__action__PoseTask_Result__Sequence * array, size_t size);

/// Finalize array of action/PoseTask messages.
/**
 * It calls
 * thor_server__action__PoseTask_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_Result__Sequence__fini(thor_server__action__PoseTask_Result__Sequence * array);

/// Create array of action/PoseTask messages.
/**
 * It allocates the memory for the array and calls
 * thor_server__action__PoseTask_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
thor_server__action__PoseTask_Result__Sequence *
thor_server__action__PoseTask_Result__Sequence__create(size_t size);

/// Destroy array of action/PoseTask messages.
/**
 * It calls
 * thor_server__action__PoseTask_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_Result__Sequence__destroy(thor_server__action__PoseTask_Result__Sequence * array);

/// Check for action/PoseTask message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_Result__Sequence__are_equal(const thor_server__action__PoseTask_Result__Sequence * lhs, const thor_server__action__PoseTask_Result__Sequence * rhs);

/// Copy an array of action/PoseTask messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_Result__Sequence__copy(
  const thor_server__action__PoseTask_Result__Sequence * input,
  thor_server__action__PoseTask_Result__Sequence * output);

/// Initialize action/PoseTask message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * thor_server__action__PoseTask_Feedback
 * )) before or use
 * thor_server__action__PoseTask_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_Feedback__init(thor_server__action__PoseTask_Feedback * msg);

/// Finalize action/PoseTask message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_Feedback__fini(thor_server__action__PoseTask_Feedback * msg);

/// Create action/PoseTask message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * thor_server__action__PoseTask_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
thor_server__action__PoseTask_Feedback *
thor_server__action__PoseTask_Feedback__create();

/// Destroy action/PoseTask message.
/**
 * It calls
 * thor_server__action__PoseTask_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_Feedback__destroy(thor_server__action__PoseTask_Feedback * msg);

/// Check for action/PoseTask message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_Feedback__are_equal(const thor_server__action__PoseTask_Feedback * lhs, const thor_server__action__PoseTask_Feedback * rhs);

/// Copy a action/PoseTask message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_Feedback__copy(
  const thor_server__action__PoseTask_Feedback * input,
  thor_server__action__PoseTask_Feedback * output);

/// Initialize array of action/PoseTask messages.
/**
 * It allocates the memory for the number of elements and calls
 * thor_server__action__PoseTask_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_Feedback__Sequence__init(thor_server__action__PoseTask_Feedback__Sequence * array, size_t size);

/// Finalize array of action/PoseTask messages.
/**
 * It calls
 * thor_server__action__PoseTask_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_Feedback__Sequence__fini(thor_server__action__PoseTask_Feedback__Sequence * array);

/// Create array of action/PoseTask messages.
/**
 * It allocates the memory for the array and calls
 * thor_server__action__PoseTask_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
thor_server__action__PoseTask_Feedback__Sequence *
thor_server__action__PoseTask_Feedback__Sequence__create(size_t size);

/// Destroy array of action/PoseTask messages.
/**
 * It calls
 * thor_server__action__PoseTask_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_Feedback__Sequence__destroy(thor_server__action__PoseTask_Feedback__Sequence * array);

/// Check for action/PoseTask message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_Feedback__Sequence__are_equal(const thor_server__action__PoseTask_Feedback__Sequence * lhs, const thor_server__action__PoseTask_Feedback__Sequence * rhs);

/// Copy an array of action/PoseTask messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_Feedback__Sequence__copy(
  const thor_server__action__PoseTask_Feedback__Sequence * input,
  thor_server__action__PoseTask_Feedback__Sequence * output);

/// Initialize action/PoseTask message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * thor_server__action__PoseTask_SendGoal_Request
 * )) before or use
 * thor_server__action__PoseTask_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_SendGoal_Request__init(thor_server__action__PoseTask_SendGoal_Request * msg);

/// Finalize action/PoseTask message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_SendGoal_Request__fini(thor_server__action__PoseTask_SendGoal_Request * msg);

/// Create action/PoseTask message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * thor_server__action__PoseTask_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
thor_server__action__PoseTask_SendGoal_Request *
thor_server__action__PoseTask_SendGoal_Request__create();

/// Destroy action/PoseTask message.
/**
 * It calls
 * thor_server__action__PoseTask_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_SendGoal_Request__destroy(thor_server__action__PoseTask_SendGoal_Request * msg);

/// Check for action/PoseTask message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_SendGoal_Request__are_equal(const thor_server__action__PoseTask_SendGoal_Request * lhs, const thor_server__action__PoseTask_SendGoal_Request * rhs);

/// Copy a action/PoseTask message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_SendGoal_Request__copy(
  const thor_server__action__PoseTask_SendGoal_Request * input,
  thor_server__action__PoseTask_SendGoal_Request * output);

/// Initialize array of action/PoseTask messages.
/**
 * It allocates the memory for the number of elements and calls
 * thor_server__action__PoseTask_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_SendGoal_Request__Sequence__init(thor_server__action__PoseTask_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/PoseTask messages.
/**
 * It calls
 * thor_server__action__PoseTask_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_SendGoal_Request__Sequence__fini(thor_server__action__PoseTask_SendGoal_Request__Sequence * array);

/// Create array of action/PoseTask messages.
/**
 * It allocates the memory for the array and calls
 * thor_server__action__PoseTask_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
thor_server__action__PoseTask_SendGoal_Request__Sequence *
thor_server__action__PoseTask_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/PoseTask messages.
/**
 * It calls
 * thor_server__action__PoseTask_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_SendGoal_Request__Sequence__destroy(thor_server__action__PoseTask_SendGoal_Request__Sequence * array);

/// Check for action/PoseTask message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_SendGoal_Request__Sequence__are_equal(const thor_server__action__PoseTask_SendGoal_Request__Sequence * lhs, const thor_server__action__PoseTask_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/PoseTask messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_SendGoal_Request__Sequence__copy(
  const thor_server__action__PoseTask_SendGoal_Request__Sequence * input,
  thor_server__action__PoseTask_SendGoal_Request__Sequence * output);

/// Initialize action/PoseTask message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * thor_server__action__PoseTask_SendGoal_Response
 * )) before or use
 * thor_server__action__PoseTask_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_SendGoal_Response__init(thor_server__action__PoseTask_SendGoal_Response * msg);

/// Finalize action/PoseTask message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_SendGoal_Response__fini(thor_server__action__PoseTask_SendGoal_Response * msg);

/// Create action/PoseTask message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * thor_server__action__PoseTask_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
thor_server__action__PoseTask_SendGoal_Response *
thor_server__action__PoseTask_SendGoal_Response__create();

/// Destroy action/PoseTask message.
/**
 * It calls
 * thor_server__action__PoseTask_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_SendGoal_Response__destroy(thor_server__action__PoseTask_SendGoal_Response * msg);

/// Check for action/PoseTask message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_SendGoal_Response__are_equal(const thor_server__action__PoseTask_SendGoal_Response * lhs, const thor_server__action__PoseTask_SendGoal_Response * rhs);

/// Copy a action/PoseTask message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_SendGoal_Response__copy(
  const thor_server__action__PoseTask_SendGoal_Response * input,
  thor_server__action__PoseTask_SendGoal_Response * output);

/// Initialize array of action/PoseTask messages.
/**
 * It allocates the memory for the number of elements and calls
 * thor_server__action__PoseTask_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_SendGoal_Response__Sequence__init(thor_server__action__PoseTask_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/PoseTask messages.
/**
 * It calls
 * thor_server__action__PoseTask_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_SendGoal_Response__Sequence__fini(thor_server__action__PoseTask_SendGoal_Response__Sequence * array);

/// Create array of action/PoseTask messages.
/**
 * It allocates the memory for the array and calls
 * thor_server__action__PoseTask_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
thor_server__action__PoseTask_SendGoal_Response__Sequence *
thor_server__action__PoseTask_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/PoseTask messages.
/**
 * It calls
 * thor_server__action__PoseTask_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_SendGoal_Response__Sequence__destroy(thor_server__action__PoseTask_SendGoal_Response__Sequence * array);

/// Check for action/PoseTask message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_SendGoal_Response__Sequence__are_equal(const thor_server__action__PoseTask_SendGoal_Response__Sequence * lhs, const thor_server__action__PoseTask_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/PoseTask messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_SendGoal_Response__Sequence__copy(
  const thor_server__action__PoseTask_SendGoal_Response__Sequence * input,
  thor_server__action__PoseTask_SendGoal_Response__Sequence * output);

/// Initialize action/PoseTask message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * thor_server__action__PoseTask_GetResult_Request
 * )) before or use
 * thor_server__action__PoseTask_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_GetResult_Request__init(thor_server__action__PoseTask_GetResult_Request * msg);

/// Finalize action/PoseTask message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_GetResult_Request__fini(thor_server__action__PoseTask_GetResult_Request * msg);

/// Create action/PoseTask message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * thor_server__action__PoseTask_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
thor_server__action__PoseTask_GetResult_Request *
thor_server__action__PoseTask_GetResult_Request__create();

/// Destroy action/PoseTask message.
/**
 * It calls
 * thor_server__action__PoseTask_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_GetResult_Request__destroy(thor_server__action__PoseTask_GetResult_Request * msg);

/// Check for action/PoseTask message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_GetResult_Request__are_equal(const thor_server__action__PoseTask_GetResult_Request * lhs, const thor_server__action__PoseTask_GetResult_Request * rhs);

/// Copy a action/PoseTask message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_GetResult_Request__copy(
  const thor_server__action__PoseTask_GetResult_Request * input,
  thor_server__action__PoseTask_GetResult_Request * output);

/// Initialize array of action/PoseTask messages.
/**
 * It allocates the memory for the number of elements and calls
 * thor_server__action__PoseTask_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_GetResult_Request__Sequence__init(thor_server__action__PoseTask_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/PoseTask messages.
/**
 * It calls
 * thor_server__action__PoseTask_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_GetResult_Request__Sequence__fini(thor_server__action__PoseTask_GetResult_Request__Sequence * array);

/// Create array of action/PoseTask messages.
/**
 * It allocates the memory for the array and calls
 * thor_server__action__PoseTask_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
thor_server__action__PoseTask_GetResult_Request__Sequence *
thor_server__action__PoseTask_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/PoseTask messages.
/**
 * It calls
 * thor_server__action__PoseTask_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_GetResult_Request__Sequence__destroy(thor_server__action__PoseTask_GetResult_Request__Sequence * array);

/// Check for action/PoseTask message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_GetResult_Request__Sequence__are_equal(const thor_server__action__PoseTask_GetResult_Request__Sequence * lhs, const thor_server__action__PoseTask_GetResult_Request__Sequence * rhs);

/// Copy an array of action/PoseTask messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_GetResult_Request__Sequence__copy(
  const thor_server__action__PoseTask_GetResult_Request__Sequence * input,
  thor_server__action__PoseTask_GetResult_Request__Sequence * output);

/// Initialize action/PoseTask message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * thor_server__action__PoseTask_GetResult_Response
 * )) before or use
 * thor_server__action__PoseTask_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_GetResult_Response__init(thor_server__action__PoseTask_GetResult_Response * msg);

/// Finalize action/PoseTask message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_GetResult_Response__fini(thor_server__action__PoseTask_GetResult_Response * msg);

/// Create action/PoseTask message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * thor_server__action__PoseTask_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
thor_server__action__PoseTask_GetResult_Response *
thor_server__action__PoseTask_GetResult_Response__create();

/// Destroy action/PoseTask message.
/**
 * It calls
 * thor_server__action__PoseTask_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_GetResult_Response__destroy(thor_server__action__PoseTask_GetResult_Response * msg);

/// Check for action/PoseTask message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_GetResult_Response__are_equal(const thor_server__action__PoseTask_GetResult_Response * lhs, const thor_server__action__PoseTask_GetResult_Response * rhs);

/// Copy a action/PoseTask message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_GetResult_Response__copy(
  const thor_server__action__PoseTask_GetResult_Response * input,
  thor_server__action__PoseTask_GetResult_Response * output);

/// Initialize array of action/PoseTask messages.
/**
 * It allocates the memory for the number of elements and calls
 * thor_server__action__PoseTask_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_GetResult_Response__Sequence__init(thor_server__action__PoseTask_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/PoseTask messages.
/**
 * It calls
 * thor_server__action__PoseTask_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_GetResult_Response__Sequence__fini(thor_server__action__PoseTask_GetResult_Response__Sequence * array);

/// Create array of action/PoseTask messages.
/**
 * It allocates the memory for the array and calls
 * thor_server__action__PoseTask_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
thor_server__action__PoseTask_GetResult_Response__Sequence *
thor_server__action__PoseTask_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/PoseTask messages.
/**
 * It calls
 * thor_server__action__PoseTask_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_GetResult_Response__Sequence__destroy(thor_server__action__PoseTask_GetResult_Response__Sequence * array);

/// Check for action/PoseTask message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_GetResult_Response__Sequence__are_equal(const thor_server__action__PoseTask_GetResult_Response__Sequence * lhs, const thor_server__action__PoseTask_GetResult_Response__Sequence * rhs);

/// Copy an array of action/PoseTask messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_GetResult_Response__Sequence__copy(
  const thor_server__action__PoseTask_GetResult_Response__Sequence * input,
  thor_server__action__PoseTask_GetResult_Response__Sequence * output);

/// Initialize action/PoseTask message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * thor_server__action__PoseTask_FeedbackMessage
 * )) before or use
 * thor_server__action__PoseTask_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_FeedbackMessage__init(thor_server__action__PoseTask_FeedbackMessage * msg);

/// Finalize action/PoseTask message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_FeedbackMessage__fini(thor_server__action__PoseTask_FeedbackMessage * msg);

/// Create action/PoseTask message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * thor_server__action__PoseTask_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
thor_server__action__PoseTask_FeedbackMessage *
thor_server__action__PoseTask_FeedbackMessage__create();

/// Destroy action/PoseTask message.
/**
 * It calls
 * thor_server__action__PoseTask_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_FeedbackMessage__destroy(thor_server__action__PoseTask_FeedbackMessage * msg);

/// Check for action/PoseTask message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_FeedbackMessage__are_equal(const thor_server__action__PoseTask_FeedbackMessage * lhs, const thor_server__action__PoseTask_FeedbackMessage * rhs);

/// Copy a action/PoseTask message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_FeedbackMessage__copy(
  const thor_server__action__PoseTask_FeedbackMessage * input,
  thor_server__action__PoseTask_FeedbackMessage * output);

/// Initialize array of action/PoseTask messages.
/**
 * It allocates the memory for the number of elements and calls
 * thor_server__action__PoseTask_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_FeedbackMessage__Sequence__init(thor_server__action__PoseTask_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/PoseTask messages.
/**
 * It calls
 * thor_server__action__PoseTask_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_FeedbackMessage__Sequence__fini(thor_server__action__PoseTask_FeedbackMessage__Sequence * array);

/// Create array of action/PoseTask messages.
/**
 * It allocates the memory for the array and calls
 * thor_server__action__PoseTask_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
thor_server__action__PoseTask_FeedbackMessage__Sequence *
thor_server__action__PoseTask_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/PoseTask messages.
/**
 * It calls
 * thor_server__action__PoseTask_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
void
thor_server__action__PoseTask_FeedbackMessage__Sequence__destroy(thor_server__action__PoseTask_FeedbackMessage__Sequence * array);

/// Check for action/PoseTask message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_FeedbackMessage__Sequence__are_equal(const thor_server__action__PoseTask_FeedbackMessage__Sequence * lhs, const thor_server__action__PoseTask_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/PoseTask messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_server
bool
thor_server__action__PoseTask_FeedbackMessage__Sequence__copy(
  const thor_server__action__PoseTask_FeedbackMessage__Sequence * input,
  thor_server__action__PoseTask_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // THOR_SERVER__ACTION__DETAIL__POSE_TASK__FUNCTIONS_H_
