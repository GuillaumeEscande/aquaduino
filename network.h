
#ifndef Reseau_h
#define Reseau_h

#include "Arduino.h"
#include <Ethernet.h>

class Network{
  private :
    EthernetServer server;
    byte mac[6];
    
  public :
    Network();
    void init();
    void run();

    String toString();
  
};



#endif
