void state2Setup(){
  start = millis();
  count = 0;
  state = 2;
  
}

void state2(){
    if(digitalRead(frontButton) == LOW){
      platformStop();
      delay(200);
      platformBackward();
      delay(200);
      platformSpinLeft();
      delay(700);
      platformStop();
      delay(200);
      platformBackward();
      delay(1000);
      platformStop();
      state3Setup();
    }
    else{
      platformForward();
      delay(2000);
       Serial.print("post delay");
    }
}