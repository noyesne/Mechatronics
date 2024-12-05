void state1Setup() {
  start = millis();
  state = 1;
}

void state1() {
  if (starting) {
    
    if (digitalRead(frontButton) == HIGH) {
      starting = false;
      delay(1000);
      delay(50);
      state2Setup();
    }
  }
  if (blackBlock) {
    nextBlockSetup();
  }
  if (marble) {
  }
}