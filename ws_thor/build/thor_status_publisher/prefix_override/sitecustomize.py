import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/salman/GryphonEC-ROS2/ws_thor/install/thor_status_publisher'
