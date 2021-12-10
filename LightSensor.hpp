
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef LightSensor_h
#define LightSensor_h

#ifndef ame_Enviroment_Defined
	#include "Stream.h"
	#include "Arduino.h"
#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "DelaySensor.hpp"
#include "MonkeyTime.hpp"

namespace ame{

class LightSensor : public DelaySensor{
	protected:
		int value = 0;
		int limitt = 120;
		
    public:
		LightSensor();
		virtual ~LightSensor();
		virtual LightSensor* monkeytime(MonkeyTime* tim);
		virtual LightSensor* delay(float tm);
		virtual LightSensor* offset(float tm);
		virtual LightSensor* timecheck(TimeCheck tm);
		virtual LightSensor* close();
		virtual LightSensor* open();
		virtual LightSensor* attach(int pin);
		virtual LightSensor* limit(int lm);
		virtual int getValue();
		virtual void update();
};

}

#endif 

#endif 
