#include <Servo.h>

// defines pins numbers
const int trigPin = 4;
const int echoPin = 5;
const int servoPin =  6;
Servo servo;

// defines variables
long duration;
int distance;
int pos = 0;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(servoPin, OUTPUT); //Sets the servoPin as an Output
  servo.attach(6);
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  Serial.println(findDist());
  moveServo();
  delay(5);
}

int findDist(){
   // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance= duration*0.034/2;

  return distance;
}

void moveServo(){
  if(pos > 180){
    pos = 0;
  }
  servo.write(pos);
  pos++;
}

