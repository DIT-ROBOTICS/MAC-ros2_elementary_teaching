#pragma once
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "std_msgs/msg/float32.hpp"
#include "interfaces/srv/distance.hpp"

#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <cmath>

using std::placeholders::_1;
using std::placeholders::_2;
using namespace std::chrono_literals;

class server : public rclcpp::Node{

  public:
    server();

  private:
    void response_callback(const std::shared_ptr<interfaces::srv::Distance::Request> request,
      std::shared_ptr<interfaces::srv::Distance::Response> response);

    rclcpp::Service<interfaces::srv::Distance>::SharedPtr server_;
};

class client : public rclcpp::Node{

  public:
    client();

  private:
    void timer_callback();
    void response_callback(rclcpp::Client<interfaces::srv::Distance>::SharedFuture future);

    rclcpp::Client<interfaces::srv::Distance>::SharedPtr client_;
    rclcpp::TimerBase::SharedPtr timer_;
    geometry_msgs::msg::Point point_;
};