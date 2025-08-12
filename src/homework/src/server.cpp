#include "homework/service_hw.h"

using std::placeholders::_1;
using std::placeholders::_2;

// TODO: setup a server for the server
Server::Server() : rclcpp::Node("Server") {
    // 建立 Service 通訊
    // 第一個參數是名稱（跟Topic一樣）, 第二個是bind函式，裡面放要運行的函式，後面照著打就好
    service_ = this->create_service<Distance>("distance", std::bind(&Server::distance_callback, this, _1, _2));
}


// TODO: make the callback function for the server
void Server::distance_callback(const std::shared_ptr<Distance::Request> request,std::shared_ptr<Distance::Response> response) {
  const auto &p = request->point;
  double d =sqrt(pow(request->point.x,2)+pow(request->point.y,2));
  response->dis = static_cast<float>(d);
  RCLCPP_INFO(this->get_logger(), "Request: (x=%.3f , y=%.3f) -> Response:%.3f", p.x, p.y, response->dis);
}

int main(int argc, char **argv){

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Server>());
  rclcpp::shutdown();
  return 0;
}