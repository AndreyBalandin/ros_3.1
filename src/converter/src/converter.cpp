#include "ros/ros.h"
#include "geometry_msgs/Point.h"
#include "visualization_msgs/Marker.h"


class SubscribeAndPublish
{
public:
  SubscribeAndPublish()
  {
    // topic to publish
    pub = n.advertise<visualization_msgs::Marker>("/output", 1);
    // topic to subscribe
    sub = n.subscribe("/input", 1, &SubscribeAndPublish::callback, this);

    marker_id_counter = 0;
  }

  void callback(const geometry_msgs::Point::ConstPtr& point)
  {
    // convert geometry_msgs::Point --> visualization_msgs::Marker
    visualization_msgs::Marker marker;
    marker.header.frame_id = "frame";
    marker.header.stamp = ros::Time();
    marker.ns = "points";
    marker.id = marker_id_counter;
    marker.type = visualization_msgs::Marker::POINTS;
    marker.action = visualization_msgs::Marker::ADD;
    marker.scale.x = 0.1;
    marker.scale.y = 0.1;
    marker.color.a = 1.0;
    marker.color.r = 0.0;
    marker.color.g = 1.0;
    marker.color.b = 0.0;
    marker.points.push_back(*point);

    // publish new marker
    pub.publish(marker);
    marker_id_counter += 1;
  }

private:
  ros::NodeHandle n;
  ros::Publisher pub;
  ros::Subscriber sub;
  int marker_id_counter;

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
