#include "homework/service_hw.h"

using namespace std::chrono_literals;

client::client() : Node("client_node"){
    // TODO: setup a the timer and client for the client
    cli = this->create_client<Distance>("point");
    timer = this->create_wall_timer(500ms,std::bind(&client::timer_callback,this));
}

// TODO: make the callback and timer function for the client
void client::timer_callback(){
    auto req = std::make_shared<Distance::Request>();
    req->point.x = x;
    req->point.y = y;

    auto future = cli->async_send_request(req,std::bind(&client::handle_response,this,_1));

    x += 1;
    y += 2;
};

void client::handle_response(rclcpp::Client<Distance>::SharedFuture future){
    auto res = future.get();
    RCLCPP_INFO(this->get_logger(),"Response: %.2f\n",res->dis);
};

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<client>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}