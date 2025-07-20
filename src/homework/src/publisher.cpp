#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include "homework/topic_hw.h"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"

using namespace std::chrono_literals;


class MinimalPublisher : public rclcpp::Node
{
  public:
    MinimalPublisher()
    : Node("minimal_publisher"), count_(0)
    {
      publisher_ = this->create_publisher<std_msgs::msg::Int64>("/topic", 10);
      // 初始化"publisher_"型態為<std_msgs::msg::String>：發布的topic名為"test_topic"，Buffer=10
      timer_ = this->create_wall_timer(500ms, std::bind(&MinimalPublisher::timer_callback, this));
      // 初始化"timer_":每500ms執行一次"MinimalPublisher::timer_callback"一次
    }

  private:
    void timer_callback()
    {
      auto message = std_msgs::msg::Int64(); // 建立"message"型態為<std_msgs::msg::String>
      message.data = count_++;
      RCLCPP_INFO(this->get_logger(), "%ld", message.data);
      publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_; // 宣告timer_
    rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr publisher_; // 宣告publisher_
    int64_t count_=0; // 宣告count_
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}