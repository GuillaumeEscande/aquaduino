#include "Arduino.h"
#include "temp.h"

#include <OneWire.h>

const byte BROCHE_ONEWIRE = 7;

enum DS18B20_RCODES {
  READ_OK,  // Lecture ok
  NO_SENSOR_FOUND,  // Pas de capteur
  INVALID_ADDRESS,  // Adresse reçue invalide
  INVALID_SENSOR  // Capteur invalide (pas un DS18B20)
};

OneWire ds(BROCHE_ONEWIRE);

Temperature::Temperature():{
  temperatue = read();
}


void Temperature::init(){

}

void Temperature::run() {

}

int Temperature::read() {
  return temperatue;
}


int Temperature::get() {
  return temperatue;
}

String  Temperature::toString(){
  return "Temperature : " + '\n';
}
