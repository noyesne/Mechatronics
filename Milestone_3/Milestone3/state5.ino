void state5Setup() {
  startTime = millis();
  count = 0;
  state = 5;
}

void state5() {
  if (count < 1) {
    state5Position();
  }

  count++;

  if (digitalRead(frontButton) == HIGH) {
    platformStop();
    delay(100);

    for (int i = 0; i < 5; i++) {
      tone(8, NOTE_G4, 200);
      delay(500);
    }

    state6Setup();
  }
}

void state5Position() {

  startTime = millis();
  unsigned long currentTime = millis();

  while(currentTime - startTime <= 300){
    platformForward();
    currentTime = millis();
  }
  
  platformStop();
  delay(100);
  startTime = millis();
  currentTime = millis();
  while (currentTime - startTime <= 750) {
    platformSpinLeft();
    currentTime = millis();
  }

  platformStop();
  delay(200);

  startTime = millis();
  currentTime = millis();

  while (currentTime - startTime <= 1000) {
    platformBackward();
    currentTime = millis();
  }


  platformStop();
  delay(200);

  platformForward();
}