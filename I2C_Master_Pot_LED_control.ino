/*
   Demonstrate use of I2C bus
   Project to control an LED(connected to Slave) by the Potentiometer(connected to Master)
   Master sends Potentiometer position data
   Circuit diagram at: "C:\Users\91987\Pictures\Screenshots\Screenshot (132).png"
*/

// Include Arduino Wire library for I2C
#include <Wire.h>

// Include Slave I2C Address
#define SLAVE_ADDR 9

// Analog pin for Potetionmeter
int analogPin = 0;

// Interger to hold potentiometer value
int val = 0;

void setup() {
  // put your setup code here, to run once:

  // Initializing I2C communication as Master
  Wire.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

  delay(50);

  //Read Pot or Potentiometer value
  // Map to range of 1-255 for flash rate
  val = map(analogRead(analogPin), 0, 1023, 255, 1);

  // Write a character to the Slave
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(val);
  Wire.endTransmission();
}
