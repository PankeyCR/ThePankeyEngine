
#include "ame_Enviroment.hpp"

#if defined(DISABLE_DigitalRead)
	#define DigitalRead_hpp
#endif

#ifndef DigitalRead_hpp
#define DigitalRead_hpp
#define DigitalRead_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

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