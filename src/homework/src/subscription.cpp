#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"
#include "homework/topic_hw.h"

using std::placeholders::_1;

sub::sub() : Node("Sub"){  
    subscriber = this->create_subscription<std_msgs::msg::Int64>("topic",10,std::bind(&sub::topic_callback,this,_1));
}

void sub::topic_callback(const std_msgs::msg::Int64 & msg){
    RCLCPP_INFO(this->get_logger(),"sub:%ld",msg.data);
}

int main(int argc, char * argv[]){
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<sub>());
  rclcpp::shutdown();
  return 0;
}

/*
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"
#include "summer_hw1/topic_hw.hpp"

using std::placeholders::_1;

Subscriber::Subscriber():Node("Sub") {
    sub = this->create_subscription<std_msgs::msg::Int64>("topic",10,std::bind(&Subscriber::time,this,_1));
}
void Subscriber::time(std_msgs::msg::Int64 msg){
    RCLCPP_INFO(this->get_logger(),"sub:%ld",msg.data);
}

int main(int argc,char* argv[]){
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<Subscriber>());
    rclcpp::shutdown();
    return 0;
}
*/