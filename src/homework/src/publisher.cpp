#include "homework/topic_hw.h"

pub::pub() : Node("Publisher_Node"){
    // TODO: setup a publisher and timer for the publisher
    Publisher_ = this->create_publisher<std_msgs::msg::Int64>("topic", 20);
    timer_ = this->create_wall_timer(500ms, std::bind(&pub::timer_callback, this));
    msg.data = 0;  //setup
}

void pub::timer_callback(){
    // TODO: build the callback function for the timer which publishes messages
    RCLCPP_INFO(this->get_logger(), "Pub: '%ld'", msg.data);
    Publisher_->publish(msg);
    msg.data++;
}

int main(int argc, char * argv[]){
  
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<pub>());
  rclcpp::shutdown();
  return 0;
}