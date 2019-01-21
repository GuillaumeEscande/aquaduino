#include "Arduino.h"
#include "clock.h"

#include <Wire.h>
#include <RTClib.h>

RTC_DS1307 rtc;

Clock::Clock(){
  Wire.begin();
  rtc.begin();
  if (! rtc.isrunning()) {  
    rtc.adjust(DateTime(__DATE__, __TIME__));
  }
}


void Clock::init(){
}

void Clock::run() {
}


String  Clock::toString(){
  return "Clock : " + '\n';
}
