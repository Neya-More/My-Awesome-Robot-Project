Enter file contents here
//TrigPin to Pin 2
//EchoPin to Pin 4
#include <Servo.h> 
int trigPin = 2;
int echoPin = 4;

long cm;
long duration;
long distance;


Servo LeftW;
Servo RightW;
void setup()
{
  LeftW.attach(11);
RightW.attach(10);  
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode (13, OUTPUT);

 Serial.begin(9600);
}


void loop()
{
  cm = getDistance();
  if (cm > 5){
    LeftW.writeMicroseconds(1300);
    digitalWrite(13, HIGH);}
  else{ 
    digitalWrite(13, LOW);
    LeftW.writeMicroseconds(1700);
   }
  Serial.println(cm);
}





long getDistance()
{
  delay(10);  
  //trigger the device
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  

//how long it has been since we sent the ping  
  duration = pulseIn(echoPin, HIGH);

//convert the duration to centimeters ( div by 2 because to and frro)
  cm = duration/27/2;
  return cm;
}


