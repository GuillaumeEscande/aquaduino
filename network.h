
#ifndef Reseau_h
#define Reseau_h

#include "Arduino.h"

class Network{
  private :
    byte mac[6];
    
  public :
    Network();
    void init();
    void run();

    String toString();
  
};



#endif
