void blackRailSetup() {
  state = 7;
  start = millis();
}

void blackRail() {
  platformForward();
  delay(800);
  platformStop();
  delay(200);
  platformSpinLeft();
  delay(1500);
  platformStop();
  delay(200);
  start = millis();
  while (millis() - start <= 5000) {
    platformBackward();
  }
  delay(500);
  platformStop();
  delay(200);
  leftBucket.write(160);
  delay(5000);
  Serial.write("DUMPED!");
  leftBucket.write(0);
  delay(200);
  leftWallSetup();
}