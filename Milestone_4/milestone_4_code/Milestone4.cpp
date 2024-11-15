/*
 * @author: Jack Noyes
 * @date:   10/2/24
 * @breif: Gets one piece into the opposite rail
 */

/* Includes */

#include <Servo.h>

/* Pin Setup (Constant) */

const int leftA         = 2;   // Left Motor A pin
const int leftB         = 3;   // Left Motor B pin
const int rightA        = 6;  // Right Motor A pin
const int rightB        = 7;  // Right Motor B pin

const int greenLED      = 9;
const int redLED        = 4;
const int blueLED       = 11;

const int frontButton   = 13;

const int lightSensor   = A0;

const int totalReads    = 20;

Servo basketServo;
Servo sweepServo;
Servo pacmanServo;
Servo leftBucket;
Servo rightBucket;

// Variables 

int state = 0;            // variable to hold current state
unsigned long startTime;  // will store the time the state was setup 
int count = 0;
int sensorValue = 0;
long avg;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  //Servo attaching 
  
  basketServo.attach(8);
  sweepServo.attach(10);
  pacmanServo.attach(5);

  // geting servos in the correct position
  basketServo.write(80);
  delay(2000);
  pacmanServo.write(90);
  delay(100);
  sweepServo.write(180);
  

  //show off buttonS
  
  state1Setup();

}

void loop() {
  // put your main code here, to run repeatedly:
  switch (state){
    case 1:
      state1();
      break;
    case 2:
      state2();
      break;
    case 3:
      state3();
      break;
    deafult:
      break;

  }
}
