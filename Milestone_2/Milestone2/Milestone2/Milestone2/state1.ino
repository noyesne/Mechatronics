void state1Setup() {
  delay(2000);
  startTime = millis();
  state = 1;
  count = 0;
}

void state1() {
  if(count < 1){
    state1Position();
  }
  unsigned long currentTime = millis();
  count++;
  Serial.println("FORWARD");
  if (currentTime - startTime >= 500) {
    if (digitalRead(frontButton) == HIGH) {
      platformStop();
      for (int i = 0; i < 3; i++) {
        tone(buzzerPin, NOTE_A5, 500);
        delay(1000);
      }
      state2Setup();
    }
  }
}

void state1Position()
{
  Serial.println("Position"); //get rid
  unsigned long currentTime = millis();
  startTime = millis();

  while (currentTime - startTime <= 600) {
    Serial.println("Forward");
    currentTime = millis();
    platformForward();
  }
  platformStop();

  startTime = millis();
  currentTime = millis();
  while (currentTime - startTime <= 570) {
    Serial.println("Left");
    currentTime = millis();
    platformSpinLeft();
  }
  platformStop();
  delay(500);

  platformForward();
}