/*
  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255 and uses
  the result to set the pulse width modulation (PWM) of an output pin.
  Also prints the results to the Serial Monitor.

  The circuit:
  - potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +5V and ground
  - LED connected from digital pin 9 to ground through 220 ohm resistor

  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInOutSerial
*/
#include <Servo.h>
// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;   // Analog input pin that the potentiometer is attached to
const int analogOutPin = 12;  // Analog output pin that the LED is attached to
const int redPin = 4;
const int greenPin = 3;
const int bluePin = 2;
Servo myservo;
Servo basket;
Servo arm;
unsigned long start = 0;
int sensorValue = 0;  // value read from the pot
int outputValue = 0;  // value output to the PWM (analog out)
int avg = 0;
int count = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  myservo.attach(8);
  basket.attach(9);
  arm.attach(4);
  start = millis();


  basket.write(50);
  arm.write(0);
}



void loop() {
  for(int i = 0; i < 180; i = i + 10){
    delay(50);
    arm.write(i);
    delay(200);
  }


 
}
