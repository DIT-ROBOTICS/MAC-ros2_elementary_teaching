#pragma once
// TODO: include message and service type for the service

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
    // TODO: define the callback function for the server
    void response_callback(
      const std::shared_ptr<interfaces::srv::Distance::Request> request,
      std::shared_ptr<interfaces::srv::Distance::Response> response
    );
    // TODO: create a server for the service
    rclcpp::Service<interfaces::srv::Distance>::SharedPtr server_;
};

class client : public rclcpp::Node{

  public:
    client();

  private:
    // TODO: define the timer and callback function for the server
    void timer_callback();
    // ##
    void response_callback(rclcpp::Client<interfaces::srv::Distance>::SharedFuture future);
    // ##
    // TODO: create a timer and client for the service
    rclcpp::Client<interfaces::srv::Distance>::SharedPtr client_;
    rclcpp::TimerBase::SharedPtr timer_;
    geometry_msgs::msg::Point point_;
};