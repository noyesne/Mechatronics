void blackRailSetup() {
  state = 7;
  start = millis();
}

void blackRail() {
  platformForward();
  delay(500);
  platformStop();
  delay(200);
  if (!blackBlock) {
    platformSpinLeft();
    delay(1500);
  }
  else{
    platformSpinRight();
    delay(1500);
  }
  platformStop();
  delay(200);
  start = millis();
  while (millis() - start <= 5000) {
    platformBackward();
  }
  delay(500);
  platformStop();
  delay(200);

  if(!blackBlock){
  leftBucket.write(0);
  delay(1000);
  leftBucket.write(160);
  delay(2000);
  }
  else{
    rightBucket.write(160);
    delay(1000);
    rightBucket.write(0);
  }
  leftWallSetup();
}