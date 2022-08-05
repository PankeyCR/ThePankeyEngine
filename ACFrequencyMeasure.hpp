
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ACFrequencyMeasure)
	#define ACFrequencyMeasure_hpp
#endif

#ifndef ACFrequencyMeasure_hpp
#define ACFrequencyMeasure_hpp
#define ACFrequencyMeasure_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "AbstractRead.hpp"

namespace ame{

class ACFrequencyMeasure : public AbstractRead{
	public:
		ACFrequencyMeasure(){
			this->read=-1;
		}
		virtual ~ACFrequencyMeasure(){
			
		}
		virtual void setPin(int pin){
			this->freqPin = pin;
		}
		virtual void Read(){
			this->actualTime = micros();
			this->read = 1.0f/(float)((this->actualTime-this->prevTime))*1000000;
			this->prevTime = this->actualTime;
		}
	protected:
		long prevTime = 0;
		long actualTime = 0;
		int freqPin = -1;
};

}

#endif