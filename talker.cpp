#include <sstream>
/*
 * The header for ROS 1 and ROS 2 are different
 * - ROS 1: ends with .h
 * - ROS 2: ends with .hpp
 */
#include "ros/ros.h"              // ROS 1
#include "std_msgs/String.h"      // ROS 1
//#include "rclcpp/rclcpp.hpp"       // ROS 2: Use rclcpp instead of ros
//#include "std_msgs/msg/string.hpp" // ROS 2: Need to add interface type "msg"

int main(int argc, char **argv)
{
/*
 * Different init API
 * - ROS 1: Use ros to init
 * - ROS 2: Use rclcpp to init, and also support "auto", which is keyworld after C++ 14.
 */
  ros::init(argc, argv, "talker");    // ROS 1
  ros::NodeHandle n;                  // ROS 1
  //rclcpp::init(argc, argv);                          // ROS 2
  //auto node = rclcpp::Node::make_shared("talker");   // ROS 2

/*
 * Different publish API
 * - ROS 1: Use advertise to create publisher
 * - ROS 2: Use create_publisher
 */
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);   // ROS 1
  ros::Rate loop_rate(10);                                                       // ROS 1
  //auto chatter_pub = node->create_publisher<std_msgs::msg::String>("chatter", 1000); // ROS 2
  //rclcpp::Rate loop_rate(10);                                                        // ROS 2

  int count = 0;

/*
 * Different namespace
 */
  std_msgs::String msg;      // ROS 1
  //std_msgs::msg::String msg; // ROS 2

/*
 * Different OK
 * - ROS 1: ros::ok
 * - ROS 2: rclcpp::ok
 */
  while (ros::ok())     // ROS 1
  //while (rclcpp::ok())  // ROS 2
  {
    std::stringstream ss;
    ss << "hello world " << count++;
    msg.data = ss.str();

/*
 * Different log function
 * - ROS 1: ROS_INFO(...)
 * - ROS 2: RCLCPP_INFO(node->get_logger(), ...)
 */
    ROS_INFO("%s", msg.data.c_str());  // ROS 1
    //RCLCPP_INFO(node->get_logger(), "%s\n", msg.data.c_str()); // ROS 2

/*
 * chatter_pub in ROS 2 is shared pointer. Need "->"
 */
    chatter_pub.publish(msg);
    //chatter_pub->publish(msg);

/*
 * Different spin
 * - ROS 1: spinOnce
 * - ROS 2: spin_some
 */
    ros::spinOnce();          // ROS 1
    //rclcpp::spin_some(node);  // ROS 2
    loop_rate.sleep();
  }
  return 0;
}
