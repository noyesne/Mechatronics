void temp(){
    attempt++;
      delay(500);
      basketServo.write(130);
      delay(600);
      basketServo.write(150);
      delay(300);
      basketServo.write(130);
      for (int i = 140; i <= 70; i = i - 10) {
        basketServo.write(i);
        delay(10);
        flag = true;
      }

      basketServo.write(70);
      delay(500);

      if (attempt >= 4) {
        flag = false;
        attempt = 0;
        for (int i = 0; i < 3; i++) {
          delay(50);
          basketServo.write(120);
          delay(500);
          basketServo.write(70);
          delay(200);
        }
      }
}