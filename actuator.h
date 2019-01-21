
#ifndef Contacteur_h
#define Contacteur_h

#include "Arduino.h"


class GPIO_Port{
  private:
    uint8_t port;
    bool state;
  public:
    GPIO_Port(const uint8_t& port, const bool& initialState);
    bool get ();
    void set(const bool& copy);

    String toString();
};

class Actuator{
  private :
    GPIO_Port pump;
    GPIO_Port resistor;
    GPIO_Port oxygen;
    GPIO_Port light;
    GPIO_Port system;
    
  public :
    Actuator();
    void init();
    void run();

    void setPump(const bool& state);
    bool getPump();

    void setResistor(const bool& state);
    bool getResistor();

    void setOxygen(const bool& state);
    bool getOxygen();

    void setLight(const bool& state);
    bool getLight();

    void setSystem(const bool& state);
    bool getSystem();

    String toString();
  
};



#endif
