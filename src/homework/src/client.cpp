#include "homework/service_hw.h"

using namespace std::chrono_literals;

client::client() : Node("Client"){
    // TODO: setup a the timer and client for the client
    client = node->create_client<Distance>("distance");
    Distance::Request->point.x=0.0;
    Distance::Request->point.y=0.0;
    timer_ = this->create_wall_timer(500ms, std::bind(&client::timer_callback, this));  
    while (!client->wait_for_service(std::chrono::seconds(1))) { ... }
    timer_ = this->create_wall_timer(500ms, std::bind(&Client::timer_callback, this));
}

// TODO: make the callback and timer function for the client
void client::response_cllback(const std::shared_ptr<Distance::Request> request,std::shared_ptr<Distance::Response> response){
    request->point.x+=1.0;
    request->point.y+=2.0;
    RCLCPP_INFO(this->get_logger(), "Response:%f",response->dis);
}

void server::timer_callback(){
    auto result = client->async_send_request(Distance::request,std::bind(&Client::response_callback, this, std::placeholders::_1));
}

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<client>();
    
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}