// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from thor_msgs:msg/CartesianGoal.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "thor_msgs/msg/detail/cartesian_goal__struct.h"
#include "thor_msgs/msg/detail/cartesian_goal__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__pose__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__pose__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__pose__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__pose__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool thor_msgs__msg__cartesian_goal__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[44];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("thor_msgs.msg._cartesian_goal.CartesianGoal", full_classname_dest, 43) == 0);
  }
  thor_msgs__msg__CartesianGoal * ros_message = _ros_message;
  {  // start_pose
    PyObject * field = PyObject_GetAttrString(_pymsg, "start_pose");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__pose__convert_from_py(field, &ros_message->start_pose)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // end_pose
    PyObject * field = PyObject_GetAttrString(_pymsg, "end_pose");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__pose__convert_from_py(field, &ros_message->end_pose)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // gripperbase_to_armgearright
    PyObject * field = PyObject_GetAttrString(_pymsg, "gripperbase_to_armgearright");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gripperbase_to_armgearright = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // max_step
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_step");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_step = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // jump_threshold
    PyObject * field = PyObject_GetAttrString(_pymsg, "jump_threshold");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->jump_threshold = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // avoid_collisions
    PyObject * field = PyObject_GetAttrString(_pymsg, "avoid_collisions");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->avoid_collisions = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * thor_msgs__msg__cartesian_goal__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CartesianGoal */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("thor_msgs.msg._cartesian_goal");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CartesianGoal");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  thor_msgs__msg__CartesianGoal * ros_message = (thor_msgs__msg__CartesianGoal *)raw_ros_message;
  {  // start_pose
    PyObject * field = NULL;
    field = geometry_msgs__msg__pose__convert_to_py(&ros_message->start_pose);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "start_pose", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // end_pose
    PyObject * field = NULL;
    field = geometry_msgs__msg__pose__convert_to_py(&ros_message->end_pose);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "end_pose", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gripperbase_to_armgearright
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gripperbase_to_armgearright);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gripperbase_to_armgearright", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_step
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_step);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_step", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // jump_threshold
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->jump_threshold);
    {
      int rc = PyObject_SetAttrString(_pymessage, "jump_threshold", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // avoid_collisions
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->avoid_collisions ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "avoid_collisions", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
