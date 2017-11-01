#include "ros/ros.h"
#include "geometry_msgs/Point.h"
#include "visualization_msgs/Marker.h"
#include <iostream>


class SubscribeAndPublish
{
public:
  SubscribeAndPublish()
  {
    // topic to publish
    pub_ = n_.advertise<visualization_msgs::Marker>("/output", 1);
    // topic to subscribe
    sub_ = n_.subscribe("/input", 1, &SubscribeAndPublish::callback, this);
  }

  void callback(const geometry_msgs::Point::ConstPtr& input)
  {
    // test output
    std::cout << "/topic: " << input->x << " " << input->y << " " << input->z << " " << std::endl;

    // convert geometry_msgs::Point --> visualization_msgs::Marker
    visualization_msgs::Marker output;
    output.pose.position = *input;

    pub_.publish(output);
  }

private:
  ros::NodeHandle n_;
  ros::Publisher pub_;
  ros::Subscriber sub_;

};//End of class SubscribeAndPublish


int main(int argc, char **argv)
{
  //Initiate ROS
  ros::init(argc, argv, "converter");

  //Create an object of class SubscribeAndPublish that will take care of everything
  SubscribeAndPublish SAPObject;

  ros::spin();

  return 0;
}
