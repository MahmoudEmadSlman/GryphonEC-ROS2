// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from thor_msgs:msg/IKGoal.idl
// generated code does not contain a copyright notice

#ifndef THOR_MSGS__MSG__DETAIL__IK_GOAL__FUNCTIONS_H_
#define THOR_MSGS__MSG__DETAIL__IK_GOAL__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "thor_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "thor_msgs/msg/detail/ik_goal__struct.h"

/// Initialize msg/IKGoal message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * thor_msgs__msg__IKGoal
 * )) before or use
 * thor_msgs__msg__IKGoal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
bool
thor_msgs__msg__IKGoal__init(thor_msgs__msg__IKGoal * msg);

/// Finalize msg/IKGoal message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
void
thor_msgs__msg__IKGoal__fini(thor_msgs__msg__IKGoal * msg);

/// Create msg/IKGoal message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * thor_msgs__msg__IKGoal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
thor_msgs__msg__IKGoal *
thor_msgs__msg__IKGoal__create();

/// Destroy msg/IKGoal message.
/**
 * It calls
 * thor_msgs__msg__IKGoal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
void
thor_msgs__msg__IKGoal__destroy(thor_msgs__msg__IKGoal * msg);

/// Check for msg/IKGoal message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
bool
thor_msgs__msg__IKGoal__are_equal(const thor_msgs__msg__IKGoal * lhs, const thor_msgs__msg__IKGoal * rhs);

/// Copy a msg/IKGoal message.
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
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
bool
thor_msgs__msg__IKGoal__copy(
  const thor_msgs__msg__IKGoal * input,
  thor_msgs__msg__IKGoal * output);

/// Initialize array of msg/IKGoal messages.
/**
 * It allocates the memory for the number of elements and calls
 * thor_msgs__msg__IKGoal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
bool
thor_msgs__msg__IKGoal__Sequence__init(thor_msgs__msg__IKGoal__Sequence * array, size_t size);

/// Finalize array of msg/IKGoal messages.
/**
 * It calls
 * thor_msgs__msg__IKGoal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
void
thor_msgs__msg__IKGoal__Sequence__fini(thor_msgs__msg__IKGoal__Sequence * array);

/// Create array of msg/IKGoal messages.
/**
 * It allocates the memory for the array and calls
 * thor_msgs__msg__IKGoal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
thor_msgs__msg__IKGoal__Sequence *
thor_msgs__msg__IKGoal__Sequence__create(size_t size);

/// Destroy array of msg/IKGoal messages.
/**
 * It calls
 * thor_msgs__msg__IKGoal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
void
thor_msgs__msg__IKGoal__Sequence__destroy(thor_msgs__msg__IKGoal__Sequence * array);

/// Check for msg/IKGoal message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
bool
thor_msgs__msg__IKGoal__Sequence__are_equal(const thor_msgs__msg__IKGoal__Sequence * lhs, const thor_msgs__msg__IKGoal__Sequence * rhs);

/// Copy an array of msg/IKGoal messages.
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
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
bool
thor_msgs__msg__IKGoal__Sequence__copy(
  const thor_msgs__msg__IKGoal__Sequence * input,
  thor_msgs__msg__IKGoal__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // THOR_MSGS__MSG__DETAIL__IK_GOAL__FUNCTIONS_H_
