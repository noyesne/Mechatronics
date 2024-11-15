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
const int analogInPin = A0;   // Analog input pin that the potentiometer is attached to // Analog output pin that the LED is attached to

Servo myservo;
Servo basket;
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
  start = millis();
  myservo.write(90);
  basket.write(150);
  delay(500);
  basket.write(100);
}



void loop() {


  if (millis() - start >= 300) {

    start = millis();
    Serial.println(analogRead(A0));
    delay(1000);
    sensorValue += analogRead(A0);

    count++;
  }

  Serial.println(count);

  if (count >= 10) {
    count = 0;
    avg = sensorValue / 10;
    Serial.print("AVG : ");
    Serial.print(avg);
    Serial.println(" ");
    if (avg > 10 && avg <= 25){
      myservo.write(180);
      sensorValue = 0;
      avg = 0;
      delay(1000);
      myservo.write(90);

    }

    else if (avg > 25 && avg < 60) {
      myservo.write(0);
      sensorValue = 0;
      avg = 0;
      delay(1000);
      myservo.write(90);
    }

    else {

      basket.write(150);
      delay(500);
      basket.write(100);
      myservo.write(90);
      sensorValue = 0;
      avg = 0;
    }
  }
}
