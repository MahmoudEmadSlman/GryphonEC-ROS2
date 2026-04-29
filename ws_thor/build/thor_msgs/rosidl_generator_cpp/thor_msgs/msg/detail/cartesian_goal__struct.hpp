// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from thor_msgs:msg/CartesianGoal.idl
// generated code does not contain a copyright notice

#ifndef THOR_MSGS__MSG__DETAIL__CARTESIAN_GOAL__STRUCT_HPP_
#define THOR_MSGS__MSG__DETAIL__CARTESIAN_GOAL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'start_pose'
// Member 'end_pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__thor_msgs__msg__CartesianGoal __attribute__((deprecated))
#else
# define DEPRECATED__thor_msgs__msg__CartesianGoal __declspec(deprecated)
#endif

namespace thor_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CartesianGoal_
{
  using Type = CartesianGoal_<ContainerAllocator>;

  explicit CartesianGoal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : start_pose(_init),
    end_pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gripperbase_to_armgearright = 0.0;
      this->max_step = 0.0;
      this->jump_threshold = 0.0;
      this->avoid_collisions = false;
    }
  }

  explicit CartesianGoal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : start_pose(_alloc, _init),
    end_pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gripperbase_to_armgearright = 0.0;
      this->max_step = 0.0;
      this->jump_threshold = 0.0;
      this->avoid_collisions = false;
    }
  }

  // field types and members
  using _start_pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _start_pose_type start_pose;
  using _end_pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _end_pose_type end_pose;
  using _gripperbase_to_armgearright_type =
    double;
  _gripperbase_to_armgearright_type gripperbase_to_armgearright;
  using _max_step_type =
    double;
  _max_step_type max_step;
  using _jump_threshold_type =
    double;
  _jump_threshold_type jump_threshold;
  using _avoid_collisions_type =
    bool;
  _avoid_collisions_type avoid_collisions;

  // setters for named parameter idiom
  Type & set__start_pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->start_pose = _arg;
    return *this;
  }
  Type & set__end_pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->end_pose = _arg;
    return *this;
  }
  Type & set__gripperbase_to_armgearright(
    const double & _arg)
  {
    this->gripperbase_to_armgearright = _arg;
    return *this;
  }
  Type & set__max_step(
    const double & _arg)
  {
    this->max_step = _arg;
    return *this;
  }
  Type & set__jump_threshold(
    const double & _arg)
  {
    this->jump_threshold = _arg;
    return *this;
  }
  Type & set__avoid_collisions(
    const bool & _arg)
  {
    this->avoid_collisions = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    thor_msgs::msg::CartesianGoal_<ContainerAllocator> *;
  using ConstRawPtr =
    const thor_msgs::msg::CartesianGoal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<thor_msgs::msg::CartesianGoal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<thor_msgs::msg::CartesianGoal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      thor_msgs::msg::CartesianGoal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<thor_msgs::msg::CartesianGoal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      thor_msgs::msg::CartesianGoal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<thor_msgs::msg::CartesianGoal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<thor_msgs::msg::CartesianGoal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<thor_msgs::msg::CartesianGoal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__thor_msgs__msg__CartesianGoal
    std::shared_ptr<thor_msgs::msg::CartesianGoal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__thor_msgs__msg__CartesianGoal
    std::shared_ptr<thor_msgs::msg::CartesianGoal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CartesianGoal_ & other) const
  {
    if (this->start_pose != other.start_pose) {
      return false;
    }
    if (this->end_pose != other.end_pose) {
      return false;
    }
    if (this->gripperbase_to_armgearright != other.gripperbase_to_armgearright) {
      return false;
    }
    if (this->max_step != other.max_step) {
      return false;
    }
    if (this->jump_threshold != other.jump_threshold) {
      return false;
    }
    if (this->avoid_collisions != other.avoid_collisions) {
      return false;
    }
    return true;
  }
  bool operator!=(const CartesianGoal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CartesianGoal_

// alias to use template instance with default allocator
using CartesianGoal =
  thor_msgs::msg::CartesianGoal_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace thor_msgs

#endif  // THOR_MSGS__MSG__DETAIL__CARTESIAN_GOAL__STRUCT_HPP_
