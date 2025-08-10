#include "homework/service_hw.h"

server::server() : Node("sever_node"){
   // TODO: setup a server for the server
   ser = this->create_service<Distance>("point",std::bind(&server::handle_request,this,_1,_2));
}

// TODO: make the callback function for the server
void server::handle_request(const std::shared_ptr<Distance::Request> request,std::shared_ptr<Distance::Response> response){
  const auto &p = request->point;
  float d = std::sqrt(p.x * p.x + p.y * p.y);
  response->dis = d;

  RCLCPP_INFO(this->get_logger(),"Request: x= %.2f y= %.2f\n",p.x,p.y);
};

int main(int argc, char **argv){
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<server>());
  rclcpp::shutdown();
  return 0;
}