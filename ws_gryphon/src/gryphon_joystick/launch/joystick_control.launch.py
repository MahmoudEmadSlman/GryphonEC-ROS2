import launch
import launch_ros.actions

def generate_launch_description():
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='gryphon_joystick',
            executable='joystick_moveit_controller',
            output='screen',
        ),
    ])