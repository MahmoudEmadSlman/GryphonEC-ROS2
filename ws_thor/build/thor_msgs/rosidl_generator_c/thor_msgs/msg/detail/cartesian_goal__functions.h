// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from thor_msgs:msg/CartesianGoal.idl
// generated code does not contain a copyright notice

#ifndef THOR_MSGS__MSG__DETAIL__CARTESIAN_GOAL__FUNCTIONS_H_
#define THOR_MSGS__MSG__DETAIL__CARTESIAN_GOAL__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "thor_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "thor_msgs/msg/detail/cartesian_goal__struct.h"

/// Initialize msg/CartesianGoal message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * thor_msgs__msg__CartesianGoal
 * )) before or use
 * thor_msgs__msg__CartesianGoal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
bool
thor_msgs__msg__CartesianGoal__init(thor_msgs__msg__CartesianGoal * msg);

/// Finalize msg/CartesianGoal message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
void
thor_msgs__msg__CartesianGoal__fini(thor_msgs__msg__CartesianGoal * msg);

/// Create msg/CartesianGoal message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * thor_msgs__msg__CartesianGoal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
thor_msgs__msg__CartesianGoal *
thor_msgs__msg__CartesianGoal__create();

/// Destroy msg/CartesianGoal message.
/**
 * It calls
 * thor_msgs__msg__CartesianGoal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
void
thor_msgs__msg__CartesianGoal__destroy(thor_msgs__msg__CartesianGoal * msg);

/// Check for msg/CartesianGoal message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
bool
thor_msgs__msg__CartesianGoal__are_equal(const thor_msgs__msg__CartesianGoal * lhs, const thor_msgs__msg__CartesianGoal * rhs);

/// Copy a msg/CartesianGoal message.
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
thor_msgs__msg__CartesianGoal__copy(
  const thor_msgs__msg__CartesianGoal * input,
  thor_msgs__msg__CartesianGoal * output);

/// Initialize array of msg/CartesianGoal messages.
/**
 * It allocates the memory for the number of elements and calls
 * thor_msgs__msg__CartesianGoal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
bool
thor_msgs__msg__CartesianGoal__Sequence__init(thor_msgs__msg__CartesianGoal__Sequence * array, size_t size);

/// Finalize array of msg/CartesianGoal messages.
/**
 * It calls
 * thor_msgs__msg__CartesianGoal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
void
thor_msgs__msg__CartesianGoal__Sequence__fini(thor_msgs__msg__CartesianGoal__Sequence * array);

/// Create array of msg/CartesianGoal messages.
/**
 * It allocates the memory for the array and calls
 * thor_msgs__msg__CartesianGoal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
thor_msgs__msg__CartesianGoal__Sequence *
thor_msgs__msg__CartesianGoal__Sequence__create(size_t size);

/// Destroy array of msg/CartesianGoal messages.
/**
 * It calls
 * thor_msgs__msg__CartesianGoal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
void
thor_msgs__msg__CartesianGoal__Sequence__destroy(thor_msgs__msg__CartesianGoal__Sequence * array);

/// Check for msg/CartesianGoal message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_thor_msgs
bool
thor_msgs__msg__CartesianGoal__Sequence__are_equal(const thor_msgs__msg__CartesianGoal__Sequence * lhs, const thor_msgs__msg__CartesianGoal__Sequence * rhs);

/// Copy an array of msg/CartesianGoal messages.
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
thor_msgs__msg__CartesianGoal__Sequence__copy(
  const thor_msgs__msg__CartesianGoal__Sequence * input,
  thor_msgs__msg__CartesianGoal__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // THOR_MSGS__MSG__DETAIL__CARTESIAN_GOAL__FUNCTIONS_H_
