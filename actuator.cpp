#include "Arduino.h"
#include "actuator.h"
#include <EEPROM.h>


#define ACTUATOR_ADDR 0x100

#define SYSTEM_PORT 39
#define PUMP_PORT 41
#define RESISTOR_PORT 43
#define OXYGEN_PORT 45
#define LIGHT_PORT 47

GPIO_Port::GPIO_Port(const uint8_t& _port, const bool& _initialState) {
  port = _port;
  pinMode(port, OUTPUT);
  set(state);
}

bool GPIO_Port::get() {
  return state;
}

void GPIO_Port::set(const bool& value) {
  state = 0x01 & value;
  if(state)
    digitalWrite(port, HIGH);
  else
    digitalWrite(port, LOW);
}

String GPIO_Port::toString() {
  if ( state ){
    return "true";
  } else {
    return "false";
  }
}


Actuator::Actuator():system(SYSTEM_PORT, true), pump(PUMP_PORT, true), resistor(RESISTOR_PORT, true), oxygen(OXYGEN_PORT, true), light(LIGHT_PORT, true){}


void Actuator::init(){
  Actuator self;
  EEPROM.get(ACTUATOR_ADDR, self);
  pump.set(self.getPump());
  light.set(self.getSystem());
  resistor.set(self.getResistor());
  oxygen.set(self.getOxygen());
  light.set(self.getLight());
}

void Actuator::run() {
  
}

void Actuator::setPump(const bool& state){
  pump.set(state);
  EEPROM.put(ACTUATOR_ADDR, (*this));
}

bool Actuator::getPump(){
  return pump.get();
}

void Actuator::setResistor(const bool& state){
  resistor.set(state);
  EEPROM.put(ACTUATOR_ADDR, (*this));
}

bool Actuator::getResistor(){
  return resistor.get();
}

void Actuator::setOxygen(const bool& state){
  oxygen.set(state);
  EEPROM.put(ACTUATOR_ADDR, (*this));
}

bool Actuator::getOxygen(){
  return oxygen.get();
}

void Actuator::setLight(const bool& state){
  light.set(state);
  EEPROM.put(ACTUATOR_ADDR, (*this));
}

bool Actuator::getLight(){
  return light.get();
}

void Actuator::setSystem(const bool& state){
  system.set(state);
  EEPROM.put(ACTUATOR_ADDR, (*this));
}

bool Actuator::getSystem(){
  return system.get();
}

String Actuator::toString(){
  return "Actuator : system=" + system.toString() + ", pump=" + pump.toString() + ", resistor=" + resistor.toString() + ", oxygen=" + oxygen.toString() + ", light=" + light.toString() + "\n";
}
