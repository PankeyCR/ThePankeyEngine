

#ifndef ServoDoor_h
#define ServoDoor_h

#include "Arduino.h"
#include "DelaySensor.h"
#include "MonkeyTime.h"
#include <Servo.h> 

class ServoDoor : public DelaySensor{
	protected:
		Servo servo;
		int oAngle = 180;
		int cAngle = 0;
		
    public:
		ServoDoor();
		virtual ~ServoDoor();
		virtual ServoDoor* attach(int pin);
		virtual ServoDoor* closeAngle(int angle);
		virtual ServoDoor* openAngle(int angle);
		virtual ServoDoor* close();
		virtual ServoDoor* open();
		virtual ServoDoor* monkeytime(MonkeyTime* tim);
		virtual ServoDoor* delay(float tm);
		virtual ServoDoor* offset(float tm);
		virtual ServoDoor* timecheck(TimeCheck tm);
		
};

#endif 
