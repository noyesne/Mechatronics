/*
 * @author: Jack Noyes
 * @date:   10/2/24
 * @breif: Gets one piece into the opposite rail
 */

/* Pin Setup */

#include "pitches.h"
#include <Servo.h>

// constants won't change. Used here to
// set pin numbers:
const int leftA = 2;   // Left Motor A pin
const int leftB = 3;   // Left Motor B pin
const int rightA = 6;  // Right Motor A pin
const int rightB = 7;  // Right Motor B pin

const int buzzerPin = 8;

Servo armServo;
Servo sweepServo;

const int frontButton = 12;
const int backButton = 11;



// Variables will change:
int state = 0;            // variable to hold current state
unsigned long startTime;  // will store the time the state was setup
unsigned long count = 0;  // will change for running some position functions
int counter = 0;
// the following variable is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.

void setup() {
  // set the digital pins as output:
  pinMode(leftA, OUTPUT);
  pinMode(leftB, OUTPUT);
  pinMode(rightA, OUTPUT);
  pinMode(rightB, OUTPUT);
  armServo.attach(9);
  sweepServo.attach(10);
  Serial.begin(9600);
  state1Setup();
}


void loop() {
  // This loop simply calls the state function for the current State
  switch (state) {
    case 1:
      if (digitalRead(frontButton) == HIGH) {
        counter++;
      }
      if(counter > 1){
        state1();
    }
      break;
    case 2:
      state2();
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
      state7();
      break;
      //  Add more states here following the pattern if needed
      // However, there need to be state functions defined or there will be
      // compiler errors
  }
}