void state3Setup() {
  start = millis();
  state = 3;
}

void state3() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;
  Serial.println(distance);
  delay(100);
  platformForward();
  delay(100);
  platformStop();
  if (distance < 5) {
    platformStop();
    delay(200);
    platformBackward();
    delay(400);
    platformStop();
    delay(300);
    sweepServo.write(20);
    delay(500);
    basketServo.write(60);
    delay(500);
    for (int i = 0; i < 6; i++) {
      platformForward();
      delay(50);
      platformStop();
      delay(100);
    }

    platformSpinRight();
    delay(300);
    platformStop();


    state4Setup();
  }
}