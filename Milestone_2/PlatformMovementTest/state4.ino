
void state4Setup() {
  Serial.println("In state 4 setup");
  platformBackward();
  startTime = millis();
  state = 4;
}

void state4() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime;

  //Template to stop this state after a timeout

  currentTime = millis();
  if ((currentTime - startTime) > interval) {
    platformStop();
    delay(interval);
    state1Setup();
  }

}

