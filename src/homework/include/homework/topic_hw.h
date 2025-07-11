#pragma once
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

    rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    std_msgs::msg::Int64 msg;
};

class sub : public rclcpp::Node{

  public:
    sub();

  private:
    void topic_callback(const std_msgs::msg::Int64 & msg);
    rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr subscription_;
};