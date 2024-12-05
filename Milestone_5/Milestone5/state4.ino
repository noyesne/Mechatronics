void state4Setup() {
  start = millis();
  state = 4;
  runThroughs++;
  angleServo.write(60);
}

void state4() {
  
  unsigned long current = millis();
  if (current - start >= 500) {
    for (int i = 20; i < 180; i += 2) {
      sweepServo.write(i);
      delay(50);
    }

    platformBackward();
    delay(1500);
    platformStop();
    sweepServo.write(0);
    state5Setup();
  }
}