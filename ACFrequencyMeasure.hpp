
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef ACFrequencyMeasure_hpp
#define ACFrequencyMeasure_hpp

#include "Arduino.h"
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

#endif 
