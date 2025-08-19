from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        #hw1的publisher
        Node(
            package="homework",
            executable="Publisher",
            name="Publisher",
            remappings=[("topic","/number")]
        ),
        #hw1的subscriber
        Node(
            package="homework",
            executable="subscriber",
            name="subscriber",
            remappings=[("topic","/number")]
        ),
        #hw2的server
        Node(
            package="homework",
            executable="server",
            name="Tower"
        ),
        #hw2的client
        Node(
            package="homework",
            executable="client",
            name="Chassis"
        )
    ])     


