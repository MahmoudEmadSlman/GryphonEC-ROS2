// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from thor_msgs:msg/CartesianGoal.idl
// generated code does not contain a copyright notice
#include "thor_msgs/msg/detail/cartesian_goal__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `start_pose`
// Member `end_pose`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
thor_msgs__msg__CartesianGoal__init(thor_msgs__msg__CartesianGoal * msg)
{
  if (!msg) {
    return false;
  }
  // start_pose
  if (!geometry_msgs__msg__Pose__init(&msg->start_pose)) {
    thor_msgs__msg__CartesianGoal__fini(msg);
    return false;
  }
  // end_pose
  if (!geometry_msgs__msg__Pose__init(&msg->end_pose)) {
    thor_msgs__msg__CartesianGoal__fini(msg);
    return false;
  }
  // gripperbase_to_armgearright
  // max_step
  // jump_threshold
  // avoid_collisions
  return true;
}

void
thor_msgs__msg__CartesianGoal__fini(thor_msgs__msg__CartesianGoal * msg)
{
  if (!msg) {
    return;
  }
  // start_pose
  geometry_msgs__msg__Pose__fini(&msg->start_pose);
  // end_pose
  geometry_msgs__msg__Pose__fini(&msg->end_pose);
  // gripperbase_to_armgearright
  // max_step
  // jump_threshold
  // avoid_collisions
}

bool
thor_msgs__msg__CartesianGoal__are_equal(const thor_msgs__msg__CartesianGoal * lhs, const thor_msgs__msg__CartesianGoal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // start_pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->start_pose), &(rhs->start_pose)))
  {
    return false;
  }
  // end_pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->end_pose), &(rhs->end_pose)))
  {
    return false;
  }
  // gripperbase_to_armgearright
  if (lhs->gripperbase_to_armgearright != rhs->gripperbase_to_armgearright) {
    return false;
  }
  // max_step
  if (lhs->max_step != rhs->max_step) {
    return false;
  }
  // jump_threshold
  if (lhs->jump_threshold != rhs->jump_threshold) {
    return false;
  }
  // avoid_collisions
  if (lhs->avoid_collisions != rhs->avoid_collisions) {
    return false;
  }
  return true;
}

bool
thor_msgs__msg__CartesianGoal__copy(
  const thor_msgs__msg__CartesianGoal * input,
  thor_msgs__msg__CartesianGoal * output)
{
  if (!input || !output) {
    return false;
  }
  // start_pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->start_pose), &(output->start_pose)))
  {
    return false;
  }
  // end_pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->end_pose), &(output->end_pose)))
  {
    return false;
  }
  // gripperbase_to_armgearright
  output->gripperbase_to_armgearright = input->gripperbase_to_armgearright;
  // max_step
  output->max_step = input->max_step;
  // jump_threshold
  output->jump_threshold = input->jump_threshold;
  // avoid_collisions
  output->avoid_collisions = input->avoid_collisions;
  return true;
}

thor_msgs__msg__CartesianGoal *
thor_msgs__msg__CartesianGoal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  thor_msgs__msg__CartesianGoal * msg = (thor_msgs__msg__CartesianGoal *)allocator.allocate(sizeof(thor_msgs__msg__CartesianGoal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(thor_msgs__msg__CartesianGoal));
  bool success = thor_msgs__msg__CartesianGoal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
thor_msgs__msg__CartesianGoal__destroy(thor_msgs__msg__CartesianGoal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    thor_msgs__msg__CartesianGoal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
thor_msgs__msg__CartesianGoal__Sequence__init(thor_msgs__msg__CartesianGoal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  thor_msgs__msg__CartesianGoal * data = NULL;

  if (size) {
    data = (thor_msgs__msg__CartesianGoal *)allocator.zero_allocate(size, sizeof(thor_msgs__msg__CartesianGoal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = thor_msgs__msg__CartesianGoal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        thor_msgs__msg__CartesianGoal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
thor_msgs__msg__CartesianGoal__Sequence__fini(thor_msgs__msg__CartesianGoal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      thor_msgs__msg__CartesianGoal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

thor_msgs__msg__CartesianGoal__Sequence *
thor_msgs__msg__CartesianGoal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  thor_msgs__msg__CartesianGoal__Sequence * array = (thor_msgs__msg__CartesianGoal__Sequence *)allocator.allocate(sizeof(thor_msgs__msg__CartesianGoal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = thor_msgs__msg__CartesianGoal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
thor_msgs__msg__CartesianGoal__Sequence__destroy(thor_msgs__msg__CartesianGoal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    thor_msgs__msg__CartesianGoal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
thor_msgs__msg__CartesianGoal__Sequence__are_equal(const thor_msgs__msg__CartesianGoal__Sequence * lhs, const thor_msgs__msg__CartesianGoal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!thor_msgs__msg__CartesianGoal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
thor_msgs__msg__CartesianGoal__Sequence__copy(
  const thor_msgs__msg__CartesianGoal__Sequence * input,
  thor_msgs__msg__CartesianGoal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(thor_msgs__msg__CartesianGoal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    thor_msgs__msg__CartesianGoal * data =
      (thor_msgs__msg__CartesianGoal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!thor_msgs__msg__CartesianGoal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          thor_msgs__msg__CartesianGoal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!thor_msgs__msg__CartesianGoal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
