// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:srv/Distance.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__DISTANCE__STRUCT_HPP_
#define INTERFACES__SRV__DETAIL__DISTANCE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'point'
#include "geometry_msgs/msg/detail/point32__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__interfaces__srv__Distance_Request __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__srv__Distance_Request __declspec(deprecated)
#endif

namespace interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Distance_Request_
{
  using Type = Distance_Request_<ContainerAllocator>;

  explicit Distance_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : point(_init)
  {
    (void)_init;
  }

  explicit Distance_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : point(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _point_type =
    geometry_msgs::msg::Point32_<ContainerAllocator>;
  _point_type point;

  // setters for named parameter idiom
  Type & set__point(
    const geometry_msgs::msg::Point32_<ContainerAllocator> & _arg)
  {
    this->point = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::srv::Distance_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::srv::Distance_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::srv::Distance_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::srv::Distance_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::Distance_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::Distance_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::Distance_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::Distance_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::srv::Distance_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::srv::Distance_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__srv__Distance_Request
    std::shared_ptr<interfaces::srv::Distance_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__srv__Distance_Request
    std::shared_ptr<interfaces::srv::Distance_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Distance_Request_ & other) const
  {
    if (this->point != other.point) {
      return false;
    }
    return true;
  }
  bool operator!=(const Distance_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Distance_Request_

// alias to use template instance with default allocator
using Distance_Request =
  interfaces::srv::Distance_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interfaces


#ifndef _WIN32
# define DEPRECATED__interfaces__srv__Distance_Response __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__srv__Distance_Response __declspec(deprecated)
#endif

namespace interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Distance_Response_
{
  using Type = Distance_Response_<ContainerAllocator>;

  explicit Distance_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dis = 0.0f;
    }
  }

  explicit Distance_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dis = 0.0f;
    }
  }

  // field types and members
  using _dis_type =
    float;
  _dis_type dis;

  // setters for named parameter idiom
  Type & set__dis(
    const float & _arg)
  {
    this->dis = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::srv::Distance_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::srv::Distance_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::srv::Distance_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::srv::Distance_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::Distance_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::Distance_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::Distance_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::Distance_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::srv::Distance_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::srv::Distance_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__srv__Distance_Response
    std::shared_ptr<interfaces::srv::Distance_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__srv__Distance_Response
    std::shared_ptr<interfaces::srv::Distance_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Distance_Response_ & other) const
  {
    if (this->dis != other.dis) {
      return false;
    }
    return true;
  }
  bool operator!=(const Distance_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Distance_Response_

// alias to use template instance with default allocator
using Distance_Response =
  interfaces::srv::Distance_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interfaces

namespace interfaces
{

namespace srv
{

struct Distance
{
  using Request = interfaces::srv::Distance_Request;
  using Response = interfaces::srv::Distance_Response;
};

}  // namespace srv

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__DISTANCE__STRUCT_HPP_
