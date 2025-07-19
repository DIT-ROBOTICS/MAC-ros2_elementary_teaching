#include "homework/topic_hw.h"

sub::sub() : Node("Subscriber"){  
     // TODO: setup a subscriber and timer for the subscriber
     int_sub_ = this->create_subscription<std_msgs::msg::Int64>("/topic", 10, std::bind(&sub::topic_callback, this, _1));
}

void sub::topic_callback(const std_msgs::msg::Int64 & msg){

   // TODO: set up the callback function for the subscriber
   RCLCPP_INFO(this->get_logger(), "Receiving /counter:%ld", msg.data);
}

int main(int argc, char * argv[]){
  
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<sub>());
  rclcpp::shutdown();
  return 0;
}