#include "ros/ros.h"
#include "geometry_msgs/Point.h"
#include <iostream>

void callback(const geometry_msgs::Point::ConstPtr& msg)
{
  std::cout << "/topic: " << msg->x << " " << msg->y << " " << msg->z << " " << std::endl;
  return;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "converter");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/input", 1000, callback);
  ros::spin();
  return 0;
}

