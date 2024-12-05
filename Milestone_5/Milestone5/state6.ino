void state6Setup() {
  state = 6;
  start = millis();
  posCounter = 1;
  basketServo.write(140);
  delay(500);
  sweepServo.write(180);
}

void state6() {
  platformBackward();
  delay(1000);
  platformStop();
  delay(200);
  blackRailSetup();
}
