void state2Setup() {
  state = 2;
  count = 0;
  basketServo.write(60);
  sweepServo.write(60);
}
/* 
 *@breif This state will move the basket into the right position and sweep the pieces in.
 *
 *
 */
void state2() {
  //sweeps the arm to the basket
  for (int i = 60; i < 180; i = i + 10) {
    sweepServo.write(i);
    delay(5);
  }

  delay(500);
  sweepServo.write(60);

  basketServo.write(90);

  state3Setup();
}