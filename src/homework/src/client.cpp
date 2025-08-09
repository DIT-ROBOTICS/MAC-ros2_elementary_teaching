#include "homework/service_hw.h"

using namespace std::chrono_literals;

client::client() : Node("TODO: node_name"){

    // TODO: setup a the timer and client for the client
}

// TODO: make the callback and timer function for the client

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<client>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}