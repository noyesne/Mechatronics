void state1Setup(){
  start = millis();
  state = 1;
  
}

void state1(){
  
  if(digitalRead(frontButton) == LOW){
    delay(1000);
    delay(50);
    state2Setup();
  }

}