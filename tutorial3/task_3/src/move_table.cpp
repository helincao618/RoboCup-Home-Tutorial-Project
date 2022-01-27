// ROS headers
#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <std_srvs/Empty.h>
#include <actionlib/client/simple_action_client.h>
// MoveIt! headers
#include <moveit/move_group_interface/move_group_interface.h>
#include "move_table/move_table.h"
// Std C++ headers
#include <string>
#include <vector>
#include <map>

using namespace NavigationGoals;

int main(int argc, char** argv)
{
  ros::init(argc, argv, "move_table");
  ros::NodeHandle nh;
  ros::AsyncSpinner spinner(1); 
  ros::Rate r(60);
 
  spinner.start();
  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);
  //rotate
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }
  ros::ServiceClient client_localization = nh.serviceClient<std_srvs::Empty>("/global_localization");
  ros::ServiceClient client_clear = nh.serviceClient<std_srvs::Empty>("/move_base/clear_costmaps");
  std_srvs::Empty srv;
  ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("/mobile_base_controller/cmd_vel",100);
  geometry_msgs::Twist msg;

  client_localization.call(srv);
  double t0 = ros::Time::now().toSec();
  double t1 = ros::Time::now().toSec();
  while(t1<t0+13 && ros::ok())
{	
  msg.linear.x = 0;
  msg.linear.y = 0;
  msg.linear.z = 0;
  msg.angular.x = 0;
  msg.angular.y = 0;
  msg.angular.z = -1.2;
  pub.publish(msg);
  t1 = ros::Time::now().toSec();
  ros::spinOnce();
}
  client_clear.call(srv);
//move to C
  move_base_msgs::MoveBaseGoal goal;
//reference frame is map
  goal.target_pose.header.frame_id = "map";
  //set goal as 2D coordinate
  goal.target_pose.pose.position.x = -1.15;
  goal.target_pose.pose.position.y = -11.6;
  //set goal orientation
  goal.target_pose.pose.orientation.x = 0.0;
  goal.target_pose.pose.orientation.y = 0.0;
  goal.target_pose.pose.orientation.z = 0.7071;
  goal.target_pose.pose.orientation.w = 0.7071;

  ROS_INFO("Sending goal");
  ac.sendGoal(goal);

  ac.waitForResult();

  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, the base reached the destination C");
  else
    ROS_INFO("The base failed to reach the destination for some reason");

//lift the table
  std::map<std::string, double> hold_position;
  std::map<std::string, double> lift_position;
  std::map<std::string, double> start_position;

  hold_position["torso_lift_joint"] = 0.01;
  hold_position["arm_1_joint"] = 0.20;
  hold_position["arm_2_joint"] = -1.50;
  hold_position["arm_3_joint"] = -1.80;
  hold_position["arm_4_joint"] = 2.10;
  hold_position["arm_5_joint"] = -1.29;
  hold_position["arm_6_joint"] = -0.70;
  hold_position["arm_7_joint"] = 0.00;

  lift_position["torso_lift_joint"] = 0.30;
  lift_position["arm_1_joint"] = 0.20;
  lift_position["arm_2_joint"] = -1.30;
  lift_position["arm_3_joint"] = -1.63;
  lift_position["arm_4_joint"] = 2.23;
  lift_position["arm_5_joint"] = -1.29;
  lift_position["arm_6_joint"] = -0.46;
  lift_position["arm_7_joint"] = 0.00;

  start_position["torso_lift_joint"] = 0.1;
  start_position["arm_1_joint"] = 0.20;
  start_position["arm_2_joint"] = -1.34;
  start_position["arm_3_joint"] = -0.20;
  start_position["arm_4_joint"] = 1.93;
  start_position["arm_5_joint"] = -1.57;
  start_position["arm_6_joint"] = 1.37;
  start_position["arm_7_joint"] = 0.00;

  

  //lift the table
  NavigationGoals::armmove(hold_position);
  NavigationGoals::armmove(lift_position);
  NavigationGoals::armmove(hold_position);
  NavigationGoals::armmove(start_position);

//navigate around ABC
while(1)
{
 
  //reference frame is map
  goal.target_pose.header.frame_id = "map";
  //set goal as 2D coordinate
  goal.target_pose.pose.position.x = -3.0;
  goal.target_pose.pose.position.y = -2.4;
  //set goal orientation
  goal.target_pose.pose.orientation.x = 0.0;
  goal.target_pose.pose.orientation.y = 0.0;
  goal.target_pose.pose.orientation.z = 0.0;
  goal.target_pose.pose.orientation.w = 1.0;

  ROS_INFO("Sending goal");
  ac.sendGoal(goal);

  ac.waitForResult();

  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, the base reached the destination A");
  else
    ROS_INFO("The base failed to reach the destination for some reason");

//reference frame is map
  goal.target_pose.header.frame_id = "map";
  //set goal as 2D coordinate
  goal.target_pose.pose.position.x = -3.8;
  goal.target_pose.pose.position.y = -6.2;
  //set goal orientation
  goal.target_pose.pose.orientation.x = 0.0;
  goal.target_pose.pose.orientation.y = 0.0;
  goal.target_pose.pose.orientation.z = 0.9;
  goal.target_pose.pose.orientation.w = 0.0;

  ROS_INFO("Sending goal");
  ac.sendGoal(goal);

  ac.waitForResult();

  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, the base reached the destination B");
  else
    ROS_INFO("The base failed to reach the destination for some reason");

//reference frame is map
  goal.target_pose.header.frame_id = "map";
  //set goal as 2D coordinate
  goal.target_pose.pose.position.x = -1.15;
  goal.target_pose.pose.position.y = -11.8;
  //set goal orientation
  goal.target_pose.pose.orientation.x = 0.0;
  goal.target_pose.pose.orientation.y = 0.0;
  goal.target_pose.pose.orientation.z = 0.7071;
  goal.target_pose.pose.orientation.w = 0.7071;

  ROS_INFO("Sending goal");
  ac.sendGoal(goal);

  ac.waitForResult();

  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, the base reached the destination C");
  else
    ROS_INFO("The base failed to reach the destination for some reason");
  client_clear.call(srv);
}

}
