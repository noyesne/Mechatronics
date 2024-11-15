void state1Setup(){
  start = millis();
  state = 1;
  
}

void state1(){
  
  if(digitalRead(frontButton) == LOW){
    delay(1000);
    state2Setup();
  }

}