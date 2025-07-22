#include "homework/service_hw.h"

using namespace std::chrono_literals;
using Distance = interfaces::srv::Distance;

client::client() : Node("Client"){

    // TODO: setup a the timer and client for the client
    point_.x = 0;
    point_.y = 0;
    distance_client_ = this->create_client<Distance>("service");
    // Wait for service to be available before starting timer
    while (!distance_client_->wait_for_service(1s)) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service. Exiting.");
            return;
        }
        RCLCPP_INFO(this->get_logger(), "Distance service not available, waiting again...");
    }
    RCLCPP_INFO(this->get_logger(), "Distance service is available! Starting client...");
    timer_ = this->create_wall_timer(500ms, std::bind(&client::timer_callback, this));
}

// TODO: make the callback and timer function for the client
void client::timer_callback() {
    // Check if service is still available
    if (!distance_client_->service_is_ready()) {
        RCLCPP_WARN(this->get_logger(), "Service is not ready, skipping request...");
        return;
    }
    
    auto request = std::make_shared<interfaces::srv::Distance::Request>();
    request->point.x = point_.x;
    request->point.y = point_.y;
    // callback is called when response is called
    auto result = distance_client_->async_send_request(request, std::bind(&client::response_callback, this, _1));
    /* source code from ROS at https://docs.ros2.org/foxy/api/rclcpp/client_8hpp_source.html
   SharedFuture
   async_send_request(SharedRequest request)
   {
     return async_send_request(request, [](SharedFuture) {});
   }
  
   template<
     typename CallbackT,
     typename std::enable_if<
       rclcpp::function_traits::same_arguments<
         CallbackT,
         CallbackType
       >::value
     >::type * = nullptr
   >
   SharedFuture
   async_send_request(SharedRequest request, CallbackT && cb)
   {
     std::lock_guard<std::mutex> lock(pending_requests_mutex_);
     int64_t sequence_number;
     rcl_ret_t ret = rcl_send_request(get_client_handle().get(), request.get(), &sequence_number);
     if (RCL_RET_OK != ret) {
       rclcpp::exceptions::throw_from_rcl_error(ret, "failed to send request");
     }
  
     SharedPromise call_promise = std::make_shared<Promise>();
     SharedFuture f(call_promise->get_future());
     pending_requests_[sequence_number] =
       std::make_tuple(call_promise, std::forward<CallbackType>(cb), f);
     return f;
   }
  
   template<
     typename CallbackT,
     typename std::enable_if<
       rclcpp::function_traits::same_arguments<
         CallbackT,
         CallbackWithRequestType
       >::value
     >::type * = nullptr
   >
   SharedFutureWithRequest
   async_send_request(SharedRequest request, CallbackT && cb)
   {
     SharedPromiseWithRequest promise = std::make_shared<PromiseWithRequest>();
     SharedFutureWithRequest future_with_request(promise->get_future());
  
     auto wrapping_cb = [future_with_request, promise, request, &cb](SharedFuture future) {
         auto response = future.get();
         promise->set_value(std::make_pair(request, response));
         cb(future_with_request);
       };
  
     async_send_request(request, wrapping_cb);
  
     return future_with_request;
   }
    */
    

}
void client::response_callback(rclcpp::Client<interfaces::srv::Distance>::SharedFuture future) {
    auto response = future.get();
    RCLCPP_INFO(this->get_logger(), "distance: %f", response->dis);
    point_.x += 1;
    point_.y += 2;
}


int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<client>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}