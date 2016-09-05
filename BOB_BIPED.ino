#include <Servo.h>
#include <NewPing.h>

#define TRIGGER_PIN   12
#define ECHO_PIN      11
#define MAX_DISTANCE  1000

Servo hip_left;
Servo foot_left;
Servo hip_right;
Servo foot_right;

NewPing eyes(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int pos; 
int hip_left_rest = 1500;
int foot_left_rest = 1600;
int hip_right_rest = 1450;
int foot_right_rest = 1500;
int pace = 0;
int obstacle_distance = 0;
int max_obstacle_distance = 10;

//----------------------------------------------------------------

void setup() 
{
  Serial.begin(9600); // Data Monitoring Only
  
  hip_left.attach(4);
  foot_left.attach(3);
  hip_right.attach(2);
  foot_right.attach(5);

  hip_left.writeMicroseconds(hip_left_rest);
  foot_left.writeMicroseconds(foot_left_rest);
  hip_right.writeMicroseconds(hip_right_rest);
  foot_right.writeMicroseconds(foot_right_rest);
  
  delay(1000);

  hop();
}

void loop()
{
  obstacle_distance = eyes.ping_cm();
  Serial.print("Ping: ");
  Serial.print(obstacle_distance);
  Serial.println("cm");   
  
  if (obstacle_distance >= max_obstacle_distance)
  {   
    walk_strt();
  } 
}

//----------------------------------------------------------------

void hop()
{  
  for (int hop = 1; hop <=3; hop +=1)
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

//----------------------------------------------------------------

void walk_strt() 
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
