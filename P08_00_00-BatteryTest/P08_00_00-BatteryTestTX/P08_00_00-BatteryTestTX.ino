/*
  P08_00_00-BatteryTestTX
  Project: P08_00_00 Tiny HyrdoBeacon
  Schematic: P08_00_00-BatteryTest.fzz

  Description: Testing running the ATtiny85 on 3.7V and sending
  the battery voltage reading
*/
#include <VirtualWire.h>
#include <SystemStatus.h>
SystemStatus status;

//Define pins
const int PinTX = 0;

//Define variables
unsigned char SensorID = 123;
int SensorVal = 0;
int BatVal = 1023;
String Message;
char CharMessage[16];

void setup()
{
  //Setup transmitter
  vw_set_tx_pin(PinTX);
  vw_setup(300);   // Bits per sec
}

void loop()
{
  //Read battery level
  BatVal = status.getVCC();
  
  //Make message
  Message = String(SensorID) + "," + String(SensorVal) + "," + String(BatVal);
  Message.toCharArray(CharMessage, Message.length()+1);
  
  //Send message
  vw_send((uint8_t *)CharMessage, strlen(CharMessage));
  vw_wait_tx(); // Wait until the whole message is gone
  delay(200);
}

/*
***** ROLL THE CREDITS *****
>> GENERAL <<
 * VirtualWire tutorial                         https://www.pjrc.com/teensy/td_libs_VirtualWire.html
 * Converting a uint8_t array into char array   https://forum.arduino.cc/index.php?topic=288726.0
 * Copy part of and array to another            https://forum.arduino.cc/index.php?topic=274173.0
 * Use VCC pin to read voltage                  https://electronics.stackexchange.com/questions/154523/attiny85-measuring-internal-voltage
 * How to use SystemStatus library              https://github.com/safchain/harg/blob/4da56f12a3e28881dfe192c8654c1492bb92f24f/examples/ct-sensor-attiny85.ino
***** Thanks everyone! ***** 
*/
