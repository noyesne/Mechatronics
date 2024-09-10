
void state3Setup() {
  platformSpinRight();
  startTime = millis();
  state = 3;
}

void state3() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime;

  //Template to stop this state after a timeout

  currentTime = millis();
  if ((currentTime - startTime) > interval) {
    platformStop();
    delay(interval);
    state4Setup();
  }

}

