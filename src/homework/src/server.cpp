#include "homework/service_hw.h"

// TODO: setup a server for the server
server():Node("Server") {
    // 建立 Service 通訊
    // 第一個參數是名稱（跟Topic一樣）, 第二個是bind函式，裡面放要運行的函式，後面照著打就好
    service_ = create_service<Distance>(
    "distance", std::bind(&AddTwoIntsServer::distance_callback, this, _1, _2));
}


// TODO: make the callback function for the server
void distance_callback(const std::shared_ptr<Distance::Request> request,std::shared_ptr<Distance::Response> response) {
  response->dis = sqrt(pow(request->point.x,2)+pow(request->point.y,2));
  RCLCPP_INFO(this->get_logger(), "Request: (%f + %f);Response:%f", request->a, request->b, response->dis);
}

int main(int argc, char **argv){

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<server>());
  rclcpp::shutdown();
  return 0;
}