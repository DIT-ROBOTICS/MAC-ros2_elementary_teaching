#include "homework/service_hw.h"

using namespace std::chrono_literals;

client::client() : Node("Client"){

    client_ = this->create_client<interfaces::srv::Distance>("service");

    timer_ = this->create_wall_timer(500ms,std::bind(&client::timer_callback, this));

    point_.x = 0.0;
    point_.y = 0.0;
}

void client::timer_callback(){
    if (!client_->wait_for_service(1s)){
        RCLCPP_WARN(this->get_logger(), "Service not available, skipping this timer call.");
        return;
    }

    auto request = std::make_shared<interfaces::srv::Distance::Request>();

    request->point.x = point_.x;
    request->point.y = point_.y;

    auto future_result = client_->async_send_request(request,std::bind(&client::response_callback, this, std::placeholders::_1));

    point_.x += 1.0;
    point_.y += 2.0;
}

void client::response_callback(rclcpp::Client<interfaces::srv::Distance>::SharedFuture future){
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