#pragma once
// TODO: include message and service type for the service

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

    // TODO: create a server for the service
};

class client : public rclcpp::Node{

  public:
    client();

  private:
    // TODO: define the timer and callback function for the server

    // TODO: create a timer and client for the service
};