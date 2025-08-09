#include "homework/service_hw.h"

using namespace std::chrono_literals;

client::client() : Node("Client"){
    // TODO: setup a the timer and client for the client
    // 初始化 client，連接到 "calculate_distance" service
    client_ = this->create_client<interfaces::srv::Distance>("calculate_distance");

    // 每 0.5 秒呼叫 send_request
    timer_ = this->create_wall_timer(
        500ms,
        std::bind(&client::send_request, this));
}

// TODO: make the callback and timer function for the client
void client::send_request() {
  // 確保服務已啟動（最多等 1 秒）
  if (!client_->wait_for_service(1s)) {
    RCLCPP_WARN(this->get_logger(), "Service not available...");
    return;
  }

  // 準備 request 內容
  auto request = std::make_shared<interfaces::srv::Distance::Request>();
  request->point.x = x_;
  request->point.y = y_;

  // 非同步送出請求 //future??
  auto future = client_->async_send_request(request, std::bind(&client::response_callback, this, _1));
}
// 當收到回應後執行的 lambda 函數
void client::response_callback(rclcpp::Client<interfaces::srv::Distance>::SharedFuture future) {
  auto response = future.get(); //get??then gpt說get會堵住
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