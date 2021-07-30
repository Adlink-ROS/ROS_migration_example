# ROS 2 needs higher version of cmake
cmake_minimum_required(VERSION 2.8.3)  # ROS 1
#cmake_minimum_required(VERSION 3.5)   # ROS 2
project(migration_example)

# ROS 2 use C++ 14, so needs to assign C++ version
#if(NOT CMAKE_CXX_STANDARD)
#  set(CMAKE_CXX_STANDARD 14)
#endif()
#if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#  add_compile_options(-Wall -Wextra -Wpedantic)
#endif()

# ROS 2 needs different packages
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs)
#find_package(ament_cmake REQUIRED)
#find_package(rclcpp REQUIRED)
#find_package(std_msgs REQUIRED)

# ROS 2 don't use catkin_package and add ament_package at the bottom of the file
catkin_package()

# Different include path
include_directories(${catkin_INCLUDE_DIRS})
#include_directories(include ${Boost_INCLUDE_DIRS})

add_executable(talker talker.cpp)

# Use ament_target_dependencies to link libraries
target_link_libraries(talker ${catkin_LIBRARIES})
#ament_target_dependencies(talker
#  rclcpp
#  std_msgs)

# Use different install path
install(TARGETS talker
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
#install(TARGETS talker
#  DESTINATION lib/${PROJECT_NAME})

# Optional: export header for downstream package
#install(DIRECTORY include/
#  DESTINATION include)
#ament_export_include_directories(include)

# Option: export dependencies for downstream package
#ament_export_dependencies(std_msgs)

# ROS 2 needs this
#ament_package()
