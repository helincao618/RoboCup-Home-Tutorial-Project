#include <ros/ros.h>
#include <ros/console.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <geometry_msgs/Point.h>
#include <std_msgs/Char.h>

#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/exact_time.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <tf/transform_listener.h>

#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>


#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


// PCL specific includes
#include <pcl_ros/point_cloud.h> // enable pcl publishing
#include <sensor_msgs/PointCloud2.h>

#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl_ros/point_cloud.h>

#include <image_geometry/pinhole_camera_model.h>

#include <perception_msgs/Rect.h>
#include <perception_msgs/RectArray.h>
#include <math.h>

//#>>>>TODO: FIX DEPENDENCIES IN CMakeLists.txt and package.xml (Make sure that everithing compiles in one shot.)

//#>>>>TODO: Separate this template in a class library (.h and .cpp files) and an node (.cpp file). The header files must be in a "include" folder in the package.


using namespace std;
using namespace cv;

namespace from2Dto3DSpace
{
class From2Dto3D
{

    private:
      // The node handle
      ros::NodeHandle nh_;
      // Node handle in the private namespace
      ros::NodeHandle priv_nh_;

      //#>>>>TODO: Define publishers and subscribers
      ros::Subscriber sub_bounding;
      ros::Subscriber sub_cloud;
      ros::Publisher pub_3D;
      

      //#>>>>TODO: Define the pointcloud structure and the bounding box local copy
      pcl::PointCloud<pcl::PointXYZRGB> pCloud;
      perception_msgs::RectArray boundoryCopy;
      // A tf transform listener if needed
      tf::TransformListener listener_;
      int flag;

      //------------------ Callbacks -------------------

      // Process clusters
      void processCloud(const sensor_msgs::PointCloud2ConstPtr& pc);
      // Process bounding boxes
      void processRect(const perception_msgs::RectArrayConstPtr & r);


    public:
      // Subscribes to and advertises topics
      From2Dto3D(ros::NodeHandle nh) : nh_(nh), priv_nh_("~")
      {

        //#>>>>TODO: Set publishers and subscribers.
      	
        // subscribers to the bounding boxes and the point cloud
        sub_bounding = nh_.subscribe("rectInfo", 30, &from2Dto3DSpace::From2Dto3D::processRect, this);
        sub_cloud = nh_.subscribe("/xtion/depth_registered/points", 30, &from2Dto3DSpace::From2Dto3D::processCloud, this);

        // Publishers
        pub_3D = nh_.advertise< geometry_msgs::Point >("segmentation/point3D", 30);
        

        ROS_INFO("from2Dto3D initialized ...");

      }

      ~From2Dto3D() {}
};
}
