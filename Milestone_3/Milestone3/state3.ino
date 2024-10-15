void state3Setup() {
  startTime = millis();
  state = 3;
  count = 0;
}

void state3() {
  armServo.write(140);
  unsigned long currentTime = millis();
  while (currentTime - startTime <= 500) {
    platformSpinRight();
    currentTime = millis();
  }
  delay(100);
  platformStop();

  platformStop();
  delay(200);

  for (int i = 0; i < 140; i++) {
    sweepServo.write(i);
    delay(5);
  }

  sweepServo.write(0);

  for (int pos = 160; pos <= 180; pos++) {
    armServo.write(pos);
    delay(10);
  }

  for (int i = 0; i < 3; i++) {
    tone(8, NOTE_G4, 200);
    delay(500);
  }

  delay(100);
  state4Setup();
}