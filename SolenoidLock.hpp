
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef SolenoidLock_hpp
#define SolenoidLock_hpp

#ifndef ame_Enviroment_Defined
	#include "Arduino.h"
#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "DelaySensor.hpp"
#include "MonkeyTime.hpp"
#include "TimeRecorder.hpp"

namespace ame{

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

}

#endif 

#endif 
