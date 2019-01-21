#include "Arduino.h"
#include "temp.h"

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

Temperature::Temperature():temperatue(0){
}


void Temperature::init(){
  sensors.begin();
}

void Temperature::run() {

}

int Temperature::read() {
  sensors.requestTemperatures();
  temperatue = sensors.getTempCByIndex(0);
  return temperatue;
}


int Temperature::get() {
  return temperatue;
}

String  Temperature::toString(){
  return "Temperature : " + '\n';
}
