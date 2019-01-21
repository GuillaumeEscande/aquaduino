#include <Ethernet.h>
#include <SPI.h>

#include "network.h"
#include "actuator.h"
#include "temp.h"

#define ethernet_h_

// assign an IP address for the controller:

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):


Network network;
Actuator actuator;
Temperature temperature;

void setup() {
  
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  
  // put your setup code here, to run once:
  Serial.begin(9600);

  network.init();
  actuator.init();
  temperature.init();
}

void loop() {
  network.run();
  actuator.run();
  temperature.run();
}
