
/*
  Milestone 1
  @authors: Jack Noyes & Nic Maffucci
  @date 9/4/24

  Description: With the push of one of two buttons two different tunes will play
               those being, Harry Potter Theme and Happy Birthday
               it will also catch if the other button was pushed as the song was playing
*/
/* Includes */
#include "pitches.h"

/* Constants */
const int buttonPin1 = 2;
const int buttonPin2 = 3;

int hold1 = 0;
int hold2 = 0;
/* Variables */
int buttonState1 = 0;  // variable state for the button on pin 2
int buttonState2 = 0;  // variable state for the button on pin 3
int ledPin = 13;
int buzzerPin = 8;

int flag = 0;


/*
 * @brief First method run on boot up of the board will be ran once 
 */
void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);  //used for debugging
}

/* 
 * @brief Looping statment that will always be ran and will continue to loop for the entire time arduino is on 
 */
void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState1 == HIGH) {
    
    flag = harry_potter();
  }

  buttonState2 = digitalRead(buttonPin2);
  if (buttonState2 == HIGH) {
    flag = happy_birthday();
  }
//check what song is queued

  Serial.println(flag);

  if (flag == 2) {
    play_queue();
    flag = harry_potter();
  }

  if (flag == 3) {
    play_queue();
    flag = happy_birthday();
  }

}
