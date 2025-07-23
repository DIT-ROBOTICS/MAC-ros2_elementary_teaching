#pragma once
// TODO: include message type for the topic
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"

#include <chrono>
#include <functional>
#include <memory>
#include <string>

using std::placeholders::_1;
using namespace std::chrono_literals;

class pub : public rclcpp::Node{

  public:
    pub();

  private:
    void timer_callback();

    // TODO: create a publisher and timer for the topic
    rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr Publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    std_msgs::msg::Int64 msg;
};

class sub : public rclcpp::Node{

  public:
    sub();

  private:
    void topic_callback(const std_msgs::msg::Int64 & msg);
    // TODO: create a subscriber for the topic
    rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr Subscription_;
};