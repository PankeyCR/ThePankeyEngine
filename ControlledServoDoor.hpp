

#ifndef ControlledServoDoor_hpp
#define ControlledServoDoor_hpp

#include "Arduino.h"
#include "DelaySensor.hpp"
#include "MonkeyTime.hpp"
#include "LinearController.hpp"
#include "KVMap.hpp"
#include <Servo.h> 
/*
class ControlledServoDoor : public DelaySensor{
	protected:
		Servo servo;
		LinearController* controllerm;
		Map<String,float>* controlmap;
		int oAngle = 180;
		int cAngle = 0;
		
    public:
		ControlledServoDoor();
		virtual ~ControlledServoDoor();
		virtual ControlledServoDoor* attach(int pin);
		virtual ControlledServoDoor* closeAngle(int angle);
		virtual ControlledServoDoor* openAngle(int angle);
		virtual ControlledServoDoor* close();
		virtual ControlledServoDoor* open();
		virtual ControlledServoDoor* monkeytime(MonkeyTime* tim);
		virtual ControlledServoDoor* delay(float tm);
		virtual ControlledServoDoor* offset(float tm);
		virtual ControlledServoDoor* input(int in);
		virtual ControlledServoDoor* timecheck(TimeCheck tm);
		virtual LinearController* controller();
		virtual Map<String,float>* control();
		virtual float angle();
		virtual float closetime();
		virtual float opentime();
		virtual void update(float tpc);
		
};
*/
#endif 
