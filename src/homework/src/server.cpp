#include "homework/service_hw.h"

server::server() : Node("Server"){
   service_ = this->create_service<interfaces::srv::Distance>(
      "calculate_distance",
      std::bind(&server::handle_request, this, std::placeholders::_1, _2));
}

void server::handle_request(
  const std::shared_ptr<interfaces::srv::Distance::Request> request,
  std::shared_ptr<interfaces::srv::Distance::Response> response)
{
  float x = request->point.x;
  float y = request->point.y;

  // 計算平方和的平方根
  response->dis = std::sqrt(x * x + y * y);

  RCLCPP_INFO(this->get_logger(), "Received request: x=%.2f, y=%.2f", x, y);
  RCLCPP_INFO(this->get_logger(), "Sending response: dis=%.2f", response->dis);
}


int main(int argc, char **argv){

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<server>());
  rclcpp::shutdown();
  return 0;
}