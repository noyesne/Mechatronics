/*
  Milestone 1
  @authors: Jack Noyes & Nic Maffucci
  @date 9/3/24

  Description: 
*/
#include "pitches.h"
// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 2;  // the number of the pushbutton pin
const int buttonPin2 = 3;
const int ledPin = 13;

// variables will change:
int buttonState1 = 0;  // variable for reading the pushbutton status

int buttonState2 = 0; // variable for the second button on pin3

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState1 == HIGH) {
    // Play C4
    digitalWrite(ledPin, HIGH);
  }
  else 
  {
    digitalWrite(ledPin, LOW);
  }
  
  if (buttonState2 == HIGH) {
    // play G3
    // iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < 8; thisNote++) {

      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(8, melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(8);
    }
  }
}
