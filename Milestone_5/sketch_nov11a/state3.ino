void state3Setup(){
  start = millis();
  state = 3;
  platformForward();
}

void state3(){
    if(digitalRead(frontButton) == LOW ){
      platformStop();
      delay(200);
      platformBackward();
      delay(200);
      platformStop();
      sweepServo.write(0);
      basketServo.write(50);
      state4Setup();
    }
}