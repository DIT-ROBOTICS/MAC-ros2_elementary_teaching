// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:srv/Distance.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__DISTANCE__STRUCT_H_
#define INTERFACES__SRV__DETAIL__DISTANCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'point'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in srv/Distance in the package interfaces.
typedef struct interfaces__srv__Distance_Request
{
  geometry_msgs__msg__Point point;
} interfaces__srv__Distance_Request;

// Struct for a sequence of interfaces__srv__Distance_Request.
typedef struct interfaces__srv__Distance_Request__Sequence
{
  interfaces__srv__Distance_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__srv__Distance_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Distance in the package interfaces.
typedef struct interfaces__srv__Distance_Response
{
  float dis;
} interfaces__srv__Distance_Response;

// Struct for a sequence of interfaces__srv__Distance_Response.
typedef struct interfaces__srv__Distance_Response__Sequence
{
  interfaces__srv__Distance_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__srv__Distance_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__SRV__DETAIL__DISTANCE__STRUCT_H_
