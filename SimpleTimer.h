
#ifndef SimpleTimer_h
#define SimpleTimer_h

#include "TimeControl.h"
#include "TimeElapsed.hpp"
#include "List.hpp"
#include "PrimitiveList.hpp"
#include "cppObjectClass.hpp"


#if defined(ARDUINO_ARCH_AVR)
	#include <avr/interrupt.hpp>
	#include <avr/io.hpp>

#elif defined(ARDUINO_ARCH_SAM)
  // SAM-specific code
#else
  // generic, non-platform specific code
#endif

namespace ame{

class Application;
#define RESOLUTION 65536

class SimpleTimer : public TimeControl{
    public:
		unsigned char clockSelectBits;
		char oldSREG;
		
		virtual ~SimpleTimer();
		
		static TimeControl *getInstance();
		
		virtual TimeControl* initialize(long timeperiod);
		virtual TimeControl* setPeriod(long timeperiod);
		
		TimeControl* attachInterrupt();
		TimeControl* detachInterrupt();
		TimeControl* startInterrupt();
		TimeControl* stopInterrupt();
		TimeControl* resumeInterrupt();
		
		virtual String toString();
		virtual cppObjectClass* getClass();
    
	private:
		static TimeControl *instance;
		
		SimpleTimer();
		
		#if defined(ARDUINO_ESP32_DEV)
		hw_timer_t * timer = nullptr;
		#endif
};

}

#endif 