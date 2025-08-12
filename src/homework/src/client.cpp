#include "homework/service_hw.h"

using namespace std::chrono_literals;

Client::Client() : rclcpp::Node("Client"){
    // TODO: setup a the timer and client for the client
    client_ = this->create_client<Distance>("distance");
    timer_  = this->create_wall_timer(500ms, std::bind(&Client::timer_callback, this));
    // Distance::Request->point.x=0.0;
    // Distance::Request->point.y=0.0;
    // timer_ = this->create_wall_timer(500ms, std::bind(&client::timer_callback, this));  
    // while (!client->wait_for_service(std::chrono::secondsxxxx(1))) { ... }
    // timer_ = this->create_wall_timer(500ms, std::bind(&Client::timer_callback, this));
}

// TODO: make the callback and timer function for the client
void Client::handle_callback(rclcpp::Client<Distance>::SharedFuture future){
    try {
        auto resp = future.get();
        RCLCPP_INFO(this->get_logger(), "distance = %.3f", resp->dis);
    } catch (const std::exception &e) {
        RCLCPP_ERROR(this->get_logger(), "failed to get response: %s", e.what());
    }
}

void Client::timer_callback(){
    if (!client_->wait_for_service(100ms)) {
    RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 2000,"service not available, waiting...");
    return;
    }
    auto req = std::make_shared<Distance::Request>();
    req->point.x = x_;
    req->point.y = y_;
    client_->async_send_request(req,std::bind(&Client::handle_callback, this, std::placeholders::_1));
    x_ += 1.0;
    y_ += 2.0;
}

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Client>();
    
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}