
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef DigitalRead_hpp
#define DigitalRead_hpp

#include "Arduino.h"
#include "AbstractRead.hpp"

namespace ame{

class DigitalRead : public AbstractRead{
  public:    
		DigitalRead(int pin){
			this->Rpin = pin;
			pinMode(pin,INPUT);
		}
		virtual ~DigitalRead(){}
		virtual void Read(){
			this->read = digitalRead(this->Rpin);
		}
  private:
		int Rpin=0;
};

}

#endif

#endif 
