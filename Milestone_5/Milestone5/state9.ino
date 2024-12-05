void whiteRailSetup() {
  state = 9;
  start = millis();
}

void whiteRail() {
  platformBackward();
  delay(500);
  platformStop();
  delay(200);
  if (!blackBlock) {
    platformSpinRight();
    delay(2000);
    platformStop();
    delay(500);
    //platformBackward();
    //delay(2000);
    platformStop();
    delay(200);
    platformBackward();
    delay(2000);
    platformStop();
    delay(200);
    platformForward();
    delay(800);
    platformSpinRight();
    delay(1000);
  } else {
    platformSpinLeft();
    delay(2000);
    platformStop();
    delay(500);
    //platformBackward();
    //delay(2000);
    platformStop();
    delay(200);
    platformBackward();
    delay(2000);
    platformStop();
    delay(200);
    platformForward();
    delay(800);
    platformSpinLeft();
    delay(1000);
  }

  platformStop();
  delay(200);
  platformBackward();
  delay(2000);
  platformStop();
  delay(200);
  if (!blackBlock) {
    rightBucket.write(140);
    delay(2000);
    rightBucket.write(0);
    delay(1000);
  } else {
    leftBucket.write(0);
    delay(2000);
    leftBucket.write(160);
    delay(1000);
  }


  if (blackBlock) {
    blackBlock = false;
  } else {
    blackBlock = true;
  }
  state1Setup();
}