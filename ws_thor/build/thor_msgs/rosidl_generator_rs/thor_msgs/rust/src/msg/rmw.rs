#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "thor_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__thor_msgs__msg__IKGoal() -> *const std::ffi::c_void;
}

#[link(name = "thor_msgs__rosidl_generator_c")]
extern "C" {
    fn thor_msgs__msg__IKGoal__init(msg: *mut IKGoal) -> bool;
    fn thor_msgs__msg__IKGoal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<IKGoal>, size: usize) -> bool;
    fn thor_msgs__msg__IKGoal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<IKGoal>);
    fn thor_msgs__msg__IKGoal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<IKGoal>, out_seq: *mut rosidl_runtime_rs::Sequence<IKGoal>) -> bool;
}

// Corresponds to thor_msgs__msg__IKGoal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IKGoal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub pose: geometry_msgs::msg::rmw::Pose,


    // This member is not documented.
    #[allow(missing_docs)]
    pub gripperbase_to_armgearright: f64,

}



impl Default for IKGoal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !thor_msgs__msg__IKGoal__init(&mut msg as *mut _) {
        panic!("Call to thor_msgs__msg__IKGoal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for IKGoal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { thor_msgs__msg__IKGoal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { thor_msgs__msg__IKGoal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { thor_msgs__msg__IKGoal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for IKGoal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for IKGoal where Self: Sized {
  const TYPE_NAME: &'static str = "thor_msgs/msg/IKGoal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__thor_msgs__msg__IKGoal() }
  }
}


#[link(name = "thor_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__thor_msgs__msg__CartesianGoal() -> *const std::ffi::c_void;
}

#[link(name = "thor_msgs__rosidl_generator_c")]
extern "C" {
    fn thor_msgs__msg__CartesianGoal__init(msg: *mut CartesianGoal) -> bool;
    fn thor_msgs__msg__CartesianGoal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<CartesianGoal>, size: usize) -> bool;
    fn thor_msgs__msg__CartesianGoal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<CartesianGoal>);
    fn thor_msgs__msg__CartesianGoal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<CartesianGoal>, out_seq: *mut rosidl_runtime_rs::Sequence<CartesianGoal>) -> bool;
}

// Corresponds to thor_msgs__msg__CartesianGoal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct CartesianGoal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub start_pose: geometry_msgs::msg::rmw::Pose,


    // This member is not documented.
    #[allow(missing_docs)]
    pub end_pose: geometry_msgs::msg::rmw::Pose,


    // This member is not documented.
    #[allow(missing_docs)]
    pub gripperbase_to_armgearright: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub max_step: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub jump_threshold: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub avoid_collisions: bool,

}



impl Default for CartesianGoal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !thor_msgs__msg__CartesianGoal__init(&mut msg as *mut _) {
        panic!("Call to thor_msgs__msg__CartesianGoal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for CartesianGoal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { thor_msgs__msg__CartesianGoal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { thor_msgs__msg__CartesianGoal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { thor_msgs__msg__CartesianGoal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for CartesianGoal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for CartesianGoal where Self: Sized {
  const TYPE_NAME: &'static str = "thor_msgs/msg/CartesianGoal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__thor_msgs__msg__CartesianGoal() }
  }
}


