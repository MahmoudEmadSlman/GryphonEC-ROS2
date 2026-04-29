// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from thor_server:action/PoseTask.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "thor_server/action/detail/pose_task__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace thor_server
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseTask_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseTask_Goal_type_support_ids_t;

static const _PoseTask_Goal_type_support_ids_t _PoseTask_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, thor_server, action, PoseTask_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, thor_server, action, PoseTask_Goal)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseTask_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace thor_server

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<thor_server::action::PoseTask_Goal>()
{
  return &::thor_server::action::rosidl_typesupport_cpp::PoseTask_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, thor_server, action, PoseTask_Goal)() {
  return get_message_type_support_handle<thor_server::action::PoseTask_Goal>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace thor_server
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseTask_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseTask_Result_type_support_ids_t;

static const _PoseTask_Result_type_support_ids_t _PoseTask_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, thor_server, action, PoseTask_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, thor_server, action, PoseTask_Result)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseTask_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace thor_server

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<thor_server::action::PoseTask_Result>()
{
  return &::thor_server::action::rosidl_typesupport_cpp::PoseTask_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, thor_server, action, PoseTask_Result)() {
  return get_message_type_support_handle<thor_server::action::PoseTask_Result>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace thor_server
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseTask_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseTask_Feedback_type_support_ids_t;

static const _PoseTask_Feedback_type_support_ids_t _PoseTask_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, thor_server, action, PoseTask_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, thor_server, action, PoseTask_Feedback)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseTask_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace thor_server

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<thor_server::action::PoseTask_Feedback>()
{
  return &::thor_server::action::rosidl_typesupport_cpp::PoseTask_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, thor_server, action, PoseTask_Feedback)() {
  return get_message_type_support_handle<thor_server::action::PoseTask_Feedback>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace thor_server
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseTask_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseTask_SendGoal_Request_type_support_ids_t;

static const _PoseTask_SendGoal_Request_type_support_ids_t _PoseTask_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, thor_server, action, PoseTask_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, thor_server, action, PoseTask_SendGoal_Request)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseTask_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace thor_server

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<thor_server::action::PoseTask_SendGoal_Request>()
{
  return &::thor_server::action::rosidl_typesupport_cpp::PoseTask_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, thor_server, action, PoseTask_SendGoal_Request)() {
  return get_message_type_support_handle<thor_server::action::PoseTask_SendGoal_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace thor_server
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseTask_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseTask_SendGoal_Response_type_support_ids_t;

static const _PoseTask_SendGoal_Response_type_support_ids_t _PoseTask_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, thor_server, action, PoseTask_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, thor_server, action, PoseTask_SendGoal_Response)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseTask_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace thor_server

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<thor_server::action::PoseTask_SendGoal_Response>()
{
  return &::thor_server::action::rosidl_typesupport_cpp::PoseTask_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, thor_server, action, PoseTask_SendGoal_Response)() {
  return get_message_type_support_handle<thor_server::action::PoseTask_SendGoal_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace thor_server
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseTask_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseTask_SendGoal_type_support_ids_t;

static const _PoseTask_SendGoal_type_support_ids_t _PoseTask_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, thor_server, action, PoseTask_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, thor_server, action, PoseTask_SendGoal)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseTask_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace thor_server

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<thor_server::action::PoseTask_SendGoal>()
{
  return &::thor_server::action::rosidl_typesupport_cpp::PoseTask_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, thor_server, action, PoseTask_SendGoal)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<thor_server::action::PoseTask_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace thor_server
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseTask_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseTask_GetResult_Request_type_support_ids_t;

static const _PoseTask_GetResult_Request_type_support_ids_t _PoseTask_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, thor_server, action, PoseTask_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, thor_server, action, PoseTask_GetResult_Request)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseTask_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace thor_server

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<thor_server::action::PoseTask_GetResult_Request>()
{
  return &::thor_server::action::rosidl_typesupport_cpp::PoseTask_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, thor_server, action, PoseTask_GetResult_Request)() {
  return get_message_type_support_handle<thor_server::action::PoseTask_GetResult_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace thor_server
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseTask_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseTask_GetResult_Response_type_support_ids_t;

static const _PoseTask_GetResult_Response_type_support_ids_t _PoseTask_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, thor_server, action, PoseTask_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, thor_server, action, PoseTask_GetResult_Response)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseTask_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace thor_server

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<thor_server::action::PoseTask_GetResult_Response>()
{
  return &::thor_server::action::rosidl_typesupport_cpp::PoseTask_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, thor_server, action, PoseTask_GetResult_Response)() {
  return get_message_type_support_handle<thor_server::action::PoseTask_GetResult_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace thor_server
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseTask_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseTask_GetResult_type_support_ids_t;

static const _PoseTask_GetResult_type_support_ids_t _PoseTask_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, thor_server, action, PoseTask_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, thor_server, action, PoseTask_GetResult)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseTask_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace thor_server

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<thor_server::action::PoseTask_GetResult>()
{
  return &::thor_server::action::rosidl_typesupport_cpp::PoseTask_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, thor_server, action, PoseTask_GetResult)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<thor_server::action::PoseTask_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "thor_server/action/detail/pose_task__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace thor_server
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseTask_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseTask_FeedbackMessage_type_support_ids_t;

static const _PoseTask_FeedbackMessage_type_support_ids_t _PoseTask_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, thor_server, action, PoseTask_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, thor_server, action, PoseTask_FeedbackMessage)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseTask_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace thor_server

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<thor_server::action::PoseTask_FeedbackMessage>()
{
  return &::thor_server::action::rosidl_typesupport_cpp::PoseTask_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, thor_server, action, PoseTask_FeedbackMessage)() {
  return get_message_type_support_handle<thor_server::action::PoseTask_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "thor_server/action/detail/pose_task__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace thor_server
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t PoseTask_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace thor_server

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<thor_server::action::PoseTask>()
{
  using ::thor_server::action::rosidl_typesupport_cpp::PoseTask_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  PoseTask_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::thor_server::action::PoseTask::Impl::SendGoalService>();
  PoseTask_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::thor_server::action::PoseTask::Impl::GetResultService>();
  PoseTask_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::thor_server::action::PoseTask::Impl::CancelGoalService>();
  PoseTask_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::thor_server::action::PoseTask::Impl::FeedbackMessage>();
  PoseTask_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::thor_server::action::PoseTask::Impl::GoalStatusMessage>();
  return &PoseTask_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(rosidl_typesupport_cpp, thor_server, action, PoseTask)() {
  return ::rosidl_typesupport_cpp::get_action_type_support_handle<thor_server::action::PoseTask>();
}

#ifdef __cplusplus
}
#endif
