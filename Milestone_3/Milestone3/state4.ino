void state4Setup() {
  startTime = millis();
  count = 0;
  platformBackward();
  state = 4;
}

void state4(){
  unsigned long currentTime = millis();
  Serial.println(startTime);
  if(currentTime - startTime >= 2000){
    platformStop();
    for(int i = 0; i < 4; i++){
    tone(8, NOTE_G4,200);
    delay(500);
  }
    state5Setup();
  }


}