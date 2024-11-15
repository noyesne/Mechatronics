void state1Setup(){
  state = 1;
  count = 0;

}

void state1(){
  // If button pressed green LED will turn on for one second then stops
  Serial.print(digitalRead(frontButton));
  if(digitalRead(frontButton) == HIGH){
  
    delay(1000);
    sweepServo.write(0);
    delay(500);
    basketServo.write(90);
    
    state2Setup();
  // While waiting for a button press blink a red light
  }else{
    delay(500);
    
    delay(500);
    
  }
}