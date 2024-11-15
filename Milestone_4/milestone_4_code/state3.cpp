void state3Setup() {
  state = 3;
  startTime = millis();
}

void state3() {
  
  // read the sensor 3 times then average it and make decision based on that
  if (millis() - startTime >= 300) {
    basketServo.write(80);
    startTime = millis();
    Serial.println(analogRead(ligthSensor));
    sensorValue += analogRead(lightSensor);

    count++;
  }
  
  if (count >= totalReads) {
    count = 0;
    avg = sensorValue / totalReads;
    Serial.print("AVG : ");
    Serial.print(avg);
    Serial.println("");
    if (avg > 30 && avg < 50) {
      sensorValue = 0;
      digitalWrite(blueLED, HIGH);
      pacmanServo.write(0);
      delay(500);
      pacmanServo.write(90);
      delay(1000);
      digitalWrite(blueLED, LOW);
    }

    else if(avg > 50 && avg < 150){
      sensorValue = 0;
      digitalWrite(GreenLED, HIGH);
      pacmanServo.write(180);
      delay(500);
      pacmanServo.write(90);
      delay(1000);
      digitalWrite(GreenLED, LOW);
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