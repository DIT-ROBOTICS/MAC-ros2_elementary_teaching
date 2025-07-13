#include "homework/topic_hw.h"

pub::pub() : Node("TODO: node_name"){
    // TODO: setup a publisher and timer for the publisher
}

void pub::timer_callback(){
    // TODO: build the callback function for the timer which publishes messages
}

int main(int argc, char * argv[]){
  
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<pub>());
  rclcpp::shutdown();
  return 0;
}