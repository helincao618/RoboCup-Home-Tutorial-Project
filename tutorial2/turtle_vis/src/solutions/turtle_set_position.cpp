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
* EIGEN INCLUDES
********************************************************************/
#include <Eigen/Eigen>
#include <Eigen/StdVector>
#include <Eigen/Geometry>
#include <Eigen/Core>

/*********************************************************************
 * SEVICES AND MESSAGES
 * ******************************************************************/
//SET HEADERS FOR THE SERVICE AND THE MESSAGES OF THE TURTLE_VIS PACKAGE
#include <turtle_vis/myClass/TurtleClass.h>
#include <vector>
using namespace Eigen;


int main(int argc, char** argv)
{

    ros::init(argc, argv, "turtle_set_position",ros::init_options::AnonymousName);

    ROS_INFO_STREAM("**Client tiago desired position");

    ros::NodeHandle n;
    ros::Rate r(60);

    //INITIALIZE THE CLIENT
    ros::ServiceClient client=n.serviceClient<turtle_vis::send_desired_pose>("TiagoPose");/*//#>>>>TODO: DEFINE THE SERVICE TYPE*/

    ////#>>>>TODO: DEFINE A MSG VARIABLE FOR THE SERVICE MESSAGE
    turtle_vis::send_desired_pose srv;

    float x;
    float y;	
	
    //static tf::TransformBroadcaster br;
    //tf::Transform transform;
    //tf::Quaternion qtf;

    while(ros::ok())
    {

        std::vector<double> vals;

        ROS_INFO_STREAM("Give me the desired position of the tiago: x,y");
        //std::cin>>myString;

        ////#>>>>TODO:GET THE VALUES FROM THE TERMINAL AND SAVE THEM IN A LOCAL VARIABLE. YOU WILL GET X,Y AND THETA
	std::cin>>x>>y;
	vals.push_back(x);
	vals.push_back(y);
	//vals.push_back(theta);
        ////#>>>>TODO:CREATE THE MESSAGE WITH THE LOCAL VARIABLE
        srv.request.x = vals[0];
        srv.request.y = vals[1];
        //srv.request.theta = vals[2];
        ////#>>>>TODO:COMPUTE THE POSITION AND ORIENTATION OF THE TF FOR THE DESIRED POSITION
        //qtf.setRPY(0,0,srv.request.theta);////#>>>>TODO:USE THETA VARIABLE
        //transform.setOrigin(tf::Vector3(srv.request.x, srv.request.x, 0));/*//#>>>>TODO:USE X VARIABLE*//*//#>>>>TODO:USE Y VARIABLE*/
        //transform.setRotation(qtf);

        //br.sendTransform(tf::StampedTransform(transform,ros::Time::now(),"/world","/turtle_desired"));


        if(client.call(srv))//#>>>>TODO:CALL THE CLIENT WITH msg
        {
            //#>>>>TODO:PLOT THE MESSAGE
	    ROS_INFO("Reply: %ld", (long int)srv.response.reply);
	    ROS_INFO("x=%f, y=%f", srv.request.x, srv.request.y);
        }
        else
        {
            ROS_ERROR_STREAM("Failed to call the service 'TiagoPose'");
            return 1;
        }

    }



    return 0;
}
