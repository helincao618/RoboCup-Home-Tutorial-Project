#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <geometry_msgs/Twist.h>
#include <std_srvs/Empty.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  ros::init(argc, argv, "navigation_goals");
  ros::NodeHandle n;
  ros::Rate r(60);
  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }
  ros::ServiceClient client_localization = n.serviceClient<std_srvs::Empty>("/global_localization");
  ros::ServiceClient client_clear = n.serviceClient<std_srvs::Empty>("/move_base/clear_costmaps");
  std_srvs::Empty srv;
  ros::Publisher pub=n.advertise<geometry_msgs::Twist>("/mobile_base_controller/cmd_vel",100);
  geometry_msgs::Twist msg;

  client_localization.call(srv);
  double t0 = ros::Time::now().toSec();
  double t1 = ros::Time::now().toSec();
  while(t1<t0+20 && ros::ok())
{	
  msg.linear.x = 0;
  msg.linear.y = 0;
  msg.linear.z = 0;
  msg.angular.x = 0;
  msg.angular.y = 0;
  msg.angular.z = -1;
  pub.publish(msg);
  t1 = ros::Time::now().toSec();
  ros::spinOnce();
}
  client_clear.call(srv);

  move_base_msgs::MoveBaseGoal goal;
while(1)
{
 
  //reference frame is map
  goal.target_pose.header.frame_id = "map";
  //set goal as 2D coordinate
  goal.target_pose.pose.position.x = -3;
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

  return 0;
}
