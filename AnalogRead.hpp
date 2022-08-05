
#include "ame_Enviroment.hpp"

#if defined(DISABLE_AnalogRead)
	#define AnalogRead_hpp
#endif

#ifndef AnalogRead_hpp
#define AnalogRead_hpp
#define AnalogRead_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "AbstractRead.hpp"

namespace ame{
	
class AnalogRead : public AbstractRead{
	public:
		AnalogRead(int pin){
			this->Rpin = pin;
			pinMode(pin,INPUT);
		}
		virtual ~AnalogRead(){}
		virtual void Read(){
			this->read = analogRead(this->Rpin);
		}
	private:
		int Rpin=0;
};

}

#endif
