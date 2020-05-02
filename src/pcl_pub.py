#!/usr/bin/env python
import cv2
import os
import rospy
from cv_bridge import CvBridge
from sensor_msgs.msg import Image, PointCloud2
import sensor_msgs.point_cloud2 as pcl2
import numpy as np
from std_msgs.msg import Header

if __name__ == '__main__':
    frame = 0
    rospy.init_node('kitti_node', anonymous=True)
    pcl_pub = rospy.Publisher('kitti_point_cloud', PointCloud2, queue_size=10)


    rate = rospy.Rate(10)

    while not rospy.is_shutdown():
        header = Header()
        header.stamp = rospy.Time.now()
        header.frame_id = 'map'
        point_cloud = np.fromfile(('velodyne_points/data/%010d.bin'%frame), dtype=np.float32).reshape(-1, 4)
        #http://docs.ros.org/melodic/api/sensor_msgs/html/point__cloud2_8py.html
        pcl_pub.publish(pcl2.create_cloud_xyz32(header, point_cloud[:, :3]))
        rospy.loginfo("point cloud published!!!")
        rate.sleep()
        frame +=1
        frame %= 107
