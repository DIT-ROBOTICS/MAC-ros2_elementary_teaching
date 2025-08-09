#include "homework/service_hw.h"

using namespace std::chrono_literals;//對於timer它會是一種滿方便的寫法，可以直接寫500ms之類的

//建構子是幫你處理好所有設定
client::client() : Node("Client"){//前面是建構子定義，後面是初始化
    client_ = this->create_client<interfaces::srv::Distance>("calculate_distance");

    // 每 0.5 秒呼叫 send_request
    timer_ = this->create_wall_timer(
        500ms,
        std::bind(&client::send_request, this));
}

void client::send_request() {
  if (!client_->wait_for_service(1s)) {
    RCLCPP_WARN(this->get_logger(), "Service not available...");
    return;
  }

  auto request = std::make_shared<interfaces::srv::Distance::Request>();
  request->point.x = x_;
  request->point.y = y_;

  auto future = client_->async_send_request(request, std::bind(&client::response_callback, this, _1));
}

void client::response_callback(rclcpp::Client<interfaces::srv::Distance>::SharedFuture future) {
  auto response = future.get();
  RCLCPP_INFO(this->get_logger(), "distance: %f", response->dis);
  x_ += 1;
  y_ += 2;
}

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<client>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}