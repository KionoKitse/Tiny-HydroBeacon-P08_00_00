/*
  P08_00_00-MessageTestTX
  Project: P08_00_00 Tiny HyrdoBeacon
  Schematic: P08_00_00-MessageTest.fzz

  Description: Testing sending a formated message using the
  VirtualWire library and ATtiny85
*/
#include <VirtualWire.h>

//Define pins
const int PinTX = 0;

//Define variables
unsigned char SensorID = 244;
int SensorVal = 1024;
int BatVal = 1023;
String Message;
char CharMessage[20];

void setup()
{
  //Setup transmitter
  vw_set_tx_pin(PinTX);
  vw_setup(300);   // Bits per sec

  //Make message
  Message = String(SensorID) + "," + String(SensorVal) + "," + String(BatVal);
  Message.toCharArray(CharMessage, 20);
}

void loop()
{
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
***** Thanks everyone! ***** 
*/
