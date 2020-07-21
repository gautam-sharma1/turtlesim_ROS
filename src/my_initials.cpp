#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include <sstream>

using namespace std;

ros::Publisher velocity_pub;
ros::Publisher velocity_pub1;




void forward(double x);
void turn(double x);



int main(int argc, char **argv)
{
  // Initiate new ROS node named "talker"
  ros::init(argc, argv, "initial");
  ros::NodeHandle n;
  ros::NodeHandle n1;
 

  velocity_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
  velocity_pub1 = n1.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
 

 
  ROS_INFO("\n\n\n******START TESTING************\n");

 
  ros::Rate loop_rate(0.5);
  
  

  ros::Rate loop(0.5);
  
  while(ros::ok()){
  ROS_INFO("\n\n\n******Forward************\n");
  loop.sleep();

  forward(-3);
  loop.sleep();
  ROS_INFO("\n\n\n******Turn************\n");
  turn(-1.57);
  loop.sleep();
  ROS_INFO("\n\n\n******Forward************\n");
  forward(3);  
  loop.sleep();
  ROS_INFO("\n\n\n******Turn************\n");
  turn(1.57);
  loop.sleep();
  ROS_INFO("\n\n\n******Forward************\n");
  forward(3);
  loop.sleep();
  ROS_INFO("\n\n\n******Turn************\n");
  turn(1.57);
  loop.sleep();
  ROS_INFO("\n\n\n******Forward************\n");
  forward(1.5);
  loop.sleep();
  ROS_INFO("\n\n\n******Turn************\n");
  turn(1.57);
  loop.sleep();
  ROS_INFO("\n\n\n******Forward************\n");
  forward(1.5);
  ros::spin();

}
 return 0;
  
}


void forward(double x)
{
  geometry_msgs::Twist vel_msg;
  vel_msg.linear.x =x;
  vel_msg.linear.y =0;
  vel_msg.linear.z =0;
  //set a random angular velocity in the y-axis
  vel_msg.angular.x = 0;
  vel_msg.angular.y = 0;
  vel_msg.angular.z = 0;
  velocity_pub.publish(vel_msg);

}


void turn(double x)
{
  geometry_msgs::Twist vel_msg1;
  vel_msg1.linear.x =0;
  vel_msg1.linear.y =0;
  vel_msg1.linear.z =0;
  //set a random angular velocity in the y-axis
  vel_msg1.angular.x = 0;
  vel_msg1.angular.y = 0;
  vel_msg1.angular.z = x;
  velocity_pub1.publish(vel_msg1);

}


