// #include "homework/topic_hw.h"

// pub::pub() : Node("TODO: node_name"){
//     // TODO: setup a publisher and timer for the publisher
// }

// void pub::timer_callback(){
//     // TODO: build the callback function for the timer which publishes messages
// }

// int main(int argc, char * argv[]){
  
//   rclcpp::init(argc, argv);
//   rclcpp::spin(std::make_shared<pub>());
//   rclcpp::shutdown();
//   return 0;
// }

#include "homework/topic_hw.h"

pub::pub() : Node("Publisher") { // 初始化節點名稱
    publisher_ = this->create_publisher<std_msgs::msg::Int64>("/topic", 10); // 建立Publisher，主題為"/topic"，佇列大小為10
    timer_ = this->create_wall_timer(500ms, std::bind(&pub::timer_callback, this)); // 設定定時器，每0.5秒呼叫一次timer_callback()
}

void pub::timer_callback() {
    auto message = std_msgs::msg::Int64(); // 建立訊息物件
    message.data = count_++; // 訊息內容設定為目前計數值後遞增
    RCLCPP_INFO(this->get_logger(), "Publishing: '%ld'", message.data); // 印出目前發送的訊息
    publisher_->publish(message); // 發佈訊息
}

int main(int argc, char * argv[]) { //啟動 ROS node、跑事件迴圈、結束時清理的標準模板
    rclcpp::init(argc, argv); //叫ROS把整個底層 DDS、節點系統都初始化起來
    rclcpp::spin(std::make_shared<pub>());
    rclcpp::shutdown(); //node結束後要清除記憶體、停止 DDS資源、關閉節點
    return 0;
}
