#include "homework/service_hw.h"

server::server() : Node("distance_server"){

   // TODO: setup a server for the server
   server_ = this->create_service<interfaces::srv::Distance>(
    "distance_service", // service name
    std::bind(&server::response_callback, this, _1, _2) //setup callback
   );

   RCLCPP_INFO(this->get_logger(), "Server is ready");
}

// TODO: make the callback function for the server
void server::response_callback(
  const std::shared_ptr<interfaces::srv::Distance::Request> request,
  std::shared_ptr<interfaces::srv::Distance::Response> response)
  {
    float x = request->point.x;
    float y = request->point.y;
    float distance = std::sqrt(x * x + y * y);

    response->dis = distance;

    RCLCPP_INFO(this->get_logger(), "Received point: (%lf, %lf) -> Response: %lf", x, y, distance);
  }

int main(int argc, char **argv){

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<server>());
  rclcpp::shutdown();
  return 0;
}