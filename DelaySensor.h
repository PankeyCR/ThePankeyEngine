

#ifndef DelaySensor_h
#define DelaySensor_h

#include "MonkeyTime.h"
#include "TimeRecorder.h"
#include "trilean.h"

class DelaySensor{
	protected:
		bool closem = false;
		bool openm = false;
		trilean state;
		float timing = 0;
		MonkeyTime* timer = nullptr;
		TimeRecorder openRecorder;
		TimeRecorder closeRecorder;
		TimeCheck timecheckm = TimeCheck::GreaterThan;
		float offsetm = 1.0f;
		int slpin=0;
		
    public:
		virtual ~DelaySensor();
		virtual DelaySensor* monkeytime(MonkeyTime* tim);
		virtual DelaySensor* delay(float tm);
		virtual DelaySensor* offset(float tm);
		virtual DelaySensor* timecheck(TimeCheck tm);
		virtual DelaySensor* close();
		virtual DelaySensor* open();
		virtual DelaySensor* attach(int pin);
		virtual void update();
		virtual bool isClose();
		virtual bool isOpen();
		virtual float closeTime();
		virtual float openTime();
		
};

#endif 
