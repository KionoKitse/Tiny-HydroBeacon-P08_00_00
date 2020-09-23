/*
   P07_00_00-Main
   Project: P07_00_00 Raindrop Bob
*/
//Sleep mode
#include <tinysnore.h>

//Global variables
int SensorVal;

//Define pins
#define SensorPin 4
#define SetPin 1
#define SensorPwr 3
#define LedPin 0

void setup() {
  //Set pin status
  pinMode(SensorPin, INPUT);
  pinMode(SetPin, INPUT);
  pinMode(SensorPwr, OUTPUT);
  pinMode(LedPin, OUTPUT);

}

void loop() {
  //Check sensor
  CheckSensors();
  DispResults();
  snore(60000);
}

void CheckSensors() {
  digitalWrite(SensorPwr, HIGH);
  delay(200);
  SensorVal = analogRead(SensorPin);
  digitalWrite(SensorPwr, LOW);
}

void DispResults(){
  if(SensorVal < 1023)
  {
    for (int i=0; i<30; i++)
    {
      digitalWrite(LedPin,HIGH);
      delay(1000);
      digitalWrite(LedPin,LOW);
      snore(1000);
    }
  }
}


/*
***** ROLL THE CREDITS *****
  >> WriteToSD <<
   SD tutorial example sketch   https://www.arduino.cc/en/Tutorial/ReadWrite
   DIY Arduino SD card reader   https://www.instructables.com/id/Cheap-Arduino-SD-Card-Reader/
   DIY SD card Reader           https://nathan.chantrell.net/20111128/diy-micro-sd-shield-for-arduino/
   DIY capacitive sensor        https://www.instructables.com/id/Building-a-Capacitive-Liquid-Sensor/
***** Thanks everyone! *****
*/
