
void state3Setup() {
  platformBackward();
  startTime = millis();
  state = 3;
  count = 1;
}

void state3() {
  if(count >= 1){
    Serial.println("STATE3");
  }
  unsigned long currentTime = millis();
  if(currentTime - startTime >= 300) {
    Serial.println("backwards3");
    if (digitalRead(backButton) == HIGH) {
      platformStop();
      delay(500);
      state4Setup();
    }
  }
}
