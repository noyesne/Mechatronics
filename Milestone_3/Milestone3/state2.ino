void state2Setup() {
  startTime = millis();
  state = 2;
  count = 0;
}

void state2() {

  unsigned long currentTime = millis();
  armServo.write(175);
  if (count < 1) {
    state2Position();
  }
  count++;
  
  delay(200);
  platformStop();
  delay(50);
  platformForward();

  if (digitalRead(frontButton) == HIGH) {
    platformStop();
    for (int i = 0; i < 2; i++) {
      tone(8, NOTE_G4, 200);
      delay(500);
    }
    state3Setup();
  }
}

void state2Position() {
  startTime = millis();
  unsigned long currentTime = millis();

  while (currentTime - startTime <= 550) {
    platformBackward();
    currentTime = millis();
  }

  platformStop();
  delay(100);
  startTime = millis();
  currentTime = millis();
  while (currentTime - startTime <= 790) {
    platformSpinLeft();
    currentTime = millis();
  }

  platformStop();
  delay(100);


  startTime = millis();
  currentTime = millis();

  while (currentTime - startTime <= 1000) {
    platformBackward();
    currentTime = millis();
  }
  platformStop();
  delay(100);

  startTime = millis();
  currentTime = millis();


  platformStop();
  startTime = millis();
  currentTime = millis();

  platformStop();
  platformForward();
}