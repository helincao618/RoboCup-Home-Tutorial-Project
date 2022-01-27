/*********************************************************************
* Compiler:         gcc 4.6.3
*
* Company:          Institute for Cognitive Systems
*                   Technical University of Munich
*
* Author:           Emmanuel Dean (dean@tum.de)
*                   Karinne Ramirez (karinne.ramirez@tum.de)
*
* Compatibility:    Ubuntu 12.04 64bit (ros hydro)
*
* Software Version: V0.1
*
* Created:          01.06.2015
*
* Comment:          turtle connection and visualization (Sensor and Signals)
*
********************************************************************/


/*********************************************************************
* STD INCLUDES
********************************************************************/
#include <iostream>
#include <fstream>
#include <pthread.h>
#include <math.h>


/*********************************************************************
* ROS INCLUDES
********************************************************************/
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <tf/transform_listener.h>
#include <tf/transform_broadcaster.h>
#include <tf_conversions/tf_eigen.h>

/*********************************************************************
 * CUSTOM CLASS
 * ******************************************************************/
#include <turtle_vis/myClass/TurtleClass.h>


int main( int argc, char** argv )
{

    ros::init(argc, argv, "turtle_control",ros::init_options::AnonymousName);

    ROS_INFO_STREAM("**Publishing turtle control..");

    ros::NodeHandle n;
    ros::Rate r(60);



    //ADVERTISE THE SERVICE
    turtleSpace::TurtleClass turtleF;
    ros::ServiceServer service=n.advertiseService("TiagoPose",
                                                  &turtleSpace::TurtleClass::getDPose,
                                                  &turtleF);
    

    //ADVERTIZE THE TOPIC
    ros::Publisher pub=n.advertise<geometry_msgs::Twist>("/mobile_base_controller/cmd_vel",100);

    
    //INIT A SUBSCRIBER
    turtleSpace::TurtleClass turtleFunc;
    ros::Subscriber sub=n.subscribe("/mobile_base_controller/odom",100,
                                   &turtleSpace::TurtleClass::getPose,
                                   &turtleFunc);

    //#>>>>TODO: SET GAINS
    //Proportional Gain
    Matrix2d K,dynamic_par;
    Vector3d tiagoPose_local;
    Vector2d tiagoT,tiagoPose_d,tiagoPose_desired_local, error;
    double theta,d;

    //INITIALIZE

    K<<0.5,0,  
       0  ,0.5;
    dynamic_par<<0.0,0.0,
		0.0,0.0;
    tiagoPose_local<<0.0,0.0,0.0;
    tiagoT<<0.0,0.0;
    tiagoPose_d<<0.0,0.0;
    tiagoPose_desired_local<<0.0,0.0;
    error<<0.0,0.0;
    theta = 0.0;
    d = 0.3;

    //CREATE A DESIREDPOSE MSG VARIABLE
    geometry_msgs::Twist msg; //#>>>>TODO:DEFINE THE MSG TYPE

    while(ros::ok())
  
    {
        tiagoPose_desired_local = turtleF.getLocalDesiredPose();
        tiagoPose_local = turtleFunc.getLocalPose();
	theta = tiagoPose_local(2);
        ////#>>>>TODO: Get Desired Pose from the class variable
        
        //CONTROL
        ////#>>>>TODO:COMPUTE THE ERROR BETWEEN CURRENT POSE AND DESIRED
        error(0) = tiagoPose_desired_local(0) - (tiagoPose_local(0)+d*(cos(theta)));
	error(1) = tiagoPose_desired_local(1) - (tiagoPose_local(1)+d*(sin(theta)));
        // COMPUTE THE INCREMENTS
	
        tiagoPose_d = K*error;

        ////#>>>>TODO:COMPUTE THE NEW TURTLE POSE
        dynamic_par<<cos(theta), -d*sin(theta),
                     sin(theta), d*cos(theta);

        tiagoT = dynamic_par.inverse()*tiagoPose_d;//USE SIMPLE INTEGRATION;

        //Publish Data
        ////#>>>>TODO:SET THE MSG VARIABLE WITH THE NEW TURTLE POSE
        msg.linear.x = tiagoT(0);
	msg.linear.y = 0;
	msg.linear.z = 0;
        msg.angular.x = 0;
        msg.angular.y = 0;
        msg.angular.z = tiagoT(1);
        pub.publish(msg);

        

        //ROS::SPIN IS IMPORTANT TO UPDATE ALL THE SERVICES AND TOPICS
        ros::spinOnce();

        r.sleep();
    }

    return 0;
}


