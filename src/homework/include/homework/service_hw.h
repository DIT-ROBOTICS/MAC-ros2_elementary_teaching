#pragma once
// TODO: include message and service type for the service


#include "rclcpp/rclcpp.hpp"                  // ROS2 C++ API
#include "geometry_msgs/msg/point.hpp"        // 輸入請求資料類型
#include "interfaces/srv/distance.hpp"          // 自定義的 service 檔案

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
    server(); //建構子：初始話節點與 service

  private:
    // TODO: define the callback function for the server
    // TODO: create a server for the service
    rclcpp::Service<interfaces::srv::Distance>::SharedPtr service_; // 定義 ROS2 的 service 成員

    void handle_request( // 當接收到請求時會呼叫這個函式
      const std::shared_ptr<interfaces::srv::Distance::Request> request,
      std::shared_ptr<interfaces::srv::Distance::Response> response);
};

class client : public rclcpp::Node{

  public:
    client(); // 建構子：初始化節點、建立 timer 與 client

  private:
    // TODO: define the timer and callback function for the server
    void timer_callback();
    void response_callback(rclcpp::Client<interfaces::srv::Distance>::SharedFuture future);

    // TODO: create a timer and client for the service
    rclcpp::Client<interfaces::srv::Distance>::SharedPtr client_; // 呼叫服務
    rclcpp::TimerBase::SharedPtr timer_; // 每 0.5 秒觸發

    float x_ = 0.0;
    float y_ = 0.0;

    void send_request(); // 每次 timer 觸發時執行：送出 request
};