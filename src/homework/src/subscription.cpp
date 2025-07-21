#include "homework/topic_hw.h"

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

sub::sub() : Node("subscriber_node") {  

     // TODO: setup a subscriber and timer for the subscriber
    subscriber_ = this->create_subscription<std_msgs::msg::Int64>(
        "topic_name", 10, std::bind(&sub::topic_callback, this, std::placeholders::_1));
    // The subscriber will call topic_callback whenever a new message is received
    RCLCPP_INFO(this->get_logger(), "Subscriber node initialized and waiting for messages.");
}

void sub::topic_callback(const your_msgs::msg::xxx & msg){

   // TODO: set up the callback function for the subscriber
    RCLCPP_INFO(this->get_logger(), "Received message: '%ld'", msg.data);

}

int main(int argc, char * argv[]){
  
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<sub>());
  rclcpp::shutdown();
  return 0;
}