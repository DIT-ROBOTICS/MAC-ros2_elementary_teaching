#include "homework/topic_hw.h"
#include <functional>
 

using std::placeholders::_1;

sub::sub() : Node("Subscriber"){  

    subscription_ = this->create_subscription<std_msgs::msg::Int64>("/topic", 10, std::bind(&sub::topic_callback, this, _1));
}

void sub::topic_callback(const std_msgs::msg::Int64::SharedPtr msg){

    RCLCPP_INFO(this->get_logger(), "Subscribing: '%lld'", static_cast<long long>(msg->data));
}

int main(int argc, char * argv[]){
  
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<sub>());
  rclcpp::shutdown();
  return 0;
}