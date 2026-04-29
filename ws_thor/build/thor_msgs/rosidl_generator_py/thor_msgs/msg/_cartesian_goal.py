# generated from rosidl_generator_py/resource/_idl.py.em
# with input from thor_msgs:msg/CartesianGoal.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CartesianGoal(type):
    """Metaclass of message 'CartesianGoal'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('thor_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'thor_msgs.msg.CartesianGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cartesian_goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cartesian_goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cartesian_goal
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cartesian_goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cartesian_goal

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CartesianGoal(metaclass=Metaclass_CartesianGoal):
    """Message class 'CartesianGoal'."""

    __slots__ = [
        '_start_pose',
        '_end_pose',
        '_gripperbase_to_armgearright',
        '_max_step',
        '_jump_threshold',
        '_avoid_collisions',
    ]

    _fields_and_field_types = {
        'start_pose': 'geometry_msgs/Pose',
        'end_pose': 'geometry_msgs/Pose',
        'gripperbase_to_armgearright': 'double',
        'max_step': 'double',
        'jump_threshold': 'double',
        'avoid_collisions': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import Pose
        self.start_pose = kwargs.get('start_pose', Pose())
        from geometry_msgs.msg import Pose
        self.end_pose = kwargs.get('end_pose', Pose())
        self.gripperbase_to_armgearright = kwargs.get('gripperbase_to_armgearright', float())
        self.max_step = kwargs.get('max_step', float())
        self.jump_threshold = kwargs.get('jump_threshold', float())
        self.avoid_collisions = kwargs.get('avoid_collisions', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.start_pose != other.start_pose:
            return False
        if self.end_pose != other.end_pose:
            return False
        if self.gripperbase_to_armgearright != other.gripperbase_to_armgearright:
            return False
        if self.max_step != other.max_step:
            return False
        if self.jump_threshold != other.jump_threshold:
            return False
        if self.avoid_collisions != other.avoid_collisions:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def start_pose(self):
        """Message field 'start_pose'."""
        return self._start_pose

    @start_pose.setter
    def start_pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'start_pose' field must be a sub message of type 'Pose'"
        self._start_pose = value

    @builtins.property
    def end_pose(self):
        """Message field 'end_pose'."""
        return self._end_pose

    @end_pose.setter
    def end_pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'end_pose' field must be a sub message of type 'Pose'"
        self._end_pose = value

    @builtins.property
    def gripperbase_to_armgearright(self):
        """Message field 'gripperbase_to_armgearright'."""
        return self._gripperbase_to_armgearright

    @gripperbase_to_armgearright.setter
    def gripperbase_to_armgearright(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gripperbase_to_armgearright' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gripperbase_to_armgearright' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gripperbase_to_armgearright = value

    @builtins.property
    def max_step(self):
        """Message field 'max_step'."""
        return self._max_step

    @max_step.setter
    def max_step(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_step' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'max_step' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._max_step = value

    @builtins.property
    def jump_threshold(self):
        """Message field 'jump_threshold'."""
        return self._jump_threshold

    @jump_threshold.setter
    def jump_threshold(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'jump_threshold' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'jump_threshold' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._jump_threshold = value

    @builtins.property
    def avoid_collisions(self):
        """Message field 'avoid_collisions'."""
        return self._avoid_collisions

    @avoid_collisions.setter
    def avoid_collisions(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'avoid_collisions' field must be of type 'bool'"
        self._avoid_collisions = value
