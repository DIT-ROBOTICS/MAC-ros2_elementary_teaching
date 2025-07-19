#include "homework/topic_hw.h"

pub::pub() : Node("Publisher"){
    // TODO: setup a publisher and timer for the publisher
    int_pub_ = this->create_publisher<std_msgs::msg::Int64>("/topic", 10);
    timer_ = this->create_wall_timer(500ms, std::bind(&pub::timer_callback, this));
    counter = 0;
}

void pub::timer_callback(){
    // TODO: build the callback function for the timer which publishes messages
    auto msg = std_msgs::msg::Int64();
    msg.data = counter;
    int_pub_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "Publishing /counter: %d", counter);
    counter++;
}

int main(int argc, char * argv[]){
  
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<pub>());
  rclcpp::shutdown();
  return 0;
}