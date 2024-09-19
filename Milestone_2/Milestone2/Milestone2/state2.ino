
void state2Setup() {
  startTime = millis();
  state = 2;
  count = 0;
}

void state2() {
  unsigned long currentTime = millis();
  if (count < 1) {
    state2Position();
  }
  count++;

  if(count > 1){
    Serial.println("FORWARD");
  }
  if(currentTime - startTime >= 300) {
    if (digitalRead(frontButton) == HIGH) {
      platformStop();
      for (int i = 0; i < 3; i++) {
        tone(buzzerPin, NOTE_A5, 500);
        delay(500);
      }
      state3Setup();
    }
  }
}

void state2Position() {
  
  delay(1000);

  startTime = millis();
  unsigned long currentTime = millis();
  while (currentTime - startTime <= 2500) {
    Serial.println("backwards1");
    currentTime = millis();
    platformBackward();
  }

  platformStop();
  delay(100);

  startTime = millis();
  currentTime = millis();
  while (currentTime - startTime <= 560) {
    currentTime = millis();
    Serial.println("Left");
    platformSpinLeft();
  }

  platformStop();
  delay(200);

  startTime = millis();
  currentTime = millis();
  while (currentTime - startTime <= 2500) {
    currentTime = millis();
    Serial.println("forward");
    platformForward();
  }

  platformStop();
  delay(200);

  startTime = millis();
  currentTime = millis();
  while (currentTime - startTime <= 1000) {

    Serial.println("Backward2");
    currentTime = millis();
    platformBackward();
  }

  platformStop();
  delay(200);

  startTime = millis();
  currentTime = millis();
  while (currentTime - startTime <= 500) {
    Serial.println("Right");
    currentTime = millis();
    platformSpinRight();
  }

  platformStop();
  delay(200);

  platformForward();
}
