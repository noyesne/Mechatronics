/* 
  @author Nic Maffucci
  @date 9/19/24

  @brief Navigates the playing field
*/

#include "pitches.h"


// constants won't change. Used here to
// set pin numbers:
const int leftA = 2;   // Left Motor A pin
const int leftB = 3;   // Left Motor B pin
const int rightA = 6;  // Right Motor A pin
const int rightB = 7;  // Right Motor B pin

const int frontButton = 12;
const int backButton = 11;

const int buzzerPin = 8;

// Variables will change:
int state = 0;            // variable to hold current state
unsigned long startTime;  // will store the time the state was setup
unsigned long count = 0;  // will change for running some position functions

// the following variable is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 2000;  // interval at which to change

void setup() {
  // set the digital pins as output:
  pinMode(leftA, OUTPUT);
  pinMode(leftB, OUTPUT);
  pinMode(rightA, OUTPUT);
  pinMode(rightB, OUTPUT);
  state1Setup();
  Serial.begin(9600);
}


void loop() {
  // This loop simply calls the state function for the current State
  switch (state) {
    case 1:
      state1();
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

      //  Add more states here following the pattern if needed
      // However, there need to be state functions defined or there will be
      // compiler errors
  }
}
