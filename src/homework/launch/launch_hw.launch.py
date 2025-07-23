# launch_hw.py
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='homework',
            executable='Client',
            name='Chassis'
        ),
        Node(
            package='homework',
            executable='Server',
            name='Tower'
        ),
        Node(
            package='homework',
            executable='Publisher',
            name='publisher',
            remappings=[('/topic', '/number')]
        ),
        Node(
            package='homework',
            executable='Subscriber',
            name='subscription',
            remappings=[('/topic', '/number')]
        ),
    ])
