

/*
  P08_00_00-BatteryTestTX
  Project: P08_00_00 Tiny HyrdoBeacon
  Schematic: P08_00_00-BatteryTest.fzz

  Description: Testing running the ATtiny85 on 3.7V and sending
  the battery voltage reading
*/
#include <tinysnore.h>
#include <VirtualWire.h>
#include <SystemStatus.h>
SystemStatus status;

//Define pins
const int PinTX = 0;
#define PwrSensor 3  //Pin to turn on moisture sensor 01
#define Sensor A2  //Pin to read moisture sensor 01


//Define variables
unsigned char SensorID = 123;
int SensorVal = 0;
int BatVal = 0;
String Message;
char CharMessage[20];

void setup()
{
  //Setup transmitter
  vw_set_tx_pin(PinTX);
  vw_setup(300);   // Bits per sec

  //Setup pins
  pinMode(PwrSensor, OUTPUT);
  pinMode(Sensor, INPUT);
  digitalWrite(PwrSensor, LOW);
}

void loop()
{
  //Read battery level
  BatVal = status.getVCC();

  //Read sensor
  CheckSensor();
  
  //Send message
  SendMessage();
  delay(200);
  SendMessage();
  delay(200);
  SendMessage();
  delay(200);
  

}

void CheckSensor() {
  //Sensor value total
  int Total = 0;

  //Check sensor five times
  for (byte i = 0; i < 5; i++) {
    digitalWrite(PwrSensor, HIGH);
    delay(100);
    Total = Total + analogRead(Sensor);
    digitalWrite(PwrSensor, LOW);
    delay(100);
  }
  
  //Calculate average
  SensorVal = Total / 5;
}

void SendMessage(){
  //Make message
  Message = String(SensorID) + "," + String(SensorVal) + "," + String(BatVal);
  Message.toCharArray(CharMessage, Message.length()+1);

  //Send message
  vw_send((uint8_t *)CharMessage, strlen(CharMessage));
  vw_wait_tx(); // Wait until the whole message is gone
}
/*
***** ROLL THE CREDITS *****
>> GENERAL <<
 * VirtualWire tutorial                         https://www.pjrc.com/teensy/td_libs_VirtualWire.html
 * Converting a uint8_t array into char array   https://forum.arduino.cc/index.php?topic=288726.0
 * Copy part of and array to another            https://forum.arduino.cc/index.php?topic=274173.0
 * Use VCC pin to read voltage                  https://electronics.stackexchange.com/questions/154523/attiny85-measuring-internal-voltage
 * How to use SystemStatus library              https://github.com/safchain/harg/blob/4da56f12a3e28881dfe192c8654c1492bb92f24f/examples/ct-sensor-attiny85.ino
 * Put ATtiny85 to sleep                        https://github.com/connornishijima/TinySnore
***** Thanks everyone! ***** 
*/
