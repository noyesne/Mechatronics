void whiteRailSetup(){
  state = 9;
  start = millis();
}

void whiteRail() {
  platformBackward();
  delay(500);
  platformStop();
  delay(200);
  platformSpinRight();
  delay(2000);
  platformStop();
  delay(200);
  platformBackward();
  delay(2000);
  platformStop();
  delay(200);

  rightBucket.write(140);
  delay(400);
  rightBucket.write(0);
  delay(300);

  state1Setup();
}