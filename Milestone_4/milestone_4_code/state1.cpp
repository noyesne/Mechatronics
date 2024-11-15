void state1Setup(){
  state = 1;
  count = 0;

}

void state1(){
  // If button pressed green LED will turn on for one second then stops
  Serial.print(digitalRead(frontButton));
  if(digitalRead(frontButton) == HIGH){
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    delay(1000);
    digitalWrite(greenLED, LOW);
    state2Setup();
  // While waiting for a button press blink a red light
  }else{
    delay(500);
    digitalWrite(redLED, HIGH);
    delay(500);
    digitalWrite(redLED, LOW);
  }
}