

#ifndef DigitalRead_h
#define DigitalRead_h

#include "Arduino.h"
#include "AbstractRead.h"

namespace ame{

class DigitalRead : public AbstractRead{
  public:    
		DigitalRead(int pin);
		~DigitalRead();
		virtual void Read();
  private:
		int Rpin=0;
};

}

#endif 
