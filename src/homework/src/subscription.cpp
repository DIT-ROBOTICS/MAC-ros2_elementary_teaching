#include "homework/topic_hw.h"
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"
using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
  public:
    MinimalSubscriber()
    : Node("minimal_subscriber")
    {
      subscription_ = this->create_subscription<std_msgs::msg::Int64>(
      "/topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
      // 初始化"subscrption_":訂閱"test_topic"，訂閱到訊息時進入"MinimalSubscriber::topic_callback"
    }

  private:
    void topic_callback(const std_msgs::msg::Int64::SharedPtr msg) const
    {
      RCLCPP_INFO(this->get_logger(), "%ld", msg->data);
    }
    rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr subscription_; // 宣告"subscription_"
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
