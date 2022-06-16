
#include <ros.h>
#include <std_msgs/Int32.h>

ros::NodeHandle nh;
int gaz = 0;
int direksiyon = 0;
std_msgs::Int32 pushed_msg;
ros::Publisher pub_button("pushed", &pushed_msg);

const int button_pin = 8;
const int button2_pin = 7;
const int relay_pin = 9;
void setup()
{
  nh.initNode();
  nh.advertise(pub_button);
  pinMode(button_pin, INPUT);
  pinMode(button2_pin, INPUT);
  pinMode(relay_pin, OUTPUT);
  digitalWrite(relay_pin,HIGH);

}

void loop()
{
  
  direksiyon=pulseIn(button_pin,HIGH);
  gaz=pulseIn(button2_pin,HIGH);
  //if the button value has not changed for the debounce delay, we know its stable
  if(gaz>1600){

    digitalWrite(relay_pin,LOW);
    //myservo.write(0);
  }
  else if(gaz>1400 && gaz<=1600){
    digitalWrite(relay_pin,HIGH);
    }
   else if(gaz<=1400 && gaz>1300){
    
    digitalWrite(relay_pin,HIGH);
    //myservo.write(15);
   }
  else{
digitalWrite(relay_pin,HIGH);
    //myservo.write(30);
      
  }
    pushed_msg.data = direksiyon;
    pub_button.publish(&pushed_msg);
    

  
  nh.spinOnce();
}
