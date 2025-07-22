#include "homework/service_hw.h"


server::server() : Node("Server"){
   // TODO: setup a server for the server
   distance_server_ = this->create_service<interfaces::srv::Distance>("service",
                             std::bind(&server::count_dist, this, _1, _2));
}


// TODO: make the callback function for the server
void server::count_dist( const std::shared_ptr<interfaces::srv::Distance::Request> request,
                           std::shared_ptr<interfaces::srv::Distance::Response> response ) {
  response->dis = sqrt(request->point.x*request->point.x + request->point.y*request->point.y);
  RCLCPP_INFO(this->get_logger(), "Sending Response->dis: %lf", response->dis);
}

int main(int argc, char **argv){

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<server>());
  rclcpp::shutdown();
  return 0;
}