void state3Setup() {
  state = 3;
  startTime = millis();

  rightBucket.write(0);
  delay(200);
  leftBucket.write(180);
}

void state3() {
  
  // read the sensor 3 times then average it and make decision based on that
  if (millis() - startTime >= 300) {
    basketServo.write(80);
    startTime = millis();
    Serial.println(analogRead(A0));
    sensorValue += analogRead(A0);

    count++;
  }
  
  if (count >= totalReads) {
    count = 0;
    avg = sensorValue / totalReads;
    Serial.print("AVG : ");
    Serial.print(avg);
    Serial.println("");
    if (avg > 10 && avg < 50) {
      sensorValue = 0;
      digitalWrite(11, HIGH);
      pacmanServo.write(0);
      delay(500);
      pacmanServo.write(90);
      delay(1000);
      digitalWrite(11, LOW);
    }

    if(avg > 50 && avg < 150){
      sensorValue = 0;
      digitalWrite(12, HIGH);
      pacmanServo.write(180);
      delay(500);
      pacmanServo.write(90);
      delay(1000);
      digitalWrite(12, LOW);
    }

    else {
      sensorValue = 0;
      delay(500);
      basketServo.write(80);
      delay(500);
      basketServo.write(150);
      delay(1000);
    }
  }
  
}