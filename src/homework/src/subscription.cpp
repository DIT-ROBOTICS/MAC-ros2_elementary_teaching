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

sub::sub() : Node("Subscriber") { // 初始化節點名稱
    subscription_ = this->create_subscription<std_msgs::msg::Int64>(
        "/topic", 10, std::bind(&sub::topic_callback, this, _1)); // 建立訂閱者，主題為"/topic"，佇列大小為10，並綁定callback函式
}

void sub::topic_callback(const std_msgs::msg::Int64 & msg) { // 訂閱callback實作
    RCLCPP_INFO(this->get_logger(), "Received: '%ld'", msg.data); // 印出接收到的訊息資料
}

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<sub>());
    rclcpp::shutdown();
    return 0;
}
