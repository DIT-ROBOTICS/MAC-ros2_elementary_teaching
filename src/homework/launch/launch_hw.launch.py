from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='homework',
            executable='Client',
            name='Chassis',
            output='screen'
        ),
        Node(
            package='homework',
            executable='Server',
            name='Tower',
            output='screen'
        ),
        Node(
            package='homework',
            executable='Publisher',
            name='publisher',
            output='screen',
            remappings=[('/topic', '/number')]
        ),
        Node(
            package='homework',
            executable='Subscriber',
            name='subscription',
            output='screen',
            remappings=[('/topic', '/number')]
        ),
    ])
