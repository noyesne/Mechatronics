
void state2Setup() {
  platformSpinLeft();
  startTime = millis();
  state = 2;
}

void state2() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime;

  //Template to stop this state after a timeout

  currentTime = millis();
  if ((currentTime - startTime) > interval) {
    platformStop();
    delay(interval);
    state3Setup();
  }

}

