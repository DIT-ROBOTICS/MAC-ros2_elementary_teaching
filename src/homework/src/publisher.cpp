#include "homework/topic_hw.h"

namespace homework
{
    // call the constructor and set the name of node
    PublisherNode::PublisherNode() : Node("Publisher"), count_(0)
    {   
        // 建立 publisher
        publisher_ = create_publisher<std_msgs::msg::Int64>("/topic", 10);
        
        // 建立 timer，每 0.5 秒執行一次
        timer_ = create_wall_timer(
            500ms,
            std::bind(&PublisherNode::timer_callback, this)
        );
    }
}

void homework::PublisherNode::timer_callback()
{
    std_msgs::msg::Int64 msg;
    msg.data = count_++;
    //print message
    RCLCPP_INFO(get_logger(), "Publisher: %ld", msg.data);
    // 把資料送到topic subscriber
    publisher_->publish(msg);
}

int main(int argc, char * argv[])
{   
    rclcpp::init(argc, argv); // 初始化 ROS
    // 開始處理timer, callback......
    rclcpp::spin(std::make_shared<homework::PublisherNode>());
    rclcpp::shutdown(); // 結束後關閉ROS
    return 0;
}