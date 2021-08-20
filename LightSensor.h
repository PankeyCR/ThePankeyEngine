

#ifndef LightSensor_h
#define LightSensor_h

#include "Arduino.h"
#include "DelaySensor.h"
#include "MonkeyTime.h"

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
