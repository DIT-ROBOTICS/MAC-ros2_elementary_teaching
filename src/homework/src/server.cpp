#include "homework/service_hw.h"

server::server() : Node("TODO: node_name"){

   // TODO: setup a server for the server
}

// TODO: make the callback function for the server

int main(int argc, char **argv){

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<server>());
  rclcpp::shutdown();
  return 0;
}