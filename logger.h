
#ifndef Logger_h
#define Logger_h

#include "Arduino.h"

class Logger{
  private :
    
  public :
    Logger();
    void init();
    void run();

    void log(const String& log);
    void saveData(const String& data);

    String toString(); 
};



#endif
