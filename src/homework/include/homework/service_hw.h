#pragma once

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/point.hpp>
#include "interfaces/srv/distance.hpp"
#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <cmath>
//我的srv是用另一個package：interfaces/srv/Distance.srv

using std::placeholders::_1;
using std::placeholders::_2;
using namespace std::chrono_literals;
using Distance = interfaces::srv::Distance;

class server : public rclcpp::Node{
  public:
    server();
  private:
    void handle_request(const std::shared_ptr<Distance::Request> request,std::shared_ptr<Distance::Response> response);
    rclcpp::Service<Distance>::SharedPtr ser;
};

class client : public rclcpp::Node{
  public:
    client();
  private:
    void timer_callback();
    void handle_response(rclcpp::Client<Distance>::SharedFuture future);
    rclcpp::Client<Distance>::SharedPtr cli;
    rclcpp::TimerBase::SharedPtr timer;
    float x = 0;
    float y = 0;
};