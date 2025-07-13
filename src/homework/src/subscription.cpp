#include "homework/topic_hw.h"

sub::sub() : Node("TODO: node_name"){  

     // TODO: setup a subscriber and timer for the subscriber
}

void sub::topic_callback(const your_msgs::msg::xxx & msg){

   // TODO: set up the callback function for the subscriber
}

int main(int argc, char * argv[]){
  
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<sub>());
  rclcpp::shutdown();
  return 0;
}