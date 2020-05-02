cmake_minimum_required(VERSION 2.8.3)
project(pcl_ros_tutorial)

find_package(catkin REQUIRED COMPONENTS
  pcl_ros
  pcl_conversions
  roscpp
  rospy
  sensor_msgs
)
include_directories(
  ${catkin_INCLUDE_DIRS}
)


catkin_package(

)



## Declare a cpp executable
add_executable(pcl_filter_v1 src/pcl_filter_v1.cpp)
add_executable(pcl_filter_v2 src/pcl_filter_v2.cpp)
add_executable(pcl_filter_v3 src/pcl_filter_v3.cpp)
add_executable(pcl_filter_v4 src/pcl_filter_v4.cpp)

target_link_libraries(pcl_filter_v1
   ${catkin_LIBRARIES}
 )
target_link_libraries(pcl_filter_v2
   ${catkin_LIBRARIES}
 )
target_link_libraries(pcl_filter_v3
   ${catkin_LIBRARIES}
 )
target_link_libraries(pcl_filter_v4
   ${catkin_LIBRARIES}
 )

