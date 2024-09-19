void state4Setup() {
  startTime = millis();
  platformSpinRight();
  state = 4;
}

void state4() {
  unsigned long currentTime = millis();
  if(currentTime - startTime >= 500) {
    platformStop();
    state5Setup();
  }
}