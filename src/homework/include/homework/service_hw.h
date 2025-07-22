#pragma once
// TODO: include message and service type for the service
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32.hpp>
#include <geometry_msgs/msg/point.hpp>
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
    void count_dist( const std::shared_ptr<interfaces::srv::Distance::Request> request,
                           std::shared_ptr<interfaces::srv::Distance::Response> response );


    // TODO: create a server for the service
    rclcpp::Service<interfaces::srv::Distance>::SharedPtr distance_server_;
};

class client : public rclcpp::Node{

  public:
    client();

  private:
    // TODO: define the timer and callback function for the server
    rclcpp::TimerBase::SharedPtr timer_;
    void timer_callback();
    void response_callback(rclcpp::Client<interfaces::srv::Distance>::SharedFuture future);

    // TODO: create a timer and client for the service
    rclcpp::Client<interfaces::srv::Distance>::SharedPtr distance_client_;
    geometry_msgs::msg::Point point_;
};