#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "ros/console.h"

#include "unistd.h"

using namespace std;

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "cmd_vel_control");

    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1, true);

    ros::Rate rate(60);

    while(ros::ok)
    {
        geometry_msgs::Twist twist;
        geometry_msgs::Vector3 linear;
    }

}