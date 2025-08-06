#pragma once
// TODO: include message and service type for the service

#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <cmath>

using Distance = interfaces::srv::Distance;
using std::placeholders::_1;
using std::placeholders::_2;
using namespace std::chrono_literals;

class server : public rclcpp::Node{

  public:
    server();

  private:
    // TODO: define the callback function for the server
    void distance_callback(const std::shared_ptr<Distance::Request> request,std::shared_ptr<Distance::Response> response);
    
    rclcpp::Service<Distance>::SharedPtr service_;
};

class client : public rclcpp::Node{

  public:
    client();

  private:
    // TODO: define the timer and callback function for the server
    void response_callback(const std::shared_ptr<Distance::Request> request,std::shared_ptr<Distance::Response> response);
    void timer_callback();
    rclcpp::Service<Distance>::SharedPtr service_;
    rclcpp::TimerBase::SharedPtr timer_;
    Distance::Request->point.x=0.0;
    Distance::Request->point.y=0.0;
    // TODO: create a timer and client for the service
};