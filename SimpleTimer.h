
#ifndef SimpleTimer_h
#define SimpleTimer_h

#include "TimeControl.h"
#include "TimeElapsed.h"
#include "List.h"
#include "PrimitiveList.h"
#include "Logger.h"


#if defined(ARDUINO_ARCH_AVR)
	#include <avr/interrupt.h>
	#include <avr/io.h>

#elif defined(ARDUINO_ARCH_SAM)
  // SAM-specific code
#else
  // generic, non-platform specific code
#endif

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
		virtual String getClassName();
    
	private:
		static TimeControl *instance;
		
		SimpleTimer();
	 
	
};


#endif 