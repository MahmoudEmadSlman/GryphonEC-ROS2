#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to thor_msgs__msg__IKGoal

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IKGoal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub pose: geometry_msgs::msg::Pose,


    // This member is not documented.
    #[allow(missing_docs)]
    pub gripperbase_to_armgearright: f64,

}



impl Default for IKGoal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::IKGoal::default())
  }
}

impl rosidl_runtime_rs::Message for IKGoal {
  type RmwMsg = super::msg::rmw::IKGoal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Owned(msg.pose)).into_owned(),
        gripperbase_to_armgearright: msg.gripperbase_to_armgearright,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Borrowed(&msg.pose)).into_owned(),
      gripperbase_to_armgearright: msg.gripperbase_to_armgearright,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      pose: geometry_msgs::msg::Pose::from_rmw_message(msg.pose),
      gripperbase_to_armgearright: msg.gripperbase_to_armgearright,
    }
  }
}


// Corresponds to thor_msgs__msg__CartesianGoal

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct CartesianGoal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub start_pose: geometry_msgs::msg::Pose,


    // This member is not documented.
    #[allow(missing_docs)]
    pub end_pose: geometry_msgs::msg::Pose,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::CartesianGoal::default())
  }
}

impl rosidl_runtime_rs::Message for CartesianGoal {
  type RmwMsg = super::msg::rmw::CartesianGoal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        start_pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Owned(msg.start_pose)).into_owned(),
        end_pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Owned(msg.end_pose)).into_owned(),
        gripperbase_to_armgearright: msg.gripperbase_to_armgearright,
        max_step: msg.max_step,
        jump_threshold: msg.jump_threshold,
        avoid_collisions: msg.avoid_collisions,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        start_pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Borrowed(&msg.start_pose)).into_owned(),
        end_pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Borrowed(&msg.end_pose)).into_owned(),
      gripperbase_to_armgearright: msg.gripperbase_to_armgearright,
      max_step: msg.max_step,
      jump_threshold: msg.jump_threshold,
      avoid_collisions: msg.avoid_collisions,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      start_pose: geometry_msgs::msg::Pose::from_rmw_message(msg.start_pose),
      end_pose: geometry_msgs::msg::Pose::from_rmw_message(msg.end_pose),
      gripperbase_to_armgearright: msg.gripperbase_to_armgearright,
      max_step: msg.max_step,
      jump_threshold: msg.jump_threshold,
      avoid_collisions: msg.avoid_collisions,
    }
  }
}


