#include "Arduino.h"
#include <WProgram.h>
#include <Servo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle  nodeh;

Servo srv_base;
Servo srv_hand;


void Base( const std_msgs::UInt16& cmd_msg){
  srv_base.write(cmd_msg.data); 
  digitalWrite(13, HIGH-digitalRead(13));  

  // FOR CHECKING COMPLETE ONE REVOLUTION 180 degree
  /* for (pos1 = 0; pos1 <= 180; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    srv_base.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position

    for (pos1 = 180; pos1 >= 0; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  }*/
}

void Hand( const std_msgs::UInt16& cmd_msg){
  srv_hand.write(cmd_msg.data); 
  digitalWrite(14, HIGH-digitalRead(14)); 

  // FOR CHECKING COMPLETE ONE REVOLUTION 90 degree
  /*for (pos2 = 0; pos2 <= 90; pos2 += 1) { // goes from 0 degrees to 90 degrees
    // in steps of 1 degree
    myservo2.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos2 = 90; pos2 >= 0; pos2 -= 1) { // goes from 90 degrees to 0 degrees
    myservo2.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }*/
  }


ros::Subscriber<std_msgs::UInt16> sub_1("srv_base", Base);
ros::Subscriber<std_msgs::UInt16> sub_2("srv_hand", Hand);


void setup(){
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);


  nodeh.initNode();
  nodeh.subscribe(sub_1);
  nodeh.subscribe(sub_2);

  
  srv_base.attach(9); 
  srv_hand.attach(10); 
  
}

void loop(){
  nodeh.spinOnce();
  delay(2);
}
