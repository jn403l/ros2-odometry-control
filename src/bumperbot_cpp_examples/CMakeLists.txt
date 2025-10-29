cmake_minimum_required(VERSION 3.8)
project(bumperbot_cpp_examples LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
# 1) Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rcl_interfaces REQUIRED)

# 2) Targets
add_executable(simple_publisher src/simple_publisher.cpp)
target_compile_features(simple_publisher PUBLIC cxx_std_20)

add_executable(simple_subscriber src/simple_subscriber.cpp)
target_compile_features(simple_subscriber PUBLIC cxx_std_20)

add_executable(simple_parameter src/simple_parameter.cpp)
target_compile_features(simple_parameter PUBLIC cxx_std_20)

# 3) Link ROS deps to target
ament_target_dependencies(simple_publisher rclcpp std_msgs)
ament_target_dependencies(simple_subscriber rclcpp std_msgs)
ament_target_dependencies(simple_parameter rclcpp rcl_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


#find_package(ament_cmake REQUIRED)

install(TARGETS
  simple_publisher
  simple_subscriber
  simple_parameter
  DESTINATION lib/${PROJECT_NAME})

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
