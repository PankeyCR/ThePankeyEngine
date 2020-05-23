

#ifndef FixPulseGenerator_h
#define FixPulseGenerator_h

#include "Arduino.h"
#include "TimeControl.h"
#include "MonkeyTime.h"

class FixPulseGenerator : public TimeElapsed, public Command<int>{
    public:
		FixPulseGenerator();
		virtual ~FixPulseGenerator();
		
		virtual void Play(TimeControl *t);
		virtual void setPin(int p);
		virtual void setHighTime(long t);
		virtual void forceHighTime(long t);
		virtual long getHighTime();
		virtual void setLowTime(long t);
		virtual void forceLowTime(long t);
		virtual long getLowTime();
		virtual bool isHigh();
		virtual MonkeyTime* getMonkeyTime();
		virtual void enable(bool en);
		
	protected:
		MonkeyTime *timer;
		bool statePulse = false;
		long highTime = 1;
		long lowTime = 1;
		long newhighTime = 1;
		long newlowTime = 1;
		long pin = 1;
		bool en = true;
};

#endif 
