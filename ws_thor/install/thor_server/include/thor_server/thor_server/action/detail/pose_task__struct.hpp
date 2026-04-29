// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from thor_server:action/PoseTask.idl
// generated code does not contain a copyright notice

#ifndef THOR_SERVER__ACTION__DETAIL__POSE_TASK__STRUCT_HPP_
#define THOR_SERVER__ACTION__DETAIL__POSE_TASK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__thor_server__action__PoseTask_Goal __attribute__((deprecated))
#else
# define DEPRECATED__thor_server__action__PoseTask_Goal __declspec(deprecated)
#endif

namespace thor_server
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PoseTask_Goal_
{
  using Type = PoseTask_Goal_<ContainerAllocator>;

  explicit PoseTask_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->roll = 0.0f;
      this->pitch = 0.0f;
      this->yaw = 0.0f;
    }
  }

  explicit PoseTask_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->roll = 0.0f;
      this->pitch = 0.0f;
      this->yaw = 0.0f;
    }
  }

  // field types and members
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _z_type =
    float;
  _z_type z;
  using _roll_type =
    float;
  _roll_type roll;
  using _pitch_type =
    float;
  _pitch_type pitch;
  using _yaw_type =
    float;
  _yaw_type yaw;

  // setters for named parameter idiom
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const float & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__roll(
    const float & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__pitch(
    const float & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__yaw(
    const float & _arg)
  {
    this->yaw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    thor_server::action::PoseTask_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const thor_server::action::PoseTask_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<thor_server::action::PoseTask_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<thor_server::action::PoseTask_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      thor_server::action::PoseTask_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::PoseTask_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      thor_server::action::PoseTask_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::PoseTask_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<thor_server::action::PoseTask_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<thor_server::action::PoseTask_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__thor_server__action__PoseTask_Goal
    std::shared_ptr<thor_server::action::PoseTask_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__thor_server__action__PoseTask_Goal
    std::shared_ptr<thor_server::action::PoseTask_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseTask_Goal_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseTask_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseTask_Goal_

// alias to use template instance with default allocator
using PoseTask_Goal =
  thor_server::action::PoseTask_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace thor_server


#ifndef _WIN32
# define DEPRECATED__thor_server__action__PoseTask_Result __attribute__((deprecated))
#else
# define DEPRECATED__thor_server__action__PoseTask_Result __declspec(deprecated)
#endif

namespace thor_server
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PoseTask_Result_
{
  using Type = PoseTask_Result_<ContainerAllocator>;

  explicit PoseTask_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit PoseTask_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    thor_server::action::PoseTask_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const thor_server::action::PoseTask_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<thor_server::action::PoseTask_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<thor_server::action::PoseTask_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      thor_server::action::PoseTask_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::PoseTask_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      thor_server::action::PoseTask_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::PoseTask_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<thor_server::action::PoseTask_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<thor_server::action::PoseTask_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__thor_server__action__PoseTask_Result
    std::shared_ptr<thor_server::action::PoseTask_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__thor_server__action__PoseTask_Result
    std::shared_ptr<thor_server::action::PoseTask_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseTask_Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseTask_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseTask_Result_

// alias to use template instance with default allocator
using PoseTask_Result =
  thor_server::action::PoseTask_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace thor_server


#ifndef _WIN32
# define DEPRECATED__thor_server__action__PoseTask_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__thor_server__action__PoseTask_Feedback __declspec(deprecated)
#endif

namespace thor_server
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PoseTask_Feedback_
{
  using Type = PoseTask_Feedback_<ContainerAllocator>;

  explicit PoseTask_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->percentage = 0l;
    }
  }

  explicit PoseTask_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->percentage = 0l;
    }
  }

  // field types and members
  using _percentage_type =
    int32_t;
  _percentage_type percentage;

  // setters for named parameter idiom
  Type & set__percentage(
    const int32_t & _arg)
  {
    this->percentage = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    thor_server::action::PoseTask_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const thor_server::action::PoseTask_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<thor_server::action::PoseTask_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<thor_server::action::PoseTask_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      thor_server::action::PoseTask_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::PoseTask_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      thor_server::action::PoseTask_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::PoseTask_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<thor_server::action::PoseTask_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<thor_server::action::PoseTask_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__thor_server__action__PoseTask_Feedback
    std::shared_ptr<thor_server::action::PoseTask_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__thor_server__action__PoseTask_Feedback
    std::shared_ptr<thor_server::action::PoseTask_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseTask_Feedback_ & other) const
  {
    if (this->percentage != other.percentage) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseTask_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseTask_Feedback_

// alias to use template instance with default allocator
using PoseTask_Feedback =
  thor_server::action::PoseTask_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace thor_server


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "thor_server/action/detail/pose_task__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__thor_server__action__PoseTask_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__thor_server__action__PoseTask_SendGoal_Request __declspec(deprecated)
#endif

namespace thor_server
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PoseTask_SendGoal_Request_
{
  using Type = PoseTask_SendGoal_Request_<ContainerAllocator>;

  explicit PoseTask_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit PoseTask_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    thor_server::action::PoseTask_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const thor_server::action::PoseTask_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    thor_server::action::PoseTask_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const thor_server::action::PoseTask_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<thor_server::action::PoseTask_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<thor_server::action::PoseTask_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      thor_server::action::PoseTask_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::PoseTask_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      thor_server::action::PoseTask_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::PoseTask_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<thor_server::action::PoseTask_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<thor_server::action::PoseTask_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__thor_server__action__PoseTask_SendGoal_Request
    std::shared_ptr<thor_server::action::PoseTask_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__thor_server__action__PoseTask_SendGoal_Request
    std::shared_ptr<thor_server::action::PoseTask_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseTask_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseTask_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseTask_SendGoal_Request_

// alias to use template instance with default allocator
using PoseTask_SendGoal_Request =
  thor_server::action::PoseTask_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace thor_server


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__thor_server__action__PoseTask_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__thor_server__action__PoseTask_SendGoal_Response __declspec(deprecated)
#endif

namespace thor_server
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PoseTask_SendGoal_Response_
{
  using Type = PoseTask_SendGoal_Response_<ContainerAllocator>;

  explicit PoseTask_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit PoseTask_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    thor_server::action::PoseTask_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const thor_server::action::PoseTask_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<thor_server::action::PoseTask_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<thor_server::action::PoseTask_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      thor_server::action::PoseTask_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::PoseTask_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      thor_server::action::PoseTask_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::PoseTask_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<thor_server::action::PoseTask_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<thor_server::action::PoseTask_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__thor_server__action__PoseTask_SendGoal_Response
    std::shared_ptr<thor_server::action::PoseTask_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__thor_server__action__PoseTask_SendGoal_Response
    std::shared_ptr<thor_server::action::PoseTask_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseTask_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseTask_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseTask_SendGoal_Response_

// alias to use template instance with default allocator
using PoseTask_SendGoal_Response =
  thor_server::action::PoseTask_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace thor_server

namespace thor_server
{

namespace action
{

struct PoseTask_SendGoal
{
  using Request = thor_server::action::PoseTask_SendGoal_Request;
  using Response = thor_server::action::PoseTask_SendGoal_Response;
};

}  // namespace action

}  // namespace thor_server


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__thor_server__action__PoseTask_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__thor_server__action__PoseTask_GetResult_Request __declspec(deprecated)
#endif

namespace thor_server
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PoseTask_GetResult_Request_
{
  using Type = PoseTask_GetResult_Request_<ContainerAllocator>;

  explicit PoseTask_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit PoseTask_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    thor_server::action::PoseTask_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const thor_server::action::PoseTask_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<thor_server::action::PoseTask_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<thor_server::action::PoseTask_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      thor_server::action::PoseTask_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::PoseTask_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      thor_server::action::PoseTask_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::PoseTask_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<thor_server::action::PoseTask_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<thor_server::action::PoseTask_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__thor_server__action__PoseTask_GetResult_Request
    std::shared_ptr<thor_server::action::PoseTask_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__thor_server__action__PoseTask_GetResult_Request
    std::shared_ptr<thor_server::action::PoseTask_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseTask_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseTask_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseTask_GetResult_Request_

// alias to use template instance with default allocator
using PoseTask_GetResult_Request =
  thor_server::action::PoseTask_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace thor_server


// Include directives for member types
// Member 'result'
// already included above
// #include "thor_server/action/detail/pose_task__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__thor_server__action__PoseTask_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__thor_server__action__PoseTask_GetResult_Response __declspec(deprecated)
#endif

namespace thor_server
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PoseTask_GetResult_Response_
{
  using Type = PoseTask_GetResult_Response_<ContainerAllocator>;

  explicit PoseTask_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit PoseTask_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    thor_server::action::PoseTask_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const thor_server::action::PoseTask_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    thor_server::action::PoseTask_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const thor_server::action::PoseTask_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<thor_server::action::PoseTask_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<thor_server::action::PoseTask_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      thor_server::action::PoseTask_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::PoseTask_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      thor_server::action::PoseTask_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::PoseTask_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<thor_server::action::PoseTask_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<thor_server::action::PoseTask_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__thor_server__action__PoseTask_GetResult_Response
    std::shared_ptr<thor_server::action::PoseTask_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__thor_server__action__PoseTask_GetResult_Response
    std::shared_ptr<thor_server::action::PoseTask_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseTask_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseTask_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseTask_GetResult_Response_

// alias to use template instance with default allocator
using PoseTask_GetResult_Response =
  thor_server::action::PoseTask_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace thor_server

namespace thor_server
{

namespace action
{

struct PoseTask_GetResult
{
  using Request = thor_server::action::PoseTask_GetResult_Request;
  using Response = thor_server::action::PoseTask_GetResult_Response;
};

}  // namespace action

}  // namespace thor_server


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "thor_server/action/detail/pose_task__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__thor_server__action__PoseTask_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__thor_server__action__PoseTask_FeedbackMessage __declspec(deprecated)
#endif

namespace thor_server
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PoseTask_FeedbackMessage_
{
  using Type = PoseTask_FeedbackMessage_<ContainerAllocator>;

  explicit PoseTask_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit PoseTask_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    thor_server::action::PoseTask_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const thor_server::action::PoseTask_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    thor_server::action::PoseTask_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const thor_server::action::PoseTask_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<thor_server::action::PoseTask_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<thor_server::action::PoseTask_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      thor_server::action::PoseTask_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::PoseTask_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      thor_server::action::PoseTask_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::PoseTask_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<thor_server::action::PoseTask_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<thor_server::action::PoseTask_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__thor_server__action__PoseTask_FeedbackMessage
    std::shared_ptr<thor_server::action::PoseTask_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__thor_server__action__PoseTask_FeedbackMessage
    std::shared_ptr<thor_server::action::PoseTask_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseTask_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseTask_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseTask_FeedbackMessage_

// alias to use template instance with default allocator
using PoseTask_FeedbackMessage =
  thor_server::action::PoseTask_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace thor_server

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace thor_server
{

namespace action
{

struct PoseTask
{
  /// The goal message defined in the action definition.
  using Goal = thor_server::action::PoseTask_Goal;
  /// The result message defined in the action definition.
  using Result = thor_server::action::PoseTask_Result;
  /// The feedback message defined in the action definition.
  using Feedback = thor_server::action::PoseTask_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = thor_server::action::PoseTask_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = thor_server::action::PoseTask_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = thor_server::action::PoseTask_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct PoseTask PoseTask;

}  // namespace action

}  // namespace thor_server

#endif  // THOR_SERVER__ACTION__DETAIL__POSE_TASK__STRUCT_HPP_
