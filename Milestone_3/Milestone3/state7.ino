void state7Setup(){
  startTime = millis();
  state = 7;
  count = 0;
}

void state7(){
    armServo.write(100);
    platformForward();
    delay(300);
    armServo.write(160);
    platformBackward();
    delay(200);
}