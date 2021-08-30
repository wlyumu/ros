#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
    //1.ros初始化
    ros::init(argc, argv, "talker");
    //2.消息发布
    ros::NodeHandle n;

    ros::Publisher talker = n.advertise<std_msgs::String>("chatter", 1000);

    ros::Rate loop_rate(1000);

    int count = 0;
    while(ros::ok())
    {
        std_msgs::String msg;
        std::stringstream ss;

        ss << "hello world "<<count;

        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());

        //发布消息
        talker.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
        count++;
    }
    return 0;
}