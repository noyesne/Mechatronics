void state5Setup() {
  start = millis();
  state = 5;
  int temp = 0;
  basketServo.write(120);
  delay(500);
  int j = 0;
  while (j < 2) {
    for (int i = 120; i >= 60; i--) {
      basketServo.write(i);
      delay(50);
    }
    basketServo.write(140);
    delay(500);
    basketServo.write(120);
    delay(1000);
    temp = analogRead(lightSensor);
    if(temp >= 10 && temp <= 60){
      j = 3;
    }
    j++;
  }

  empty = 0;
  attempt = 0;
}

void state5() {
  
  if (millis() - start >= 200) {
    
    Serial.print("Value: ");
    Serial.print(analogRead(lightSensor));
    Serial.print("\n");
    
    sensorValue += analogRead(lightSensor);
    delay(50);
    readCounter++;
    start = millis();
  }

  if (readCounter >= 25) {
    Serial.println(sensorValue);
    int avg = sensorValue / 25;
    
    
    Serial.print("AVG: ");
    Serial.print(avg);
    Serial.print("\n");
    
    if (avg >= 30 && avg <= 45) {

      //Black
      sortServo.write(180);
      delay(500);
      sortServo.write(90);
      blackCounter++;
      empty = 0;
    }

    if (avg >= 10 && avg <= 30) {
      sortServo.write(0);
      delay(500);
      sortServo.write(90);
      delay(200);
      whiteCounter++;
      empty = 0;
    }


    if (avg >= 80) {
      shimmy();
      delay(200);
      basketServo.write(120);
      //delay(200);
      //basketServo.write(140);
      empty++;
    }
    readCounter = 0;
    sensorValue = 0;
    avg = 0;
    runThroughs++;
  }

  if (empty >= 2) {
    state6Setup();
  }
}


void shimmy() {
  int i = 0;
  int temp = 0;

  while (i < 3) {

    basketServo.write(110);
    sweepServo.write(60);
    delay(200);
    sweepServo.write(80);
    delay(50);
    platformForward();
    delay(400);
    platformStop();
    delay(50);
    delay(50);
    platformBackward();
    delay(700);
    platformStop();
    delay(200);
    delay(1000);
    temp = analogRead(lightSensor);

    if (temp >= 10 && temp <= 60) {
      i = 4;
    }

    i++;
  }
  i = 0;

  delay(1000);
  temp = analogRead(lightSensor);

  if (temp >= 10 && temp <= 60) {
    i = 4;
  }

  while (i < 3) {

    for (int i = 120; i >= 60; i--) {
      basketServo.write(i);
      delay(50);
    }
    basketServo.write(140);
    delay(500);
    basketServo.write(120);
    delay(1000);

    temp = analogRead(lightSensor);

    if (temp >= 10 && temp <= 60) {
      i = 4;
    }
    i++;
  }
}