
#ifndef Clock_h
#define Clock_h

#include "Arduino.h"

class Clock{
  private :
    
  public :
    Clock();
    void init();
    void run();

    String toString(); 
};



#endif
