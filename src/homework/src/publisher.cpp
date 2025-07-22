#include "homework/topic_hw.h"

pub::pub() : Node("publisher_node"), count_(0) {
    publisher_ = this->create_publisher<std_msgs::msg::Int64>("topic_name", 10);
    // Create a timer that calls the timer_callback function every second
    timer_ = this->create_wall_timer(500ms, std::bind(&pub::timer_callback, this)); 
}

void pub::timer_callback(){
    // TODO: build the callback function for the timer which publishes messages
    auto message = std_msgs::msg::Int64();
    message.data = count_;
    RCLCPP_INFO(this->get_logger(), "Publishing: '%ld'", message.data);
    publisher_->publish(message);
    count_++;
}

int main(int argc, char * argv[]){
  
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<pub>());
  rclcpp::shutdown();
  return 0;
}