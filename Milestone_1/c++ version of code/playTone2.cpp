#include "pitches.h"
/* 
 *@brief   Will play "Happy Birthday" without the use of the delay function
 *@author  Jack Noyes
 *@source  Robson Couto, 2019, https://github.com/robsoncouto/arduino-songs/blob/master/happybirthday/happybirthday.ino
 *@return  Return 1 when other button is pressed and 0 when not pressed
 */
int happy_birthday() {
  /* Variables */

  // change this to make the song slower or faster
  int bpm = 220;
  // change this to whichever pin you want to use
  int buzzerPin = 8;
  int ledPin = 13;
  int button2 = 2;                    //harry_potter pin
  int button3 = 3;                    //happy_birthday pin
  int flag = 0;                       //flag will be 1 if other button is pressed when meoldy is playing
  int wholenote = (60000 * 4) / bpm;  // this calculates the duration of a whole note in ms
  int divider = 0;
  int duration = 0;

  /*
   * notes of the moledy followed by the duration.
   * a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
   * !!negative numbers are used to represent dotted notes,
   * so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
   */


  int melody[] = {

    // Happy Birthday
    // Score available at https://musescore.com/user/8221/scores/26906
    NOTE_C4,
    4,
    NOTE_C4,
    8,
    NOTE_D4,
    -4,
    NOTE_C4,
    -4,
    NOTE_F4,
    -4,
    NOTE_E4,
    -2,
    NOTE_C4,
    4,
    NOTE_C4,
    8,
    NOTE_D4,
    -4,
    NOTE_C4,
    -4,
    NOTE_G4,
    -4,
    NOTE_F4,
    -2,
    NOTE_C4,
    4,
    NOTE_C4,
    8,
    NOTE_C5,
    -4,
    NOTE_A4,
    -4,
    NOTE_F4,
    -4,
    NOTE_E4,
    -4,
    NOTE_D4,
    -4,
    NOTE_AS4,
    4,
    NOTE_AS4,
    8,
    NOTE_A4,
    -4,
    NOTE_F4,
    -4,
    NOTE_G4,
    -4,
    NOTE_F4,
    -2,

  };

  // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
  // there are two values per note (pitch and duration), so for each note there are four bytes
  int notes = sizeof(melody) / sizeof(melody[0]) / 2;

  if (digitalRead(3) == HIGH) {
        Serial.println("button 3 HIGH");
        hold2 = 1;
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

      Serial.println(hold2);
      
      
      if (digitalRead(3) == LOW){
        Serial.println("button 3 LOW");
        hold2 = 0;
      }
      if (digitalRead(2) == HIGH){
        Serial.print("button 2 HIGH");
        flag = 2;
      }
      if (digitalRead(button3) == LOW && hold2 == 1) {
        Serial.println("IN case 2");
        flag = 0;
      }
      if (digitalRead(button3) == HIGH && hold2 == 0) {
        Serial.println("IN case 3");
        flag = 3;
      }
      if(digitalRead(button3) == HIGH && hold2 == 1){
        flag == 0;
      }
      
    }
    

    // stop the waveform generation before the next note.
    noTone(buzzerPin);
  }
  return flag;
}