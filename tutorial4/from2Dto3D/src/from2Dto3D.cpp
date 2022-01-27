#include <ros/ros.h>
#include <from2Dto3D/from2Dto3D.h>

void from2Dto3DSpace::From2Dto3D::processCloud(const sensor_msgs::PointCloud2ConstPtr& pc)
{    
    //#>>>>TODO: store local data copy or shared, depending on the message
    
    pcl::fromROSMsg(*pc,pCloud);
    geometry_msgs::Point coordinate_3d;
    string object;
    ros::param::get("objectname",object);

    ROS_INFO_STREAM(object);
    
    float px,py;

    if (!isnan(boundoryCopy.rect_array[0].id))
    {
      
      for(int i=0;i<boundoryCopy.rect_array.size();i++)
      {
        if(boundoryCopy.rect_array[i].header.frame_id==object)
        {
            px=boundoryCopy.rect_array[i].x+0.5*boundoryCopy.rect_array[i].width;
            py=boundoryCopy.rect_array[i].y+0.5*boundoryCopy.rect_array[i].height;
            coordinate_3d.x=pCloud.at(px,py).x;
            coordinate_3d.y=pCloud.at(px,py).y;
            coordinate_3d.z=pCloud.at(px,py).z;

            for (int j=0;j<100;j++)
            {
                    px=px+0.1;
                    coordinate_3d.x=pCloud.at(px,py).x;
                    coordinate_3d.y=pCloud.at(px,py).y;
                    coordinate_3d.z=pCloud.at(px,py).z;
                    if (!isnan(coordinate_3d.x))
                    {
                            pub_3D.publish(coordinate_3d);

                            ROS_INFO_STREAM("This is a "<<object<<". It's at");
                            ROS_INFO_STREAM(coordinate_3d);
                            j=101;
                            i=1+boundoryCopy.rect_array.size();
                    }

            }

        }
       }                   
        
        

    }
    
    boundoryCopy.rect_array.clear();



}

void from2Dto3DSpace::From2Dto3D::processRect(const perception_msgs::RectArrayConstPtr& r)
{

    //#>>>>TODO: process bounding box and send 3D position to the topic
    // tip: take a look at the pcl::PointXYZRGB structure
    
    
    //ROS_INFO_STREAM("ggggggggggggggggggg");
    for(int i=0;i<r->rect_array.size();i++)
      {
      	boundoryCopy.rect_array.push_back(r->rect_array[i]);
        

      }

}




