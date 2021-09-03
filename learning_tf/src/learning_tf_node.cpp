#include "ros/ros.h"
#include "tf/transform_broadcaster.h"
#include "turtlesim/Pose.h"

using namespace std;

string  turtle_name;

void poseCb(const turtlesim::PoseConstPtr &msg)
{
    static tf::TransformBroadcaster br;
    tf::Transform transform;
    transform.setOrigin(tf::Vector3(msg->x, msg->y, 0.0));
    tf::Quaternion q;
    q.setRPY(0, 0, msg->theta);
    transform.setRotation(q);
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", turtle_name));
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "tf_test");

    if(argc != 2)
    {
        ROS_ERROR("need turle name as argument");
        return 1;
    }

    turtle_name = argv[1];

    ros::NodeHandle turtle_node;
    ros::Subscriber sub = turtle_node.subscribe(turtle_name+"/pose", 10, &poseCb);

    ros::spin();
    return 0;
}
