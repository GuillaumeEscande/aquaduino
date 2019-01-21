#include "Arduino.h"
#include "logger.h"

#include <SPI.h>
#include <SD.h>

File logFile;
File dataFile;

Logger::Logger(){
}


void Logger::init(){
  SD.begin(4);
  logFile = SD.open("log.txt", FILE_WRITE);
  dataFile = SD.open("data.txt", FILE_WRITE);
}

void Logger::run() {
}

void Logger::log(const String& log){
  logFile.write(log);
}
void Logger::saveData(const String& data){
  logFile.write(data);
}


String  Logger::toString(){
  return "Logger : " + '\n';
}
