// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:srv/Distance.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__DISTANCE__TRAITS_HPP_
#define INTERFACES__SRV__DETAIL__DISTANCE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/srv/detail/distance__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Distance_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Distance_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Distance_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::srv::Distance_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::srv::Distance_Request & msg)
{
  return interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::srv::Distance_Request>()
{
  return "interfaces::srv::Distance_Request";
}

template<>
inline const char * name<interfaces::srv::Distance_Request>()
{
  return "interfaces/srv/Distance_Request";
}

template<>
struct has_fixed_size<interfaces::srv::Distance_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::srv::Distance_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::srv::Distance_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Distance_Response & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Distance_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Distance_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::srv::Distance_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::srv::Distance_Response & msg)
{
  return interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::srv::Distance_Response>()
{
  return "interfaces::srv::Distance_Response";
}

template<>
inline const char * name<interfaces::srv::Distance_Response>()
{
  return "interfaces/srv/Distance_Response";
}

template<>
struct has_fixed_size<interfaces::srv::Distance_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::srv::Distance_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::srv::Distance_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::Distance>()
{
  return "interfaces::srv::Distance";
}

template<>
inline const char * name<interfaces::srv::Distance>()
{
  return "interfaces/srv/Distance";
}

template<>
struct has_fixed_size<interfaces::srv::Distance>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::srv::Distance_Request>::value &&
    has_fixed_size<interfaces::srv::Distance_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::srv::Distance>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::srv::Distance_Request>::value &&
    has_bounded_size<interfaces::srv::Distance_Response>::value
  >
{
};

template<>
struct is_service<interfaces::srv::Distance>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::srv::Distance_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::srv::Distance_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__SRV__DETAIL__DISTANCE__TRAITS_HPP_
