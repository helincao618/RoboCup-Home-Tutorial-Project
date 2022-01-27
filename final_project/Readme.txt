/**********************************************************************************************************************/
Needing packages
/**********************************************************************************************************************/
packages:

darknet_ros;

from2Dto3D: 
           transform points of the grasping object(bottle)

ikTiago:
           three services
	   1.ikTiago: open the door a little angle for further operation
           2.openwide:open the door widely
           3.littlemove: tuning the postion

perception_msgs;

perception_tutorials(object_detection,plane_segementation):
           detect object with YOLO

robot_nav_motion:
           the main process and the navigation part
               
tf_tiago;

tiago;

/**********************************************************************************************************************/
Implement the whole process
/**********************************************************************************************************************/

Compile the packages given above in a certain worksapce

1.Change the map to "Y20_final"

$ rosservice call /pal_map_manager/change_map "input: 'Y20_final'"

2.Begin navigation

$ rosrun robot_nav_motion test_nav

When reaching the naviagted goal position 

3. Launch the services in ikTiago 

$ roslaunch ikTiago tiago_arm.launch

4. Run the node to computing handle 3D position

$ rosrun tf_tiago transform1 

5. Launch the node to detect object 

$ roslaunch object_detection recognition.launch

6. Launch the node to get the  3D-position

$ roslaunch from2Dto3D transform.launch

7. Launch the whole process

$ rosrun robot_nav_motion test_arm 



