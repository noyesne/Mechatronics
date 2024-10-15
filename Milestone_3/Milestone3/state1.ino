void state1Setup() {
  delay(1000);
  startTime = millis();
  state = 1;
  count = 0;
  sweepServo.write(0);
  armServo.write(90);
}

void state1() {
  armServo.write(180);
  if(count < 1){
    state1Position();
    
  }
  count++;

  if(digitalRead(frontButton) == HIGH) {
    platformStop();
    for (int i = 0; i < 1; i++) {
      tone(8, NOTE_G4, 500);
      delay(100);
    }
    state2Setup();
  }
}

void state1Position(){
  delay(1000);
  platformForward();
}