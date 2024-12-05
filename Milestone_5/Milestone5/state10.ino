void nextBlockSetup(){
  state = 10; 
}

void nextBlock(){
  platformForward();
  delay(800);
  platformStop();
  delay(500);
  platformSpinLeft();
  delay(1500);
  platformStop();
  delay(500);
  platformBackward();
  delay(2000);
  platformStop();
  delay(500);

  state3Setup();
}