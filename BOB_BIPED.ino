#include <Servo.h>

int pos; 

Servo hip_left;
Servo foot_left;
Servo hip_right;
Servo foot_right;

int hip_left_rest = 1500;
int foot_left_rest = 1600;
int hip_right_rest = 1450;
int foot_right_rest = 1500;

int pace = 100;

void setup() 
{
  hip_left.attach(4);
  foot_left.attach(3);
  hip_right.attach(2);
  foot_right.attach(5);

  hip_left.writeMicroseconds(hip_left_rest);
  foot_left.writeMicroseconds(foot_left_rest);
  hip_right.writeMicroseconds(hip_right_rest);
  foot_right.writeMicroseconds(foot_right_rest);
  
// -----------------------------------------------------  
  
  delay(1000);
  for (int dance = 1; dance <=3; dance +=1)
  {
    foot_right.write(1000);
    foot_left.write(2000);
    delay(100);
    foot_right.write(foot_right_rest);
    foot_left.write(foot_left_rest);
    delay(100);
  }
  
  foot_right.write(foot_right_rest);
  foot_left.write(foot_left_rest); 
  delay(1000);
  
}

void loop() 
{
  for (pos = foot_right_rest; pos <=1650; pos +=1)
  {
    foot_right.write(pos);
    delay(2);
  }
  delay(pace);
  
  for (pos = hip_right_rest; pos >=1100; pos -=1)
  {
    hip_right.write(pos);
    delay(2);
  }
  delay(pace);

 for (pos = hip_left_rest; pos >=1200; pos -=1)
 {
  hip_left.write(pos);
  delay(2);
 }
 delay(pace);
 
 for (pos = 1650; pos >= foot_right_rest; pos -=1)
 {
  foot_right.write(pos);
  delay(2);
 }
 delay(pace);
 
 for (pos = foot_left_rest; pos >=1300; pos -=1)
 {
  foot_left.write(pos);
  delay(2);
 }
 delay(pace);
 
 for (pos = 1200; pos <= hip_left_rest; pos +=1)
 {
  hip_left.write(pos);
  delay(2);
 }
 delay(pace);

 for(pos = 1100; pos <= hip_right_rest; pos +=1)
 {
  hip_right.write(pos);
  delay(2);
 }
 delay(pace);

 for(pos = 1300; pos <= foot_left_rest; pos +=1)
 {
  foot_left.write(pos);
  delay(2);
 }
 delay(pace);
 
}
