#include "homework/topic_hw.h"

pub::pub() : Node("Publisher") {
    publisher_ = this->create_publisher<std_msgs::msg::Int64>("/topic", 10);
    timer_ = this->create_wall_timer(500ms, std::bind(&pub::timer_callback, this));
}

void pub::timer_callback() {
    auto message = std_msgs::msg::Int64();
    message.data = count_++;
    RCLCPP_INFO(this->get_logger(), "Publishing: '%ld'", message.data);
    publisher_->publish(message);
}

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<pub>());
    rclcpp::shutdown();
    return 0;
}