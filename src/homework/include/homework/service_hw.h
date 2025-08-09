//得請教莊大神
//要花點時間讀物件導向
#pragma once
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "interfaces/srv/distance.hpp"

#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <cmath>

//呼叫時會被傳入的第1、2個參數
//placeholder是位置佔位符，一個暫時的空格，之後被呼叫後會有實際參數填入
using std::placeholders::_1;
using std::placeholders::_2;
using namespace std::chrono_literals;

//宣告一個server的class,server是ROS2中的一個節點
class server : public rclcpp::Node{

  //這裡面要放建構子,以下都是公開的
  public:
    server();

  private:
    rclcpp::Service<interfaces::srv::Distance>::SharedPtr service_;//私有變數名稱為service_,型態為前面那一坨（看不懂

    void handle_request( // 當接收到請求時會呼叫這個函式
      const std::shared_ptr<interfaces::srv::Distance::Request> request,//std::shared_ptr指標
      std::shared_ptr<interfaces::srv::Distance::Response> response);
};

class client : public rclcpp::Node{

  public:
    client();

  private:
    void response_callback(rclcpp::Client<interfaces::srv::Distance>::SharedFuture future);

    rclcpp::Client<interfaces::srv::Distance>::SharedPtr client_; // 呼叫服務
    rclcpp::TimerBase::SharedPtr timer_; // 每 0.5 秒觸發

    float x_ = 0.0;
    float y_ = 0.0;

    void send_request(); // 每次 timer 觸發時執行：送出 request
};