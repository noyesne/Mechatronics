//  Matthew Stein
//  In-class 1 solution

byte counter;

void setup() {
  // put your setup code here, to run once:
  counter = 0;
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly: 
  delay(4000);  // Run once every 4 second
   digitalWrite(2,counter & B00000001);
   digitalWrite(3,counter & B00000010);
   digitalWrite(4,counter & B00000100);
   digitalWrite(5,counter & B00001000);
  
  
  counter = counter + 1;
  if(counter == 16) counter = 0;
 
  
  
  
  
  
  
  
}
