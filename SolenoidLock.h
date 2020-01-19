

#ifndef SolenoidLock_h
#define SolenoidLock_h

#include "Arduino.h"
#include "DelaySensor.h"
#include "MonkeyTime.h"
#include "TimeRecorder.h"

class SolenoidLock : public DelaySensor{
	protected:
		
    public:
		SolenoidLock();
		virtual ~SolenoidLock();
		virtual SolenoidLock* attach(int pin);
		virtual SolenoidLock* monkeytime(MonkeyTime* tim);
		virtual SolenoidLock* delay(float tm);
		virtual SolenoidLock* offset(float tm);
		virtual SolenoidLock* timecheck(TimeCheck tm);
		virtual SolenoidLock* close();
		virtual SolenoidLock* open();
		
};

#endif 
