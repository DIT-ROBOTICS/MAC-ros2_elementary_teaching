#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"
#include "homework/topic_hw.h"

using namespace std::chrono_literals;

pub::pub() : Node("Pub"){
    publisher = this->create_publisher<std_msgs::msg::Int64>("topic",10);
    timer = this->create_wall_timer(500ms,std::bind(&pub::timer_callback,this));
    msg.data = 0;
}

void pub::timer_callback(){
    publisher->publish(msg);
    RCLCPP_INFO(this->get_logger(),"pub:%ld",msg.data);
    msg.data++;
}

int main(int argc, char * argv[]){
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<pub>());
  rclcpp::shutdown();
  return 0;
}

/*
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"
#include "summer_hw1/topic_hw.hpp"

using namespace std::chrono_literals;

Publisher::Publisher():Node("Pub") {
    pub = this->create_publisher<std_msgs::msg::Int64>("topic",10);
    timer = this->create_wall_timer(500ms,std::bind(&Publisher::time,this));
    msg.data = 0;
}
void Publisher::time(){
    pub->publish(msg);
    RCLCPP_INFO(this->get_logger(),"pub:%ld",msg.data);
    msg.data++;
}

int main(int argc,char* argv[]){
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<Publisher>());
    rclcpp::shutdown();
    return 0;
}
*/