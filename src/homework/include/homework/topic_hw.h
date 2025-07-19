#pragma once
// TODO: include message type for the topic

// include 需要用到的東東,像是這次用到rclcpp, std_msgs
// rclcpp : 提供ros2的c++節點功能
// std_msgs/msg/Int64 : topic的資料型別
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"

using namespace std::chrono_literals;
// 讓所有的class都在homework下 (homework::下)
namespace homework
{
    // 定義了一個class叫PublisherNode, 這個class是一個node
    class PublisherNode : public rclcpp::Node
    {
        public:
            PublisherNode(); // 用來設定timer, publisher
        
        private:
            // call this function 0.5second a time
            void timer_callback();
            // ros2 timer, 用來週期執行timer_callback()
            rclcpp::TimerBase::SharedPtr timer_;
            // publisher sending topic
            rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr publisher_;
            // 每次遞增的數字
            int64_t count_;
    };

    // recieve topic and print the information of topic
    class SubscriberNode : public rclcpp::Node
    {
        public:
            SubscriberNode();  // constructor

        private:
            // 接收topic時執行
            void topic_callback(const std_msgs::msg::Int64::SharedPtr msg);
            // subscriber
            rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr subscription_;
    };

}  // namespace homework