#include "pitches.h"
/* 
 * @brief This is the error sound when someone presses the other button when the melody is playing
 */
void play_queue() {
  int count = 0;
  unsigned long currentTime = millis();
  while (count != 2) {
    if (millis() - currentTime >= 1000) {
      currentTime = millis();
      Serial.println(count);
      if (count == 0) {
        tone(buzzerPin, NOTE_G4, 500);
      }
      while (millis() - currentTime <= 500) {
        Serial.print("in loop1");
      }
      if (count == 1) {
        Serial.println("In HERE!!!");
        tone(buzzerPin, NOTE_G4, 500);
      }
      count++;
      currentTime = millis();
    }
  }
  while (millis() - currentTime <= 1000) {
    Serial.println("in Loop2");
  }
}