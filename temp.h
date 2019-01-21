
#ifndef Temp_h
#define Temp_h

#include "Arduino.h"

class Temperature{
  private :
    int temperatue;

    int read();
    
  public :
    Temperature();
    void init();
    void run();

    String toString();

    int get();
  
};



#endif
