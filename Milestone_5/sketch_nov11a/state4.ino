void state4Setup() {
  start = millis();
  state = 4;
}

void state4() {
  unsigned long current = millis();
  if (current - start >= 500) {
    for (int i = 0; i < 180; i += 5) {
      sweepServo.write(i);
      delay(20);
    }
    platformBackward();
    delay(500);
    state5Setup();
  }
}