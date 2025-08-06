// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:srv/Distance.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__DISTANCE__BUILDER_HPP_
#define INTERFACES__SRV__DETAIL__DISTANCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/srv/detail/distance__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_Distance_Request_point
{
public:
  Init_Distance_Request_point()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::Distance_Request point(::interfaces::srv::Distance_Request::_point_type arg)
  {
    msg_.point = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::Distance_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::Distance_Request>()
{
  return interfaces::srv::builder::Init_Distance_Request_point();
}

}  // namespace interfaces


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_Distance_Response_dis
{
public:
  Init_Distance_Response_dis()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::Distance_Response dis(::interfaces::srv::Distance_Response::_dis_type arg)
  {
    msg_.dis = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::Distance_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::Distance_Response>()
{
  return interfaces::srv::builder::Init_Distance_Response_dis();
}

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__DISTANCE__BUILDER_HPP_
