// ROS headers
#include <ros/ros.h>

// MoveIt! headers
#include <moveit/move_group_interface/move_group_interface.h>

// Std C++ headers
#include <string>
#include <vector>
#include <map>	

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

namespace NavigationGoals{
     int armmove(std::map<std::string, double> target_position) {
		ros::NodeHandle n;
		ros::AsyncSpinner spinner(1);
		spinner.start();

		std::vector<std::string> torso_arm_joint_names;
	 	//select group of joints
	 	moveit::planning_interface::MoveGroupInterface group_arm_torso("arm_torso");
	 	//choose your preferred planner
		group_arm_torso.setPlannerId("SBLkConfigDefault");

		torso_arm_joint_names = group_arm_torso.getJoints();

	 	group_arm_torso.setStartStateToCurrentState();
		group_arm_torso.setMaxVelocityScalingFactor(1.0);

		for (unsigned int i = 0; i < torso_arm_joint_names.size(); ++i)
			if ( target_position.count(torso_arm_joint_names[i]) > 0 ) {
				ROS_INFO_STREAM("\t" << torso_arm_joint_names[i] << " goal position: " << target_position[torso_arm_joint_names[i]]);
				group_arm_torso.setJointValueTarget(torso_arm_joint_names[i], target_position[torso_arm_joint_names[i]]);
		}

		moveit::planning_interface::MoveGroupInterface::Plan my_plan;
		group_arm_torso.setPlanningTime(5.0);
		bool success = (bool) group_arm_torso.plan(my_plan);

		if (!success) {
			throw std::runtime_error("No Plan Found");
		}

		ROS_INFO_STREAM("Plan found in " << my_plan.planning_time_ << " seconds");

		// Execute the plan
		ros::Time start = ros::Time::now();

		group_arm_torso.move();

		ROS_INFO_STREAM("Motion duration: " << (ros::Time::now() - start).toSec());

		spinner.stop();

		return EXIT_SUCCESS;
	}
}
