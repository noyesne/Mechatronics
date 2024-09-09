#include "pitches.h"

/* 
 *@brief  Will play "Hedwig's theme - Harry Potter" without the use of the delay function
 *@author Jack Noyes
 *@source Robson Couto, 2019  https://github.com/robsoncouto/arduino-songs 
 *
 *@return Returns 1 when other button is pressed and 0 when not pressed
 */
int harry_potter() {
  /* Variables */

  int bpm = 260;
  int buzzerPin = 8;
  int button2 = 2;                    //harry_potter pin
  int button3 = 3;                    //happy_birthday pin
  int ledPin = 13;                    // this is the built in LED on pin 13
  int wholenote = (60000 * 4) / bpm;  // this calculates the duration of a whole note in ms (60s/bpm)*4 beats
  int divider = 0;
  int duration = 0;
  int flag = 0;  //this flag = 1 when the opposite button is pressed

  /*
   * notes of the moledy followed by the duration.
   * a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
   * !!negative numbers are used to represent dotted notes,
   * so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
   */

  int melody[] = {

    // Hedwig's theme fromn the Harry Potter Movies
    // Socre from https://musescore.com/user/3811306/scores/4906610

    REST,
    2,
    NOTE_D5,
    4,
    NOTE_G5,
    -4,
    NOTE_AS5,
    8,
    NOTE_A4,
    4,
    NOTE_G5,
    2,
    NOTE_D5,
    4,
    NOTE_C5,
    -2,
    NOTE_A4,
    -2,
    NOTE_G4,
    -4,
    NOTE_AS4,
    8,
    NOTE_A4,
    4,
    NOTE_F4,
    2,
    NOTE_GS4,
    4,
    NOTE_D4,
    -1,
    NOTE_D4,
    4,
    NOTE_G4,
    -4,
    NOTE_AS4,
    8,
    NOTE_A4,
    4,  //10
    NOTE_G4,
    2,
    NOTE_D5,
    4,
    NOTE_F5,
    2,
    NOTE_E5,
    4,
    NOTE_DS5,
    2,
    NOTE_B4,
    4,
    NOTE_DS5,
    -4,
    NOTE_D5,
    8,
    NOTE_CS5,
    4,
    NOTE_CS4,
    2,
    NOTE_B4,
    4,
    NOTE_G4,
    -1,
    NOTE_AS4,
    4,
    NOTE_D5,
    2,
    NOTE_AS4,
    4,  //18
    NOTE_D5,
    2,
    NOTE_AS4,
    4,
    NOTE_DS5,
    2,
    NOTE_D5,
    4,
    NOTE_CS5,
    2,
    NOTE_A4,
    4,
    NOTE_AS4,
    -4,
    NOTE_D5,
    8,
    NOTE_CS5,
    4,
    NOTE_CS4,
    2,
    NOTE_D4,
    4,
    NOTE_D5,
    -1,
    REST,
    4,
    NOTE_AS4,
    4,
    NOTE_D5,
    2,
    NOTE_AS4,
    4,  //26
    NOTE_D5,
    2,
    NOTE_AS4,
    4,
    NOTE_F5,
    2,
    NOTE_E5,
    4,
    NOTE_DS5,
    2,
    NOTE_B4,
    4,
    NOTE_DS5,
    -4,
    NOTE_D5,
    8,
    NOTE_CS5,
    4,
    NOTE_CS4,
    2,
    NOTE_AS4,
    4,
    NOTE_G4,
    -1,
  };

  // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
  // there are two values per note (pitch and duration), so for each note there are four bytes
  int notes = sizeof(melody) / sizeof(melody[0]) / 2;

    if(digitalRead(button2) == HIGH){
      hold1 = 1;
    }
  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      duration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      duration = (wholenote) / abs(divider);
      duration *= 1.5;  // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzerPin, melody[thisNote], duration * 0.9);
    unsigned long currentTime = millis();
    while (millis() - currentTime <= duration) {
      
      if(digitalRead(button2) == LOW){
        hold1 = 0;
      }
      if (digitalRead(button3) == HIGH) {
        flag = 3;
      }
      if (digitalRead(button2) == LOW && hold1 == 1) {
        flag = 0;
      }
      if(digitalRead(button2) == HIGH && hold1 == 0){
        flag = 2;
      }

    }
    // stop the waveform generation before the next note.
    noTone(buzzerPin);
  }
  return flag;
}