cmake_minimum_required(VERSION 3.8)
project(homework)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# TODO: include interfaces files' directories
find_package(interfaces REQUIRED)


# TODO: include header files' directories
include_directories(include)


# TODO: add_executable for each node
add_executable(publisher src/publisher.cpp)
ament_target_dependencies( publisher
  rclcpp
  std_msgs
)
add_executable(subscription src/subscription.cpp)
ament_target_dependencies( subscription
  rclcpp
  std_msgs
)
add_executable(client src/client.cpp)
ament_target_dependencies( client
  rclcpp
  std_msgs
  geometry_msgs
  interfaces
)
add_executable(server src/server.cpp)
ament_target_dependencies( server
  rclcpp
  std_msgs
  geometry_msgs
  interfaces
)


install(TARGETS
  # TODO: add each executable target here
  publisher
  subscription
  client
  server
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY
  include/
  DESTINATION include/
)

# TODO: install launch file directory

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
