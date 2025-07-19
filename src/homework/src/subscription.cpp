// #include "homework/topic_hw.h"

// sub::sub() : Node("TODO: node_name"){  

//      // TODO: setup a subscriber and timer for the subscriber
// }

// void sub::topic_callback(const your_msgs::msg::xxx & msg){

//    // TODO: set up the callback function for the subscriber
// }

// int main(int argc, char * argv[]){
  
//   rclcpp::init(argc, argv);
//   rclcpp::spin(std::make_shared<sub>());
//   rclcpp::shutdown();
//   return 0;
// }

#include "homework/topic_hw.h"

sub::sub() : Node("Subscriber") {
    subscription_ = this->create_subscription<std_msgs::msg::Int64>(
        "/topic", 10, std::bind(&sub::topic_callback, this, _1));
}

void sub::topic_callback(const std_msgs::msg::Int64 & msg) {
    RCLCPP_INFO(this->get_logger(), "Received: '%ld'", msg.data);
}

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<sub>());
    rclcpp::shutdown();
    return 0;
}
