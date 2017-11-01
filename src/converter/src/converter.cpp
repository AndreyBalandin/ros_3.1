#include "ros/ros.h"
#include "geometry_msgs/Point.h"
#include "visualization_msgs/Marker.h"
#include <iostream>

ros::Publisher pub;

void callback(const geometry_msgs::Point::ConstPtr& msg)
{
  std::cout << "/topic: " << msg->x << " " << msg->y << " " << msg->z << " " << std::endl;

  visualization_msgs::Marker marker;
  marker.pose.position = *msg;
  pub.publish(marker);

  return;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "converter");
  ros::NodeHandle n;
  pub = n.advertise<visualization_msgs::Marker>("/output", 1000);
  ros::Subscriber sub = n.subscribe("/input", 1000, callback);
  ros::spin();
  return 0;
}

