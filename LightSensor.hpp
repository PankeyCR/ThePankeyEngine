
#include "ame_Enviroment.hpp"

#if defined(DISABLE_LightSensor)
	#define LightSensor_hpp
#endif

#ifndef LightSensor_hpp
#define LightSensor_hpp
#define LightSensor_AVAILABLE

#ifndef ame_Enviroment_Defined

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