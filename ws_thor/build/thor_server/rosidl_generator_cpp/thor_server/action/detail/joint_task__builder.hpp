// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from thor_server:action/JointTask.idl
// generated code does not contain a copyright notice

#ifndef THOR_SERVER__ACTION__DETAIL__JOINT_TASK__BUILDER_HPP_
#define THOR_SERVER__ACTION__DETAIL__JOINT_TASK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "thor_server/action/detail/joint_task__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace thor_server
{

namespace action
{

namespace builder
{

class Init_JointTask_Goal_gripper_joint_deg
{
public:
  explicit Init_JointTask_Goal_gripper_joint_deg(::thor_server::action::JointTask_Goal & msg)
  : msg_(msg)
  {}
  ::thor_server::action::JointTask_Goal gripper_joint_deg(::thor_server::action::JointTask_Goal::_gripper_joint_deg_type arg)
  {
    msg_.gripper_joint_deg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::thor_server::action::JointTask_Goal msg_;
};

class Init_JointTask_Goal_joint5_deg
{
public:
  explicit Init_JointTask_Goal_joint5_deg(::thor_server::action::JointTask_Goal & msg)
  : msg_(msg)
  {}
  Init_JointTask_Goal_gripper_joint_deg joint5_deg(::thor_server::action::JointTask_Goal::_joint5_deg_type arg)
  {
    msg_.joint5_deg = std::move(arg);
    return Init_JointTask_Goal_gripper_joint_deg(msg_);
  }

private:
  ::thor_server::action::JointTask_Goal msg_;
};

class Init_JointTask_Goal_joint4_deg
{
public:
  explicit Init_JointTask_Goal_joint4_deg(::thor_server::action::JointTask_Goal & msg)
  : msg_(msg)
  {}
  Init_JointTask_Goal_joint5_deg joint4_deg(::thor_server::action::JointTask_Goal::_joint4_deg_type arg)
  {
    msg_.joint4_deg = std::move(arg);
    return Init_JointTask_Goal_joint5_deg(msg_);
  }

private:
  ::thor_server::action::JointTask_Goal msg_;
};

class Init_JointTask_Goal_joint3_deg
{
public:
  explicit Init_JointTask_Goal_joint3_deg(::thor_server::action::JointTask_Goal & msg)
  : msg_(msg)
  {}
  Init_JointTask_Goal_joint4_deg joint3_deg(::thor_server::action::JointTask_Goal::_joint3_deg_type arg)
  {
    msg_.joint3_deg = std::move(arg);
    return Init_JointTask_Goal_joint4_deg(msg_);
  }

private:
  ::thor_server::action::JointTask_Goal msg_;
};

class Init_JointTask_Goal_joint2_deg
{
public:
  explicit Init_JointTask_Goal_joint2_deg(::thor_server::action::JointTask_Goal & msg)
  : msg_(msg)
  {}
  Init_JointTask_Goal_joint3_deg joint2_deg(::thor_server::action::JointTask_Goal::_joint2_deg_type arg)
  {
    msg_.joint2_deg = std::move(arg);
    return Init_JointTask_Goal_joint3_deg(msg_);
  }

private:
  ::thor_server::action::JointTask_Goal msg_;
};

class Init_JointTask_Goal_joint1_deg
{
public:
  Init_JointTask_Goal_joint1_deg()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JointTask_Goal_joint2_deg joint1_deg(::thor_server::action::JointTask_Goal::_joint1_deg_type arg)
  {
    msg_.joint1_deg = std::move(arg);
    return Init_JointTask_Goal_joint2_deg(msg_);
  }

private:
  ::thor_server::action::JointTask_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::thor_server::action::JointTask_Goal>()
{
  return thor_server::action::builder::Init_JointTask_Goal_joint1_deg();
}

}  // namespace thor_server


namespace thor_server
{

namespace action
{

namespace builder
{

class Init_JointTask_Result_success
{
public:
  Init_JointTask_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::thor_server::action::JointTask_Result success(::thor_server::action::JointTask_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::thor_server::action::JointTask_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::thor_server::action::JointTask_Result>()
{
  return thor_server::action::builder::Init_JointTask_Result_success();
}

}  // namespace thor_server


namespace thor_server
{

namespace action
{

namespace builder
{

class Init_JointTask_Feedback_percentage
{
public:
  Init_JointTask_Feedback_percentage()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::thor_server::action::JointTask_Feedback percentage(::thor_server::action::JointTask_Feedback::_percentage_type arg)
  {
    msg_.percentage = std::move(arg);
    return std::move(msg_);
  }

private:
  ::thor_server::action::JointTask_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::thor_server::action::JointTask_Feedback>()
{
  return thor_server::action::builder::Init_JointTask_Feedback_percentage();
}

}  // namespace thor_server


namespace thor_server
{

namespace action
{

namespace builder
{

class Init_JointTask_SendGoal_Request_goal
{
public:
  explicit Init_JointTask_SendGoal_Request_goal(::thor_server::action::JointTask_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::thor_server::action::JointTask_SendGoal_Request goal(::thor_server::action::JointTask_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::thor_server::action::JointTask_SendGoal_Request msg_;
};

class Init_JointTask_SendGoal_Request_goal_id
{
public:
  Init_JointTask_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JointTask_SendGoal_Request_goal goal_id(::thor_server::action::JointTask_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_JointTask_SendGoal_Request_goal(msg_);
  }

private:
  ::thor_server::action::JointTask_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::thor_server::action::JointTask_SendGoal_Request>()
{
  return thor_server::action::builder::Init_JointTask_SendGoal_Request_goal_id();
}

}  // namespace thor_server


namespace thor_server
{

namespace action
{

namespace builder
{

class Init_JointTask_SendGoal_Response_stamp
{
public:
  explicit Init_JointTask_SendGoal_Response_stamp(::thor_server::action::JointTask_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::thor_server::action::JointTask_SendGoal_Response stamp(::thor_server::action::JointTask_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::thor_server::action::JointTask_SendGoal_Response msg_;
};

class Init_JointTask_SendGoal_Response_accepted
{
public:
  Init_JointTask_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JointTask_SendGoal_Response_stamp accepted(::thor_server::action::JointTask_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_JointTask_SendGoal_Response_stamp(msg_);
  }

private:
  ::thor_server::action::JointTask_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::thor_server::action::JointTask_SendGoal_Response>()
{
  return thor_server::action::builder::Init_JointTask_SendGoal_Response_accepted();
}

}  // namespace thor_server


namespace thor_server
{

namespace action
{

namespace builder
{

class Init_JointTask_GetResult_Request_goal_id
{
public:
  Init_JointTask_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::thor_server::action::JointTask_GetResult_Request goal_id(::thor_server::action::JointTask_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::thor_server::action::JointTask_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::thor_server::action::JointTask_GetResult_Request>()
{
  return thor_server::action::builder::Init_JointTask_GetResult_Request_goal_id();
}

}  // namespace thor_server


namespace thor_server
{

namespace action
{

namespace builder
{

class Init_JointTask_GetResult_Response_result
{
public:
  explicit Init_JointTask_GetResult_Response_result(::thor_server::action::JointTask_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::thor_server::action::JointTask_GetResult_Response result(::thor_server::action::JointTask_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::thor_server::action::JointTask_GetResult_Response msg_;
};

class Init_JointTask_GetResult_Response_status
{
public:
  Init_JointTask_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JointTask_GetResult_Response_result status(::thor_server::action::JointTask_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_JointTask_GetResult_Response_result(msg_);
  }

private:
  ::thor_server::action::JointTask_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::thor_server::action::JointTask_GetResult_Response>()
{
  return thor_server::action::builder::Init_JointTask_GetResult_Response_status();
}

}  // namespace thor_server


namespace thor_server
{

namespace action
{

namespace builder
{

class Init_JointTask_FeedbackMessage_feedback
{
public:
  explicit Init_JointTask_FeedbackMessage_feedback(::thor_server::action::JointTask_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::thor_server::action::JointTask_FeedbackMessage feedback(::thor_server::action::JointTask_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::thor_server::action::JointTask_FeedbackMessage msg_;
};

class Init_JointTask_FeedbackMessage_goal_id
{
public:
  Init_JointTask_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JointTask_FeedbackMessage_feedback goal_id(::thor_server::action::JointTask_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_JointTask_FeedbackMessage_feedback(msg_);
  }

private:
  ::thor_server::action::JointTask_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::thor_server::action::JointTask_FeedbackMessage>()
{
  return thor_server::action::builder::Init_JointTask_FeedbackMessage_goal_id();
}

}  // namespace thor_server

#endif  // THOR_SERVER__ACTION__DETAIL__JOINT_TASK__BUILDER_HPP_
