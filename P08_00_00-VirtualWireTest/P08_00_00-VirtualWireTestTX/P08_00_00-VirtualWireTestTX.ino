/*
  P08_00_00-VirtualWireTestTX
  Project: P08_00_00 Tiny HyrdoBeacon
  Schematic: P08_00_00-VirtualWireTest.fzz

  Description: Testing VirtualWire on ATtiny85
*/
#include <VirtualWire.h>

const int transmit_pin = 0;

void setup()
{
  // Initialise the IO and ISR
  vw_set_tx_pin(transmit_pin);
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(300);   // Bits per sec
}

byte count = 1;

void loop()
{
  char msg[7] = {'h','e','l','l','o',' ','#'};

  msg[6] = count;
  vw_send((uint8_t *)msg, 7);
  vw_wait_tx(); // Wait until the whole message is gone
  delay(1000);
  count = count + 1;
}

/*
***** ROLL THE CREDITS *****
>> GENERAL <<
 * VirtualWire tutorial		https://www.pjrc.com/teensy/td_libs_VirtualWire.html
***** Thanks everyone! ***** 
*/