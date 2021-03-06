### Description  
P08_00_00 Tiny HydroBeacon
A wireless soil moisture sensor for house plants 
 * Wireless RF communication
 * Battery powered
 * Charge level monitoring

### Notes to user
 * Project documented at https://kionokitse.wordpress.com/tiny-hydrobeacon/
 
#### Folders
 * P08_00_00-VirtualWireTest
	* Testing using VirtualWire with ATtiny85 using example sketch
	* Working
 * P08_00_00-MessageTest
	* Format sample sensor values
	* Transmit using VirtualWire library
	* Receive message and print as char array
	* Working
 * P08_00_00-BatteryTest
	* Use SystemStatus library to read VCC voltage without additional pins
	* Format sample sensor values
	* Transmit using VirtualWire library
	* Receive message and print as char array
	* Working

### Hardware
 * ATtiny85
 * 433MHz Transmitter MX-F01
 * 433MHz Receiver MX-RM-5V
 * 1200mAh 3.7V LiPo battery LP503562
 * LiPo Charger Adafruit MicroLipo
 
### Progress log 
 * 2020-05-29 Working on programming ATtiny85 with Arduino UNO
 * 2020-06-01 Got ATtiny85 working properly 
 * 2020-06-02 Testing 433MHz Manchester library
 * 2020-06-08 Solder in LiPo charger and charging tests
 * 2020-06-09 Upload project to GitHub
 * 2020-06-09 Testing VirtualWire library on ATtiny85
 * 2020-06-09 Got sample VirtualWire sketch working needed to use 300 bits/sec
 * 2020-06-11 Sending a message using CSV formatting
 * 2020-06-11 Testing ATtiny85 at 1MHz (Works) 
 * 2020-06-11 Reading the battery level test (Successful)
 * 2020-06-13 Looking for power sources LiPo looks interesting
 * 2020-06-13 CR2477 > LIR2477 battery looks interesting charging might be an issue
 * 2020-06-13 Each sensor will require a 433MHz transmitter might be an issue since I won't need a bunch of receivers
 * 2020-06-14 Considering design ideas
 * 2020-06-14 P08_01_00 might be possible without a transmitter but how to program individually and adjust
 * 2020-06-17 Testing transmission ranges ~one room no walls
 * 2020-06-18 Testing power usage for power source 0.8174sec @ ~200mA  -> 200mA * 0.8174(1 per hr)/(60*60) -> 0.4541 mAh
 
### What's next
 * Determine battery usage
 * Decide on power source
 * Mechanical design
 * Testing soil sensor
 * Order battery
 * Battery charging
 * Sleep mode
 
 
### Notebook
 * Battery life could be extended if the system only started transmitting a signal if the soil moisture level was low.
 * 2000 bits/sec on the VirtualWire library is too fast 300 bits per second worked well I have not checked if faster rates works as well
 * Message formatting is SensorID,SensorVal,BatVal
 
 * ATtiny85 and 433MHz tutorial that worked		https://www.instructables.com/id/Attiny85-RF-Transmitter-to-Arduino-Uno-Receiver-Ma/?utm_source=base&utm_medium=related-instructables&utm_campaign=related_test
 * VirtualWire tutorial							https://www.pjrc.com/teensy/td_libs_VirtualWire.html
 * A library for reading VCC level directly		https://github.com/cano64/ArduinoSystemStatus
 * A library to put ATtiny85 to sleep			https://www.reddit.com/r/arduino/comments/6bf6go/i_wrote_a_library_to_put_an_attiny254585_to_deep/
 * Battery life calculator						https://www.omnicalculator.com/other/battery-life

### Additional tasks
 * Tutorial for programming ATtiny85 and pro mini
 * Tutorial for ATtiny85 and 433MHz
 
