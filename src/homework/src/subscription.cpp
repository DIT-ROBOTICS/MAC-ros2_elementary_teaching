#include "homework/topic_hw.h"

namespace homework
{
    SubscriberNode::SubscriberNode() : Node("Subscriber")
    {
        subscription_ = create_subscription<std_msgs::msg::Int64>(
            "/topic", 10,
            std::bind(&SubscriberNode::topic_callback, this, std::placeholders::_1)
        );
    }
}

void homework::SubscriberNode::topic_callback(const std_msgs::msg::Int64::SharedPtr msg)
{
    RCLCPP_INFO(get_logger(), "Subscriber: %ld", msg->data);
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<homework::SubscriberNode>());
    rclcpp::shutdown();
    return 0;
}
