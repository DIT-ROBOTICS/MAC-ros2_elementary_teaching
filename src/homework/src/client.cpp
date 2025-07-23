#include "homework/service_hw.h"

using namespace std::chrono_literals;

client::client() : Node("Client_Node"){

    // TODO: setup a the timer and client for the client
    Client_ = this->create_client<interfaces::srv::Distance>("service");

    timer_ = this->create_wall_timer(500ms,std::bind(&client::timer_callback, this));

    point.x = 0.0;
    point.y = 0.0;
}

// TODO: make the callback and timer function for the client
void client::timer_callback(){
    if (!Client_->wait_for_service(5s)){
        RCLCPP_WARN(this->get_logger(), "Waiting for Connect");
        return;
    }

    auto request = std::make_shared<interfaces::srv::Distance::Request>();

    request->point.x = point.x;
    request->point.y = point.y;

    auto result = Client_->async_send_request(request,std::bind(&client::client_callback, this, std::placeholders::_1));

    point.x += 1.0;
    point.y += 2.0;
}

void client::client_callback(rclcpp::Client<interfaces::srv::Distance>::SharedFuture future){
    auto response = future.get();
    RCLCPP_INFO(this->get_logger(), "distance: %lf", response->dis);
}

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<client>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}