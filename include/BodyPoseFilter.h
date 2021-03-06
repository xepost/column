#ifndef BODYPOSEFILTER_H
#define BODYPOSEFILTER_H

#include <ros/ros.h>
#include <vector>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/TwistStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <tf/transform_datatypes.h>


class BodyPoseFilter{
public:
    BodyPoseFilter(){}
    ~BodyPoseFilter(){}
    /**
    * Returns single best estimate of pose from window of readings with number of outliers as normalized covariance
    * Covariance is row represented
    */
    static geometry_msgs::PoseWithCovarianceStamped ransac(const std::vector<geometry_msgs::PoseStamped> &  reading_vec); 

    /**
    * Returns the pose of the body frame in the AprilTag frame using a better estimate of the orientation from the IMU 
    */
    static geometry_msgs::PoseStamped rotation_invariance_imu(const geometry_msgs::PoseStamped & april_tag_in_camera, 
        const geometry_msgs::PoseStamped & body_pose_in_local);        
};

#endif // BODYPOSEFILTER_H
