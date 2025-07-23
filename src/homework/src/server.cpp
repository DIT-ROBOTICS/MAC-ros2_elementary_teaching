#include "homework/service_hw.h"

server::server() : Node("Server_Nodes"){

   // TODO: setup a server for the server
   Server_ = this->create_service<interfaces::srv::Distance>("service", std::bind(&server::server_callback, this, _1, _2));
}

// TODO: make the callback function for the server
void server::server_callback(const std::shared_ptr<interfaces::srv::Distance::Request> request,
    std::shared_ptr<interfaces::srv::Distance::Response> response){

    response->dis = std::sqrt(std::pow(request->point.x, 2) + std::pow(request->point.y, 2));  //distance
    RCLCPP_INFO(this->get_logger(), "request: x = %lf" " y = %lf",request->point.x, request->point.y);
    RCLCPP_INFO(this->get_logger(), "response = [%lf]", response->dis);
}

int main(int argc, char **argv){

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<server>());
  rclcpp::shutdown();
  return 0;
}