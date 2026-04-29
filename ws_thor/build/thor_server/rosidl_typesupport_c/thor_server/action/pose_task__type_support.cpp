// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from thor_server:action/PoseTask.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "thor_server/action/detail/pose_task__struct.h"
#include "thor_server/action/detail/pose_task__type_support.h"
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

typedef struct _PoseTask_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseTask_Goal_type_support_ids_t;

static const _PoseTask_Goal_type_support_ids_t _PoseTask_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PoseTask_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseTask_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseTask_Goal_type_support_symbol_names_t _PoseTask_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, thor_server, action, PoseTask_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, thor_server, action, PoseTask_Goal)),
  }
};

typedef struct _PoseTask_Goal_type_support_data_t
{
  void * data[2];
} _PoseTask_Goal_type_support_data_t;

static _PoseTask_Goal_type_support_data_t _PoseTask_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseTask_Goal_message_typesupport_map = {
  2,
  "thor_server",
  &_PoseTask_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_PoseTask_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_PoseTask_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseTask_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseTask_Goal_message_typesupport_map),
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
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, thor_server, action, PoseTask_Goal)() {
  return &::thor_server::action::rosidl_typesupport_c::PoseTask_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__type_support.h"
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

typedef struct _PoseTask_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseTask_Result_type_support_ids_t;

static const _PoseTask_Result_type_support_ids_t _PoseTask_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PoseTask_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseTask_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseTask_Result_type_support_symbol_names_t _PoseTask_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, thor_server, action, PoseTask_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, thor_server, action, PoseTask_Result)),
  }
};

typedef struct _PoseTask_Result_type_support_data_t
{
  void * data[2];
} _PoseTask_Result_type_support_data_t;

static _PoseTask_Result_type_support_data_t _PoseTask_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseTask_Result_message_typesupport_map = {
  2,
  "thor_server",
  &_PoseTask_Result_message_typesupport_ids.typesupport_identifier[0],
  &_PoseTask_Result_message_typesupport_symbol_names.symbol_name[0],
  &_PoseTask_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseTask_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseTask_Result_message_typesupport_map),
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
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, thor_server, action, PoseTask_Result)() {
  return &::thor_server::action::rosidl_typesupport_c::PoseTask_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__type_support.h"
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

typedef struct _PoseTask_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseTask_Feedback_type_support_ids_t;

static const _PoseTask_Feedback_type_support_ids_t _PoseTask_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PoseTask_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseTask_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseTask_Feedback_type_support_symbol_names_t _PoseTask_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, thor_server, action, PoseTask_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, thor_server, action, PoseTask_Feedback)),
  }
};

typedef struct _PoseTask_Feedback_type_support_data_t
{
  void * data[2];
} _PoseTask_Feedback_type_support_data_t;

static _PoseTask_Feedback_type_support_data_t _PoseTask_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseTask_Feedback_message_typesupport_map = {
  2,
  "thor_server",
  &_PoseTask_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_PoseTask_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_PoseTask_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseTask_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseTask_Feedback_message_typesupport_map),
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
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, thor_server, action, PoseTask_Feedback)() {
  return &::thor_server::action::rosidl_typesupport_c::PoseTask_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__type_support.h"
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

typedef struct _PoseTask_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseTask_SendGoal_Request_type_support_ids_t;

static const _PoseTask_SendGoal_Request_type_support_ids_t _PoseTask_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PoseTask_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseTask_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseTask_SendGoal_Request_type_support_symbol_names_t _PoseTask_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, thor_server, action, PoseTask_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, thor_server, action, PoseTask_SendGoal_Request)),
  }
};

typedef struct _PoseTask_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _PoseTask_SendGoal_Request_type_support_data_t;

static _PoseTask_SendGoal_Request_type_support_data_t _PoseTask_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseTask_SendGoal_Request_message_typesupport_map = {
  2,
  "thor_server",
  &_PoseTask_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_PoseTask_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_PoseTask_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseTask_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseTask_SendGoal_Request_message_typesupport_map),
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
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, thor_server, action, PoseTask_SendGoal_Request)() {
  return &::thor_server::action::rosidl_typesupport_c::PoseTask_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__type_support.h"
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

typedef struct _PoseTask_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseTask_SendGoal_Response_type_support_ids_t;

static const _PoseTask_SendGoal_Response_type_support_ids_t _PoseTask_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PoseTask_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseTask_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseTask_SendGoal_Response_type_support_symbol_names_t _PoseTask_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, thor_server, action, PoseTask_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, thor_server, action, PoseTask_SendGoal_Response)),
  }
};

typedef struct _PoseTask_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _PoseTask_SendGoal_Response_type_support_data_t;

static _PoseTask_SendGoal_Response_type_support_data_t _PoseTask_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseTask_SendGoal_Response_message_typesupport_map = {
  2,
  "thor_server",
  &_PoseTask_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_PoseTask_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_PoseTask_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseTask_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseTask_SendGoal_Response_message_typesupport_map),
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
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, thor_server, action, PoseTask_SendGoal_Response)() {
  return &::thor_server::action::rosidl_typesupport_c::PoseTask_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__type_support.h"
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

typedef struct _PoseTask_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseTask_SendGoal_type_support_ids_t;

static const _PoseTask_SendGoal_type_support_ids_t _PoseTask_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PoseTask_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseTask_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseTask_SendGoal_type_support_symbol_names_t _PoseTask_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, thor_server, action, PoseTask_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, thor_server, action, PoseTask_SendGoal)),
  }
};

typedef struct _PoseTask_SendGoal_type_support_data_t
{
  void * data[2];
} _PoseTask_SendGoal_type_support_data_t;

static _PoseTask_SendGoal_type_support_data_t _PoseTask_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseTask_SendGoal_service_typesupport_map = {
  2,
  "thor_server",
  &_PoseTask_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_PoseTask_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_PoseTask_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t PoseTask_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseTask_SendGoal_service_typesupport_map),
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
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, thor_server, action, PoseTask_SendGoal)() {
  return &::thor_server::action::rosidl_typesupport_c::PoseTask_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__type_support.h"
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

typedef struct _PoseTask_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseTask_GetResult_Request_type_support_ids_t;

static const _PoseTask_GetResult_Request_type_support_ids_t _PoseTask_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PoseTask_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseTask_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseTask_GetResult_Request_type_support_symbol_names_t _PoseTask_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, thor_server, action, PoseTask_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, thor_server, action, PoseTask_GetResult_Request)),
  }
};

typedef struct _PoseTask_GetResult_Request_type_support_data_t
{
  void * data[2];
} _PoseTask_GetResult_Request_type_support_data_t;

static _PoseTask_GetResult_Request_type_support_data_t _PoseTask_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseTask_GetResult_Request_message_typesupport_map = {
  2,
  "thor_server",
  &_PoseTask_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_PoseTask_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_PoseTask_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseTask_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseTask_GetResult_Request_message_typesupport_map),
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
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, thor_server, action, PoseTask_GetResult_Request)() {
  return &::thor_server::action::rosidl_typesupport_c::PoseTask_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__type_support.h"
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

typedef struct _PoseTask_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseTask_GetResult_Response_type_support_ids_t;

static const _PoseTask_GetResult_Response_type_support_ids_t _PoseTask_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PoseTask_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseTask_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseTask_GetResult_Response_type_support_symbol_names_t _PoseTask_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, thor_server, action, PoseTask_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, thor_server, action, PoseTask_GetResult_Response)),
  }
};

typedef struct _PoseTask_GetResult_Response_type_support_data_t
{
  void * data[2];
} _PoseTask_GetResult_Response_type_support_data_t;

static _PoseTask_GetResult_Response_type_support_data_t _PoseTask_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseTask_GetResult_Response_message_typesupport_map = {
  2,
  "thor_server",
  &_PoseTask_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_PoseTask_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_PoseTask_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseTask_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseTask_GetResult_Response_message_typesupport_map),
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
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, thor_server, action, PoseTask_GetResult_Response)() {
  return &::thor_server::action::rosidl_typesupport_c::PoseTask_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__type_support.h"
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

typedef struct _PoseTask_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseTask_GetResult_type_support_ids_t;

static const _PoseTask_GetResult_type_support_ids_t _PoseTask_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PoseTask_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseTask_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseTask_GetResult_type_support_symbol_names_t _PoseTask_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, thor_server, action, PoseTask_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, thor_server, action, PoseTask_GetResult)),
  }
};

typedef struct _PoseTask_GetResult_type_support_data_t
{
  void * data[2];
} _PoseTask_GetResult_type_support_data_t;

static _PoseTask_GetResult_type_support_data_t _PoseTask_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseTask_GetResult_service_typesupport_map = {
  2,
  "thor_server",
  &_PoseTask_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_PoseTask_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_PoseTask_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t PoseTask_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseTask_GetResult_service_typesupport_map),
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
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, thor_server, action, PoseTask_GetResult)() {
  return &::thor_server::action::rosidl_typesupport_c::PoseTask_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__type_support.h"
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

typedef struct _PoseTask_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseTask_FeedbackMessage_type_support_ids_t;

static const _PoseTask_FeedbackMessage_type_support_ids_t _PoseTask_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PoseTask_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseTask_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseTask_FeedbackMessage_type_support_symbol_names_t _PoseTask_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, thor_server, action, PoseTask_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, thor_server, action, PoseTask_FeedbackMessage)),
  }
};

typedef struct _PoseTask_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _PoseTask_FeedbackMessage_type_support_data_t;

static _PoseTask_FeedbackMessage_type_support_data_t _PoseTask_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseTask_FeedbackMessage_message_typesupport_map = {
  2,
  "thor_server",
  &_PoseTask_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_PoseTask_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_PoseTask_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseTask_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseTask_FeedbackMessage_message_typesupport_map),
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
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, thor_server, action, PoseTask_FeedbackMessage)() {
  return &::thor_server::action::rosidl_typesupport_c::PoseTask_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "thor_server/action/pose_task.h"
// already included above
// #include "thor_server/action/detail/pose_task__type_support.h"

static rosidl_action_type_support_t _thor_server__action__PoseTask__typesupport_c;

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, thor_server, action, PoseTask)()
{
  // Thread-safe by always writing the same values to the static struct
  _thor_server__action__PoseTask__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, thor_server, action, PoseTask_SendGoal)();
  _thor_server__action__PoseTask__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, thor_server, action, PoseTask_GetResult)();
  _thor_server__action__PoseTask__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _thor_server__action__PoseTask__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, thor_server, action, PoseTask_FeedbackMessage)();
  _thor_server__action__PoseTask__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_thor_server__action__PoseTask__typesupport_c;
}

#ifdef __cplusplus
}
#endif
