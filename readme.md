### Description  
P08_00_00 Tiny HydroBeacon
A wireless soil moisture sensor for house plants 
Wireless 433MHz ATtiny85 soil moisture sensor
* Wireless RF communication
* Battery powered
* Charge level monitoring

### Notes to user
 * Project documented at https://kionokitse.wordpress.com/tiny-hydrobeacon/
 * Main project is P08_00_00-Main
#### Folders
 * P08_00_00-VirtualWireTest
	* Testing using VirtualWire with ATtiny85 using example sketch
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
 
### What's next
 * Improving 433Mhz transmission
 * Message formatting
 * Determine battery usage
 * Decide on power source
 * Signal strength tests
 * Mechanical design
 
### Notebook
 * Battery life could be extended if the system only started transmitting a signal if the soil moisture level was low.
 * 2000 bits/sec on the VirtualWire library is too fast 300 bits per second worked well
 * ATtiny85 and 433MHz tutorial that worked		https://www.instructables.com/id/Attiny85-RF-Transmitter-to-Arduino-Uno-Receiver-Ma/?utm_source=base&utm_medium=related-instructables&utm_campaign=related_test
 * Send a string message Manchester				https://github.com/IrvinPoncePerez/Door-Man_System/blob/639ece5c9c1ce5d513985b7bd781983dad9640e1/arduino/Transmitter/Transmitter_ino/Transmitter_ino.ino
 * Receive a string message	Manchester			https://github.com/IrvinPoncePerez/Door-Man_System/blob/639ece5c9c1ce5d513985b7bd781983dad9640e1/arduino/Receiver/Receiver_ino/Receiver_ino.ino
 * VirtualWire tutorial							https://www.pjrc.com/teensy/td_libs_VirtualWire.html
 
### Additional tasks
 * Tutorial for programming ATtiny85 and pro mini
 * Tutorial for ATtiny85 and 433MHz
 
