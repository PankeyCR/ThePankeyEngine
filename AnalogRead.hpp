
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef AnalogRead_hpp
#define AnalogRead_hpp

#include "Arduino.h"
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

#endif 
