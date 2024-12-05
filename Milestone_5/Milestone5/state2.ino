void state2Setup() {
  platformForward();
  start = millis();
  state = 2;
}

void state2() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;
  Serial.println(distance);
  delay(100);
  if (distance <= 10.0) {
    platformStop();
    delay(200);
    platformBackward();
    delay(400);
    platformSpinLeft();
    delay(1000);
    platformStop();
    delay(200);
    platformBackward();
    delay(1000);
    platformStop();
    state3Setup();
  }
}