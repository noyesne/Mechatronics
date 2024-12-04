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



const int frontButton   = 12;
const int trigPin       = 13;
const int echoPin       = 11;

const int lightSensor   = A0;

const int totalReads    = 20;

Servo basketServo;
Servo sweepServo;
Servo angleServo;
Servo sortServo;
Servo leftBucket;
Servo rightBucket;

// Variables 

int state = 0;            // variable to hold current state
unsigned long start;  // will store the time the state was setup 
int readCounter = 0;
long sensorValue = 0;
int runThroughs = 0;
int posCounter = 1;     //this will know when each wall has been hit
int attempt = 0;
bool flag = false;

int blackCounter = 0;


float duration, distance;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  //Servo attaching 
  pinMode(leftA, OUTPUT);
  pinMode(leftB, OUTPUT);
  pinMode(rightA, OUTPUT);
  pinMode(rightB, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(frontButton, INPUT);
  
   
  basketServo.attach(9);
  sweepServo.attach(4);
  sortServo.attach(8);
  rightBucket.attach(10);
  angleServo.attach(A1);
  leftBucket.attach(5);

  // geting servos in the correct position
  basketServo.write(130);
  delay(200);
  sortServo.write(90);
  delay(100);
  sweepServo.write(160);
  delay(200);
  leftBucket.write(160);
  delay(200);
  rightBucket.write(0);
  delay(200);
  

  //show off buttonS
  
  state1Setup();

}

void loop() {
  // put your main code here, to run repeatedly:
  switch (state){
    case 1:
      state1();
      Serial.println("IN STATE 1");
      break;
    case 2:
      state2();
      Serial.println("IN STATE 2");
      break;
    case 3:
      state3();
      
      break;
    case 4:
      state4();
      
      break;
    case 5:
      state5();
      
      break;
    case 6:
      state6();
      break;
    case 7:
      blackRail();
      break;
    case 8:
      leftWall();
      break;
    case 9:
      whiteRail();
      break;

  }
}
