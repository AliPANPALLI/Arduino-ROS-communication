#include <ros.h>
#include <std_msgs/Int8.h>

ros::NodeHandle  nh;

#define PIN_INPUT A3

#define RPWM 9 // define pin 3 for RPWM pin (output)

#define LPWM 11 // define pin 6 for LPWM pin (output)
 

int val = 0;
void messageCb(const std_msgs::Int8& msg){
  
  if(msg.data == 2 ){
          digitalWrite(LPWM,HIGH);
          digitalWrite(RPWM,LOW); //run motor for target value
          
  }
  else if(msg.data == 1){
            digitalWrite(RPWM,HIGH);
            digitalWrite(LPWM,LOW); //run motor for target value
  }
  /*
  else if((msg.data == 3)){
    if(val<570){
      if(val>430){
            digitalWrite(RPWM,HIGH);
            digitalWrite(LPWM,LOW); //run motor for target value
  }
  else{
    digitalWrite(LPWM,LOW);
          digitalWrite(RPWM,LOW);
  
  }
  }
  else if(val >=590 ){
    digitalWrite(LPWM,HIGH);
          digitalWrite(RPWM,LOW); //run motor for target value
  }
  else {
    digitalWrite(LPWM,LOW);
          digitalWrite(RPWM,LOW);
  }
  }*/
  else {
            
          digitalWrite(LPWM,LOW);
          digitalWrite(RPWM,LOW); //run motor for target value
  }
}
ros::Subscriber<std_msgs::Int8> sub("stick", &messageCb);
void setup() {
  pinMode(RPWM,OUTPUT);
  pinMode(LPWM,OUTPUT);
  
  nh.initNode();
  nh.subscribe(sub);
}
void loop() {
  val = analogRead(PIN_INPUT);
  nh.spinOnce();
  delay(1);
 }
  
