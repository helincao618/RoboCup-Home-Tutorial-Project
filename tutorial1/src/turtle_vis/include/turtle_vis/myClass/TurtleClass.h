#ifndef TURTLECLASS_H
#define TURTLECLASS_H

/*********************************************************************
* ROS INCLUDES
********************************************************************/
#include <ros/ros.h>

#include <std_msgs/String.h>
#include <turtle_vis/DesiredPose.h>
#include <turtle_vis/send_desired_pose.h>

/*********************************************************************
* EIGEN INCLUDES
********************************************************************/
#include <Eigen/Eigen>
#include <Eigen/StdVector>
#include <Eigen/Geometry>
#include <Eigen/Core>

using namespace Eigen;

namespace turtleSpace
{
    class TurtleClass
    {
    public:

				pthread_mutex_t count_mutex;
        
        TurtleClass();
        ~TurtleClass();

	Vector3d turtlePose_g;
	Vector3d turtlePose_desired_g;	
//#>>>>TODO:CREATE A CALLBACK FUNCTION FOR THE TOPIC turtle_vis::DesiredPose (SEE TurtleClass.cpp)
			
	void getPose(const turtle_vis::DesiredPose::ConstPtr &msg);			//#>>>>TODO:CREATE A CALLBACK FUNCTION FOR THE SERVICE turtle_vis::send_desired_pose
	bool getDPose(turtle_vis::send_desired_pose::Request &req,turtle_vis::send_desired_pose::Response &res);
				//#>>>>TODO:CREATE 2 METHODS TO GET THE DESIRED TURTLE POSE AND CURRENT TURTLE POSE 
	Vector3d getLocalPose();
	Vector3d getLocalDesiredPose();
    };


}

#endif // TURTLECLASS_H
