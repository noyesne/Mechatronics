
void state1Setup() {
  platformForward();
  startTime = millis();
  state = 1;
}

void state1() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime;

  //Template to stop this state after a timeout

  currentTime = millis();
  if ((currentTime - startTime) > interval) {
    platformStop();
    delay(interval);
    state2Setup();
  }

}

