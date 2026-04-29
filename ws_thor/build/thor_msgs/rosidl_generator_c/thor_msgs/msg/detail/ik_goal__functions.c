// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from thor_msgs:msg/IKGoal.idl
// generated code does not contain a copyright notice
#include "thor_msgs/msg/detail/ik_goal__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
thor_msgs__msg__IKGoal__init(thor_msgs__msg__IKGoal * msg)
{
  if (!msg) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    thor_msgs__msg__IKGoal__fini(msg);
    return false;
  }
  // gripperbase_to_armgearright
  return true;
}

void
thor_msgs__msg__IKGoal__fini(thor_msgs__msg__IKGoal * msg)
{
  if (!msg) {
    return;
  }
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
  // gripperbase_to_armgearright
}

bool
thor_msgs__msg__IKGoal__are_equal(const thor_msgs__msg__IKGoal * lhs, const thor_msgs__msg__IKGoal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  // gripperbase_to_armgearright
  if (lhs->gripperbase_to_armgearright != rhs->gripperbase_to_armgearright) {
    return false;
  }
  return true;
}

bool
thor_msgs__msg__IKGoal__copy(
  const thor_msgs__msg__IKGoal * input,
  thor_msgs__msg__IKGoal * output)
{
  if (!input || !output) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  // gripperbase_to_armgearright
  output->gripperbase_to_armgearright = input->gripperbase_to_armgearright;
  return true;
}

thor_msgs__msg__IKGoal *
thor_msgs__msg__IKGoal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  thor_msgs__msg__IKGoal * msg = (thor_msgs__msg__IKGoal *)allocator.allocate(sizeof(thor_msgs__msg__IKGoal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(thor_msgs__msg__IKGoal));
  bool success = thor_msgs__msg__IKGoal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
thor_msgs__msg__IKGoal__destroy(thor_msgs__msg__IKGoal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    thor_msgs__msg__IKGoal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
thor_msgs__msg__IKGoal__Sequence__init(thor_msgs__msg__IKGoal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  thor_msgs__msg__IKGoal * data = NULL;

  if (size) {
    data = (thor_msgs__msg__IKGoal *)allocator.zero_allocate(size, sizeof(thor_msgs__msg__IKGoal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = thor_msgs__msg__IKGoal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        thor_msgs__msg__IKGoal__fini(&data[i - 1]);
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
thor_msgs__msg__IKGoal__Sequence__fini(thor_msgs__msg__IKGoal__Sequence * array)
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
      thor_msgs__msg__IKGoal__fini(&array->data[i]);
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

thor_msgs__msg__IKGoal__Sequence *
thor_msgs__msg__IKGoal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  thor_msgs__msg__IKGoal__Sequence * array = (thor_msgs__msg__IKGoal__Sequence *)allocator.allocate(sizeof(thor_msgs__msg__IKGoal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = thor_msgs__msg__IKGoal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
thor_msgs__msg__IKGoal__Sequence__destroy(thor_msgs__msg__IKGoal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    thor_msgs__msg__IKGoal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
thor_msgs__msg__IKGoal__Sequence__are_equal(const thor_msgs__msg__IKGoal__Sequence * lhs, const thor_msgs__msg__IKGoal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!thor_msgs__msg__IKGoal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
thor_msgs__msg__IKGoal__Sequence__copy(
  const thor_msgs__msg__IKGoal__Sequence * input,
  thor_msgs__msg__IKGoal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(thor_msgs__msg__IKGoal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    thor_msgs__msg__IKGoal * data =
      (thor_msgs__msg__IKGoal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!thor_msgs__msg__IKGoal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          thor_msgs__msg__IKGoal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!thor_msgs__msg__IKGoal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
