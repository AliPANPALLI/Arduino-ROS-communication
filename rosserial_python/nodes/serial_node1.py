#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
#Ali PANPALLI

import rospy
from std_msgs.msg import Int32
from std_msgs.msg import Int8

def callback(msg):
	var=msg.data
	pub = rospy.Publisher('stick',Int8,queue_size=1)
	rate = rospy.Rate(100)
	if var>1450 and var<1550:
		varP=3
		print("ORTA")
	elif var>=1600:
		varP=2
		print("SAG")
	else:
		varP=1
		print("SOL")
	print(varP)
	pub.publish(varP)
	rate.sleep()


rospy.init_node('subscriber',anonymous=True)
rospy.Subscriber('pushed',Int32, callback)
rospy.spin()
