 void leftWallSetup(){
  state = 8;
  start = millis();
  delay(500);
 }

 void leftWall() {
  platformForward();
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;
  Serial.println(distance);
  delay(100);

  if (distance <= 10) {
    platformStop();
    delay(100);
    whiteRailSetup();
  }
}