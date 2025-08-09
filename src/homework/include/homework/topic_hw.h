// #pragma once
// // TODO: include message type for the topic

// #include <chrono>
// #include <functional>
// #include <memory>
// #include <string>

// using std::placeholders::_1;
// using namespace std::chrono_literals;

// class pub : public rclcpp::Node{

//   public:
//     pub();

//   private:
//     void timer_callback();

//     // TODO: create a publisher and timer for the topic
// };

// class sub : public rclcpp::Node{

//   public:
//     sub();

//   private:
//     void topic_callback(const std_msgs::msg::Int64 & msg);
//     // TODO: create a subscriber for the topic
// };

#pragma once

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"

using std::placeholders::_1;
using namespace std::chrono_literals;

class pub : public rclcpp::Node { // Publisher類別，繼承自rclcpp::Node
public:
    pub();

private:
    void timer_callback();
    rclcpp::TimerBase::SharedPtr timer_; // 建立一個Timer，控制每0.5秒執行一次callback
    rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr publisher_; // Publisher物件，發佈整數訊息
    int64_t count_ = 0; // 記錄當前計數值
};

class sub : public rclcpp::Node { // Subscriber類別，繼承自rclcpp::Node
public:
    sub();

private:
    void topic_callback(const std_msgs::msg::Int64 & msg); // Subscription物件，用於接收整數訊息
    rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr subscription_; // callback函式，收到訊息時會印出訊息內容
};
