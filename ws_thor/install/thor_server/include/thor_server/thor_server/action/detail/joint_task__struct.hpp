// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from thor_server:action/JointTask.idl
// generated code does not contain a copyright notice

#ifndef THOR_SERVER__ACTION__DETAIL__JOINT_TASK__STRUCT_HPP_
#define THOR_SERVER__ACTION__DETAIL__JOINT_TASK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__thor_server__action__JointTask_Goal __attribute__((deprecated))
#else
# define DEPRECATED__thor_server__action__JointTask_Goal __declspec(deprecated)
#endif

namespace thor_server
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct JointTask_Goal_
{
  using Type = JointTask_Goal_<ContainerAllocator>;

  explicit JointTask_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->joint1_deg = 0.0f;
      this->joint2_deg = 0.0f;
      this->joint3_deg = 0.0f;
      this->joint4_deg = 0.0f;
      this->joint5_deg = 0.0f;
      this->gripper_joint_deg = 0.0f;
    }
  }

  explicit JointTask_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->joint1_deg = 0.0f;
      this->joint2_deg = 0.0f;
      this->joint3_deg = 0.0f;
      this->joint4_deg = 0.0f;
      this->joint5_deg = 0.0f;
      this->gripper_joint_deg = 0.0f;
    }
  }

  // field types and members
  using _joint1_deg_type =
    float;
  _joint1_deg_type joint1_deg;
  using _joint2_deg_type =
    float;
  _joint2_deg_type joint2_deg;
  using _joint3_deg_type =
    float;
  _joint3_deg_type joint3_deg;
  using _joint4_deg_type =
    float;
  _joint4_deg_type joint4_deg;
  using _joint5_deg_type =
    float;
  _joint5_deg_type joint5_deg;
  using _gripper_joint_deg_type =
    float;
  _gripper_joint_deg_type gripper_joint_deg;

  // setters for named parameter idiom
  Type & set__joint1_deg(
    const float & _arg)
  {
    this->joint1_deg = _arg;
    return *this;
  }
  Type & set__joint2_deg(
    const float & _arg)
  {
    this->joint2_deg = _arg;
    return *this;
  }
  Type & set__joint3_deg(
    const float & _arg)
  {
    this->joint3_deg = _arg;
    return *this;
  }
  Type & set__joint4_deg(
    const float & _arg)
  {
    this->joint4_deg = _arg;
    return *this;
  }
  Type & set__joint5_deg(
    const float & _arg)
  {
    this->joint5_deg = _arg;
    return *this;
  }
  Type & set__gripper_joint_deg(
    const float & _arg)
  {
    this->gripper_joint_deg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    thor_server::action::JointTask_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const thor_server::action::JointTask_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<thor_server::action::JointTask_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<thor_server::action::JointTask_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      thor_server::action::JointTask_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::JointTask_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      thor_server::action::JointTask_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::JointTask_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<thor_server::action::JointTask_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<thor_server::action::JointTask_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__thor_server__action__JointTask_Goal
    std::shared_ptr<thor_server::action::JointTask_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__thor_server__action__JointTask_Goal
    std::shared_ptr<thor_server::action::JointTask_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointTask_Goal_ & other) const
  {
    if (this->joint1_deg != other.joint1_deg) {
      return false;
    }
    if (this->joint2_deg != other.joint2_deg) {
      return false;
    }
    if (this->joint3_deg != other.joint3_deg) {
      return false;
    }
    if (this->joint4_deg != other.joint4_deg) {
      return false;
    }
    if (this->joint5_deg != other.joint5_deg) {
      return false;
    }
    if (this->gripper_joint_deg != other.gripper_joint_deg) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointTask_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointTask_Goal_

// alias to use template instance with default allocator
using JointTask_Goal =
  thor_server::action::JointTask_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace thor_server


#ifndef _WIN32
# define DEPRECATED__thor_server__action__JointTask_Result __attribute__((deprecated))
#else
# define DEPRECATED__thor_server__action__JointTask_Result __declspec(deprecated)
#endif

namespace thor_server
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct JointTask_Result_
{
  using Type = JointTask_Result_<ContainerAllocator>;

  explicit JointTask_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit JointTask_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    thor_server::action::JointTask_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const thor_server::action::JointTask_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<thor_server::action::JointTask_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<thor_server::action::JointTask_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      thor_server::action::JointTask_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::JointTask_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      thor_server::action::JointTask_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::JointTask_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<thor_server::action::JointTask_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<thor_server::action::JointTask_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__thor_server__action__JointTask_Result
    std::shared_ptr<thor_server::action::JointTask_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__thor_server__action__JointTask_Result
    std::shared_ptr<thor_server::action::JointTask_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointTask_Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointTask_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointTask_Result_

// alias to use template instance with default allocator
using JointTask_Result =
  thor_server::action::JointTask_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace thor_server


#ifndef _WIN32
# define DEPRECATED__thor_server__action__JointTask_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__thor_server__action__JointTask_Feedback __declspec(deprecated)
#endif

namespace thor_server
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct JointTask_Feedback_
{
  using Type = JointTask_Feedback_<ContainerAllocator>;

  explicit JointTask_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->percentage = 0l;
    }
  }

  explicit JointTask_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    thor_server::action::JointTask_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const thor_server::action::JointTask_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<thor_server::action::JointTask_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<thor_server::action::JointTask_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      thor_server::action::JointTask_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::JointTask_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      thor_server::action::JointTask_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::JointTask_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<thor_server::action::JointTask_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<thor_server::action::JointTask_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__thor_server__action__JointTask_Feedback
    std::shared_ptr<thor_server::action::JointTask_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__thor_server__action__JointTask_Feedback
    std::shared_ptr<thor_server::action::JointTask_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointTask_Feedback_ & other) const
  {
    if (this->percentage != other.percentage) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointTask_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointTask_Feedback_

// alias to use template instance with default allocator
using JointTask_Feedback =
  thor_server::action::JointTask_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace thor_server


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "thor_server/action/detail/joint_task__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__thor_server__action__JointTask_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__thor_server__action__JointTask_SendGoal_Request __declspec(deprecated)
#endif

namespace thor_server
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct JointTask_SendGoal_Request_
{
  using Type = JointTask_SendGoal_Request_<ContainerAllocator>;

  explicit JointTask_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit JointTask_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    thor_server::action::JointTask_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const thor_server::action::JointTask_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    thor_server::action::JointTask_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const thor_server::action::JointTask_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<thor_server::action::JointTask_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<thor_server::action::JointTask_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      thor_server::action::JointTask_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::JointTask_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      thor_server::action::JointTask_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::JointTask_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<thor_server::action::JointTask_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<thor_server::action::JointTask_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__thor_server__action__JointTask_SendGoal_Request
    std::shared_ptr<thor_server::action::JointTask_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__thor_server__action__JointTask_SendGoal_Request
    std::shared_ptr<thor_server::action::JointTask_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointTask_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointTask_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointTask_SendGoal_Request_

// alias to use template instance with default allocator
using JointTask_SendGoal_Request =
  thor_server::action::JointTask_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace thor_server


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__thor_server__action__JointTask_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__thor_server__action__JointTask_SendGoal_Response __declspec(deprecated)
#endif

namespace thor_server
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct JointTask_SendGoal_Response_
{
  using Type = JointTask_SendGoal_Response_<ContainerAllocator>;

  explicit JointTask_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit JointTask_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    thor_server::action::JointTask_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const thor_server::action::JointTask_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<thor_server::action::JointTask_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<thor_server::action::JointTask_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      thor_server::action::JointTask_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::JointTask_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      thor_server::action::JointTask_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::JointTask_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<thor_server::action::JointTask_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<thor_server::action::JointTask_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__thor_server__action__JointTask_SendGoal_Response
    std::shared_ptr<thor_server::action::JointTask_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__thor_server__action__JointTask_SendGoal_Response
    std::shared_ptr<thor_server::action::JointTask_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointTask_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointTask_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointTask_SendGoal_Response_

// alias to use template instance with default allocator
using JointTask_SendGoal_Response =
  thor_server::action::JointTask_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace thor_server

namespace thor_server
{

namespace action
{

struct JointTask_SendGoal
{
  using Request = thor_server::action::JointTask_SendGoal_Request;
  using Response = thor_server::action::JointTask_SendGoal_Response;
};

}  // namespace action

}  // namespace thor_server


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__thor_server__action__JointTask_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__thor_server__action__JointTask_GetResult_Request __declspec(deprecated)
#endif

namespace thor_server
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct JointTask_GetResult_Request_
{
  using Type = JointTask_GetResult_Request_<ContainerAllocator>;

  explicit JointTask_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit JointTask_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    thor_server::action::JointTask_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const thor_server::action::JointTask_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<thor_server::action::JointTask_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<thor_server::action::JointTask_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      thor_server::action::JointTask_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::JointTask_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      thor_server::action::JointTask_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::JointTask_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<thor_server::action::JointTask_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<thor_server::action::JointTask_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__thor_server__action__JointTask_GetResult_Request
    std::shared_ptr<thor_server::action::JointTask_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__thor_server__action__JointTask_GetResult_Request
    std::shared_ptr<thor_server::action::JointTask_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointTask_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointTask_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointTask_GetResult_Request_

// alias to use template instance with default allocator
using JointTask_GetResult_Request =
  thor_server::action::JointTask_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace thor_server


// Include directives for member types
// Member 'result'
// already included above
// #include "thor_server/action/detail/joint_task__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__thor_server__action__JointTask_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__thor_server__action__JointTask_GetResult_Response __declspec(deprecated)
#endif

namespace thor_server
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct JointTask_GetResult_Response_
{
  using Type = JointTask_GetResult_Response_<ContainerAllocator>;

  explicit JointTask_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit JointTask_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    thor_server::action::JointTask_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const thor_server::action::JointTask_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    thor_server::action::JointTask_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const thor_server::action::JointTask_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<thor_server::action::JointTask_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<thor_server::action::JointTask_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      thor_server::action::JointTask_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::JointTask_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      thor_server::action::JointTask_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::JointTask_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<thor_server::action::JointTask_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<thor_server::action::JointTask_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__thor_server__action__JointTask_GetResult_Response
    std::shared_ptr<thor_server::action::JointTask_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__thor_server__action__JointTask_GetResult_Response
    std::shared_ptr<thor_server::action::JointTask_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointTask_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointTask_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointTask_GetResult_Response_

// alias to use template instance with default allocator
using JointTask_GetResult_Response =
  thor_server::action::JointTask_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace thor_server

namespace thor_server
{

namespace action
{

struct JointTask_GetResult
{
  using Request = thor_server::action::JointTask_GetResult_Request;
  using Response = thor_server::action::JointTask_GetResult_Response;
};

}  // namespace action

}  // namespace thor_server


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "thor_server/action/detail/joint_task__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__thor_server__action__JointTask_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__thor_server__action__JointTask_FeedbackMessage __declspec(deprecated)
#endif

namespace thor_server
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct JointTask_FeedbackMessage_
{
  using Type = JointTask_FeedbackMessage_<ContainerAllocator>;

  explicit JointTask_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit JointTask_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    thor_server::action::JointTask_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const thor_server::action::JointTask_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    thor_server::action::JointTask_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const thor_server::action::JointTask_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<thor_server::action::JointTask_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<thor_server::action::JointTask_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      thor_server::action::JointTask_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::JointTask_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      thor_server::action::JointTask_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<thor_server::action::JointTask_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<thor_server::action::JointTask_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<thor_server::action::JointTask_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__thor_server__action__JointTask_FeedbackMessage
    std::shared_ptr<thor_server::action::JointTask_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__thor_server__action__JointTask_FeedbackMessage
    std::shared_ptr<thor_server::action::JointTask_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointTask_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointTask_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointTask_FeedbackMessage_

// alias to use template instance with default allocator
using JointTask_FeedbackMessage =
  thor_server::action::JointTask_FeedbackMessage_<std::allocator<void>>;

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

struct JointTask
{
  /// The goal message defined in the action definition.
  using Goal = thor_server::action::JointTask_Goal;
  /// The result message defined in the action definition.
  using Result = thor_server::action::JointTask_Result;
  /// The feedback message defined in the action definition.
  using Feedback = thor_server::action::JointTask_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = thor_server::action::JointTask_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = thor_server::action::JointTask_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = thor_server::action::JointTask_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct JointTask JointTask;

}  // namespace action

}  // namespace thor_server

#endif  // THOR_SERVER__ACTION__DETAIL__JOINT_TASK__STRUCT_HPP_
