#pragma once

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"
#include <chrono>
#include <functional>
#include <memory>
#include <string>

class pub : public rclcpp::Node{
  public:
    pub();
  private:
    void timer_callback();
    rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr publisher;
    std_msgs::msg::Int64 msg;
    rclcpp::TimerBase::SharedPtr timer;
};

class sub : public rclcpp::Node{
  public:
    sub();
  private:
    void topic_callback(const std_msgs::msg::Int64 & msg);
    rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr subscriber;
};

/*
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"

class Publisher:public rclcpp::Node
{
    public:
        Publisher();
    private:
        void time();
        rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr pub;
        std_msgs::msg::Int64 msg;
        rclcpp::TimerBase::SharedPtr timer;
};

class Subscriber:public rclcpp::Node
{
    public:
        Subscriber();
    private:
        void time(std_msgs::msg::Int64 msg);
        rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr sub;
};
*/