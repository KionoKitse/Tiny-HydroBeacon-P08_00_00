/*
  P08_00_00-BatteryTestRX
  Project: P08_00_00 Tiny HyrdoBeacon
  Schematic: P08_00_00-BatteryTest.fzz

  Description: Testing running the ATtiny85 on 3.7V and sending
  the battery voltage reading
*/

#include <VirtualWire.h>

//Define pins
const int PinRX = 9;

//Define variables
char CharMessage[16];
void setup()
{
  //Serial output
  Serial.begin(9600); 
  Serial.println("setup");

  //Setup receiver
  vw_set_rx_pin(PinRX);
  vw_setup(300);  // Bits per sec
  vw_rx_start();  // Start the receiver PLL running
}

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    // Turn on LED
    digitalWrite(13, true); 

    //Print message
    memcpy(CharMessage, buf, buflen); //Copy valid part of buffer to message
    Serial.println((char*) CharMessage); //Convert message into char array
    memset(CharMessage, 0, sizeof(CharMessage));

    //Turn off led
    digitalWrite(13, false);
  }
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
