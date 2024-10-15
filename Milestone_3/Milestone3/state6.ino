void state6Setup() {
  startTime = millis();
  count = 0;
  state = 6;
}

void state6() {
  delay(200);
  armServo.write(100);
  delay(200);

  for (int i = 0; i < 6; i++) {
    tone(8, NOTE_G4, 200);
    delay(500);
  }
  counter = 0;
  state7Setup();
  
}