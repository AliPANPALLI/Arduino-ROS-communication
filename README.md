# Arduino-ROS-communication
Communicating 2 different Arduinos via ROS.
## EXECUTE
 After opening it in terminal to our working directory. ROS is started by typing ```roscore``` in our terminal.
 We upload Arduino codes to our arduinos.
 If there are differences in the Arduino ports, make the necessary edits in the ```arduino.launch``` file.
 Run the command ```roslaunch rosserial_python arduino.launch``` in the terminal.
 Run ```rosrun rosserial_python serial_node1.py``` in terminal.
