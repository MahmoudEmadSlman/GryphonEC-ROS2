// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from thor_server:action/PoseTask.idl
// generated code does not contain a copyright notice

#ifndef THOR_SERVER__ACTION__DETAIL__POSE_TASK__BUILDER_HPP_
#define THOR_SERVER__ACTION__DETAIL__POSE_TASK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "thor_server/action/detail/pose_task__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace thor_server
{

namespace action
{

namespace builder
{

class Init_PoseTask_Goal_yaw
{
public:
  explicit Init_PoseTask_Goal_yaw(::thor_server::action::PoseTask_Goal & msg)
  : msg_(msg)
  {}
  ::thor_server::action::PoseTask_Goal yaw(::thor_server::action::PoseTask_Goal::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::thor_server::action::PoseTask_Goal msg_;
};

class Init_PoseTask_Goal_pitch
{
public:
  explicit Init_PoseTask_Goal_pitch(::thor_server::action::PoseTask_Goal & msg)
  : msg_(msg)
  {}
  Init_PoseTask_Goal_yaw pitch(::thor_server::action::PoseTask_Goal::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_PoseTask_Goal_yaw(msg_);
  }

private:
  ::thor_server::action::PoseTask_Goal msg_;
};

class Init_PoseTask_Goal_roll
{
public:
  explicit Init_PoseTask_Goal_roll(::thor_server::action::PoseTask_Goal & msg)
  : msg_(msg)
  {}
  Init_PoseTask_Goal_pitch roll(::thor_server::action::PoseTask_Goal::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_PoseTask_Goal_pitch(msg_);
  }

private:
  ::thor_server::action::PoseTask_Goal msg_;
};

class Init_PoseTask_Goal_z
{
public:
  explicit Init_PoseTask_Goal_z(::thor_server::action::PoseTask_Goal & msg)
  : msg_(msg)
  {}
  Init_PoseTask_Goal_roll z(::thor_server::action::PoseTask_Goal::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_PoseTask_Goal_roll(msg_);
  }

private:
  ::thor_server::action::PoseTask_Goal msg_;
};

class Init_PoseTask_Goal_y
{
public:
  explicit Init_PoseTask_Goal_y(::thor_server::action::PoseTask_Goal & msg)
  : msg_(msg)
  {}
  Init_PoseTask_Goal_z y(::thor_server::action::PoseTask_Goal::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_PoseTask_Goal_z(msg_);
  }

private:
  ::thor_server::action::PoseTask_Goal msg_;
};

class Init_PoseTask_Goal_x
{
public:
  Init_PoseTask_Goal_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseTask_Goal_y x(::thor_server::action::PoseTask_Goal::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_PoseTask_Goal_y(msg_);
  }

private:
  ::thor_server::action::PoseTask_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::thor_server::action::PoseTask_Goal>()
{
  return thor_server::action::builder::Init_PoseTask_Goal_x();
}

}  // namespace thor_server


namespace thor_server
{

namespace action
{

namespace builder
{

class Init_PoseTask_Result_success
{
public:
  Init_PoseTask_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::thor_server::action::PoseTask_Result success(::thor_server::action::PoseTask_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::thor_server::action::PoseTask_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::thor_server::action::PoseTask_Result>()
{
  return thor_server::action::builder::Init_PoseTask_Result_success();
}

}  // namespace thor_server


namespace thor_server
{

namespace action
{

namespace builder
{

class Init_PoseTask_Feedback_percentage
{
public:
  Init_PoseTask_Feedback_percentage()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::thor_server::action::PoseTask_Feedback percentage(::thor_server::action::PoseTask_Feedback::_percentage_type arg)
  {
    msg_.percentage = std::move(arg);
    return std::move(msg_);
  }

private:
  ::thor_server::action::PoseTask_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::thor_server::action::PoseTask_Feedback>()
{
  return thor_server::action::builder::Init_PoseTask_Feedback_percentage();
}

}  // namespace thor_server


namespace thor_server
{

namespace action
{

namespace builder
{

class Init_PoseTask_SendGoal_Request_goal
{
public:
  explicit Init_PoseTask_SendGoal_Request_goal(::thor_server::action::PoseTask_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::thor_server::action::PoseTask_SendGoal_Request goal(::thor_server::action::PoseTask_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::thor_server::action::PoseTask_SendGoal_Request msg_;
};

class Init_PoseTask_SendGoal_Request_goal_id
{
public:
  Init_PoseTask_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseTask_SendGoal_Request_goal goal_id(::thor_server::action::PoseTask_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_PoseTask_SendGoal_Request_goal(msg_);
  }

private:
  ::thor_server::action::PoseTask_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::thor_server::action::PoseTask_SendGoal_Request>()
{
  return thor_server::action::builder::Init_PoseTask_SendGoal_Request_goal_id();
}

}  // namespace thor_server


namespace thor_server
{

namespace action
{

namespace builder
{

class Init_PoseTask_SendGoal_Response_stamp
{
public:
  explicit Init_PoseTask_SendGoal_Response_stamp(::thor_server::action::PoseTask_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::thor_server::action::PoseTask_SendGoal_Response stamp(::thor_server::action::PoseTask_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::thor_server::action::PoseTask_SendGoal_Response msg_;
};

class Init_PoseTask_SendGoal_Response_accepted
{
public:
  Init_PoseTask_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseTask_SendGoal_Response_stamp accepted(::thor_server::action::PoseTask_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_PoseTask_SendGoal_Response_stamp(msg_);
  }

private:
  ::thor_server::action::PoseTask_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::thor_server::action::PoseTask_SendGoal_Response>()
{
  return thor_server::action::builder::Init_PoseTask_SendGoal_Response_accepted();
}

}  // namespace thor_server


namespace thor_server
{

namespace action
{

namespace builder
{

class Init_PoseTask_GetResult_Request_goal_id
{
public:
  Init_PoseTask_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::thor_server::action::PoseTask_GetResult_Request goal_id(::thor_server::action::PoseTask_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::thor_server::action::PoseTask_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::thor_server::action::PoseTask_GetResult_Request>()
{
  return thor_server::action::builder::Init_PoseTask_GetResult_Request_goal_id();
}

}  // namespace thor_server


namespace thor_server
{

namespace action
{

namespace builder
{

class Init_PoseTask_GetResult_Response_result
{
public:
  explicit Init_PoseTask_GetResult_Response_result(::thor_server::action::PoseTask_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::thor_server::action::PoseTask_GetResult_Response result(::thor_server::action::PoseTask_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::thor_server::action::PoseTask_GetResult_Response msg_;
};

class Init_PoseTask_GetResult_Response_status
{
public:
  Init_PoseTask_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseTask_GetResult_Response_result status(::thor_server::action::PoseTask_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_PoseTask_GetResult_Response_result(msg_);
  }

private:
  ::thor_server::action::PoseTask_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::thor_server::action::PoseTask_GetResult_Response>()
{
  return thor_server::action::builder::Init_PoseTask_GetResult_Response_status();
}

}  // namespace thor_server


namespace thor_server
{

namespace action
{

namespace builder
{

class Init_PoseTask_FeedbackMessage_feedback
{
public:
  explicit Init_PoseTask_FeedbackMessage_feedback(::thor_server::action::PoseTask_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::thor_server::action::PoseTask_FeedbackMessage feedback(::thor_server::action::PoseTask_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::thor_server::action::PoseTask_FeedbackMessage msg_;
};

class Init_PoseTask_FeedbackMessage_goal_id
{
public:
  Init_PoseTask_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseTask_FeedbackMessage_feedback goal_id(::thor_server::action::PoseTask_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_PoseTask_FeedbackMessage_feedback(msg_);
  }

private:
  ::thor_server::action::PoseTask_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::thor_server::action::PoseTask_FeedbackMessage>()
{
  return thor_server::action::builder::Init_PoseTask_FeedbackMessage_goal_id();
}

}  // namespace thor_server

#endif  // THOR_SERVER__ACTION__DETAIL__POSE_TASK__BUILDER_HPP_
