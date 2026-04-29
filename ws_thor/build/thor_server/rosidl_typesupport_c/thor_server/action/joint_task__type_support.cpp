// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from thor_server:action/JointTask.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "thor_server/action/detail/joint_task__struct.h"
#include "thor_server/action/detail/joint_task__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace thor_server
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _JointTask_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _JointTask_Goal_type_support_ids_t;

static const _JointTask_Goal_type_support_ids_t _JointTask_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _JointTask_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _JointTask_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _JointTask_Goal_type_support_symbol_names_t _JointTask_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, thor_server, action, JointTask_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, thor_server, action, JointTask_Goal)),
  }
};

typedef struct _JointTask_Goal_type_support_data_t
{
  void * data[2];
} _JointTask_Goal_type_support_data_t;

static _JointTask_Goal_type_support_data_t _JointTask_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _JointTask_Goal_message_typesupport_map = {
  2,
  "thor_server",
  &_JointTask_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_JointTask_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_JointTask_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t JointTask_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_JointTask_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace thor_server

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, thor_server, action, JointTask_Goal)() {
  return &::thor_server::action::rosidl_typesupport_c::JointTask_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/joint_task__struct.h"
// already included above
// #include "thor_server/action/detail/joint_task__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace thor_server
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _JointTask_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _JointTask_Result_type_support_ids_t;

static const _JointTask_Result_type_support_ids_t _JointTask_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _JointTask_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _JointTask_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _JointTask_Result_type_support_symbol_names_t _JointTask_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, thor_server, action, JointTask_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, thor_server, action, JointTask_Result)),
  }
};

typedef struct _JointTask_Result_type_support_data_t
{
  void * data[2];
} _JointTask_Result_type_support_data_t;

static _JointTask_Result_type_support_data_t _JointTask_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _JointTask_Result_message_typesupport_map = {
  2,
  "thor_server",
  &_JointTask_Result_message_typesupport_ids.typesupport_identifier[0],
  &_JointTask_Result_message_typesupport_symbol_names.symbol_name[0],
  &_JointTask_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t JointTask_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_JointTask_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace thor_server

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, thor_server, action, JointTask_Result)() {
  return &::thor_server::action::rosidl_typesupport_c::JointTask_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/joint_task__struct.h"
// already included above
// #include "thor_server/action/detail/joint_task__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace thor_server
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _JointTask_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _JointTask_Feedback_type_support_ids_t;

static const _JointTask_Feedback_type_support_ids_t _JointTask_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _JointTask_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _JointTask_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _JointTask_Feedback_type_support_symbol_names_t _JointTask_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, thor_server, action, JointTask_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, thor_server, action, JointTask_Feedback)),
  }
};

typedef struct _JointTask_Feedback_type_support_data_t
{
  void * data[2];
} _JointTask_Feedback_type_support_data_t;

static _JointTask_Feedback_type_support_data_t _JointTask_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _JointTask_Feedback_message_typesupport_map = {
  2,
  "thor_server",
  &_JointTask_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_JointTask_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_JointTask_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t JointTask_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_JointTask_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace thor_server

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, thor_server, action, JointTask_Feedback)() {
  return &::thor_server::action::rosidl_typesupport_c::JointTask_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/joint_task__struct.h"
// already included above
// #include "thor_server/action/detail/joint_task__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace thor_server
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _JointTask_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _JointTask_SendGoal_Request_type_support_ids_t;

static const _JointTask_SendGoal_Request_type_support_ids_t _JointTask_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _JointTask_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _JointTask_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _JointTask_SendGoal_Request_type_support_symbol_names_t _JointTask_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, thor_server, action, JointTask_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, thor_server, action, JointTask_SendGoal_Request)),
  }
};

typedef struct _JointTask_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _JointTask_SendGoal_Request_type_support_data_t;

static _JointTask_SendGoal_Request_type_support_data_t _JointTask_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _JointTask_SendGoal_Request_message_typesupport_map = {
  2,
  "thor_server",
  &_JointTask_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_JointTask_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_JointTask_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t JointTask_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_JointTask_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace thor_server

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, thor_server, action, JointTask_SendGoal_Request)() {
  return &::thor_server::action::rosidl_typesupport_c::JointTask_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/joint_task__struct.h"
// already included above
// #include "thor_server/action/detail/joint_task__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace thor_server
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _JointTask_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _JointTask_SendGoal_Response_type_support_ids_t;

static const _JointTask_SendGoal_Response_type_support_ids_t _JointTask_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _JointTask_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _JointTask_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _JointTask_SendGoal_Response_type_support_symbol_names_t _JointTask_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, thor_server, action, JointTask_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, thor_server, action, JointTask_SendGoal_Response)),
  }
};

typedef struct _JointTask_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _JointTask_SendGoal_Response_type_support_data_t;

static _JointTask_SendGoal_Response_type_support_data_t _JointTask_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _JointTask_SendGoal_Response_message_typesupport_map = {
  2,
  "thor_server",
  &_JointTask_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_JointTask_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_JointTask_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t JointTask_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_JointTask_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace thor_server

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, thor_server, action, JointTask_SendGoal_Response)() {
  return &::thor_server::action::rosidl_typesupport_c::JointTask_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/joint_task__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace thor_server
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _JointTask_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _JointTask_SendGoal_type_support_ids_t;

static const _JointTask_SendGoal_type_support_ids_t _JointTask_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _JointTask_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _JointTask_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _JointTask_SendGoal_type_support_symbol_names_t _JointTask_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, thor_server, action, JointTask_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, thor_server, action, JointTask_SendGoal)),
  }
};

typedef struct _JointTask_SendGoal_type_support_data_t
{
  void * data[2];
} _JointTask_SendGoal_type_support_data_t;

static _JointTask_SendGoal_type_support_data_t _JointTask_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _JointTask_SendGoal_service_typesupport_map = {
  2,
  "thor_server",
  &_JointTask_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_JointTask_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_JointTask_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t JointTask_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_JointTask_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace thor_server

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, thor_server, action, JointTask_SendGoal)() {
  return &::thor_server::action::rosidl_typesupport_c::JointTask_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/joint_task__struct.h"
// already included above
// #include "thor_server/action/detail/joint_task__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace thor_server
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _JointTask_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _JointTask_GetResult_Request_type_support_ids_t;

static const _JointTask_GetResult_Request_type_support_ids_t _JointTask_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _JointTask_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _JointTask_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _JointTask_GetResult_Request_type_support_symbol_names_t _JointTask_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, thor_server, action, JointTask_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, thor_server, action, JointTask_GetResult_Request)),
  }
};

typedef struct _JointTask_GetResult_Request_type_support_data_t
{
  void * data[2];
} _JointTask_GetResult_Request_type_support_data_t;

static _JointTask_GetResult_Request_type_support_data_t _JointTask_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _JointTask_GetResult_Request_message_typesupport_map = {
  2,
  "thor_server",
  &_JointTask_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_JointTask_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_JointTask_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t JointTask_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_JointTask_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace thor_server

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, thor_server, action, JointTask_GetResult_Request)() {
  return &::thor_server::action::rosidl_typesupport_c::JointTask_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/joint_task__struct.h"
// already included above
// #include "thor_server/action/detail/joint_task__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace thor_server
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _JointTask_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _JointTask_GetResult_Response_type_support_ids_t;

static const _JointTask_GetResult_Response_type_support_ids_t _JointTask_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _JointTask_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _JointTask_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _JointTask_GetResult_Response_type_support_symbol_names_t _JointTask_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, thor_server, action, JointTask_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, thor_server, action, JointTask_GetResult_Response)),
  }
};

typedef struct _JointTask_GetResult_Response_type_support_data_t
{
  void * data[2];
} _JointTask_GetResult_Response_type_support_data_t;

static _JointTask_GetResult_Response_type_support_data_t _JointTask_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _JointTask_GetResult_Response_message_typesupport_map = {
  2,
  "thor_server",
  &_JointTask_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_JointTask_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_JointTask_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t JointTask_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_JointTask_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace thor_server

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, thor_server, action, JointTask_GetResult_Response)() {
  return &::thor_server::action::rosidl_typesupport_c::JointTask_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/joint_task__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace thor_server
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _JointTask_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _JointTask_GetResult_type_support_ids_t;

static const _JointTask_GetResult_type_support_ids_t _JointTask_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _JointTask_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _JointTask_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _JointTask_GetResult_type_support_symbol_names_t _JointTask_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, thor_server, action, JointTask_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, thor_server, action, JointTask_GetResult)),
  }
};

typedef struct _JointTask_GetResult_type_support_data_t
{
  void * data[2];
} _JointTask_GetResult_type_support_data_t;

static _JointTask_GetResult_type_support_data_t _JointTask_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _JointTask_GetResult_service_typesupport_map = {
  2,
  "thor_server",
  &_JointTask_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_JointTask_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_JointTask_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t JointTask_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_JointTask_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace thor_server

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, thor_server, action, JointTask_GetResult)() {
  return &::thor_server::action::rosidl_typesupport_c::JointTask_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/joint_task__struct.h"
// already included above
// #include "thor_server/action/detail/joint_task__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace thor_server
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _JointTask_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _JointTask_FeedbackMessage_type_support_ids_t;

static const _JointTask_FeedbackMessage_type_support_ids_t _JointTask_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _JointTask_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _JointTask_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _JointTask_FeedbackMessage_type_support_symbol_names_t _JointTask_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, thor_server, action, JointTask_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, thor_server, action, JointTask_FeedbackMessage)),
  }
};

typedef struct _JointTask_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _JointTask_FeedbackMessage_type_support_data_t;

static _JointTask_FeedbackMessage_type_support_data_t _JointTask_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _JointTask_FeedbackMessage_message_typesupport_map = {
  2,
  "thor_server",
  &_JointTask_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_JointTask_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_JointTask_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t JointTask_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_JointTask_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace thor_server

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, thor_server, action, JointTask_FeedbackMessage)() {
  return &::thor_server::action::rosidl_typesupport_c::JointTask_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "thor_server/action/joint_task.h"
// already included above
// #include "thor_server/action/detail/joint_task__type_support.h"

static rosidl_action_type_support_t _thor_server__action__JointTask__typesupport_c;

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, thor_server, action, JointTask)()
{
  // Thread-safe by always writing the same values to the static struct
  _thor_server__action__JointTask__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, thor_server, action, JointTask_SendGoal)();
  _thor_server__action__JointTask__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, thor_server, action, JointTask_GetResult)();
  _thor_server__action__JointTask__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _thor_server__action__JointTask__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, thor_server, action, JointTask_FeedbackMessage)();
  _thor_server__action__JointTask__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_thor_server__action__JointTask__typesupport_c;
}

#ifdef __cplusplus
}
#endif
