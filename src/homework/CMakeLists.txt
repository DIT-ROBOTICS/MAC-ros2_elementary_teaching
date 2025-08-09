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

# TODO: include interfaces files' directories 我把的interface的package抓來用
find_package(interfaces REQUIRED)

# TODO: include header files' directories
include_directories(
  include
)

# TODO: add_executable for each node

add_executable(publisher src/publisher.cpp) #把 src/publisher.cpp 編譯成一個叫 publisher 的可執行檔
ament_target_dependencies(publisher rclcpp std_msgs) #給這個 publisher 執行檔連接上 rclcpp 和 std_msgs 的函式庫和標頭檔

add_executable(subscriber src/subscription.cpp)
ament_target_dependencies(subscriber rclcpp std_msgs)

# Server Node
add_executable(server src/server.cpp)
ament_target_dependencies(server rclcpp geometry_msgs interfaces)

# Client Node
add_executable(client src/client.cpp)
ament_target_dependencies(client rclcpp geometry_msgs interfaces)

install(TARGETS
  publisher 
  subscriber
  server
  client
  DESTINATION lib/${PROJECT_NAME})

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
