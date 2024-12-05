void state4Setup() {
  start = millis();
  state = 4;
  runThroughs++;
  angleServo.write(65);
}

void state4() {

  unsigned long current = millis();
  if (current - start >= 500) {
    for (int i = 20; i < 180; i += 2) {
      sweepServo.write(i);
      if (i == 90) {
        if (!blackBlock) {
          angleServo.write(55);
        }
      }
      delay(100);
    }

    platformBackward();
    delay(1500);
    platformStop();
    sweepServo.write(0);
    state5Setup();
  }
}