
#ifndef SimpleTimer_h
#define SimpleTimer_h

#include "TimeControl.h"
#include "TimeElapsed.h"
#include "MonkeyTime.h"
#include "List.h"
#include "PrimitiveList.h"


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
		List<TimeElapsed> *timeList;
		
		virtual ~SimpleTimer();
		
		static TimeControl *getInstance();
		void initialize(float timeperiod);
		void setPeriod(float timeperiod);
		void attachInterrupt();
		void detachInterrupt();
		void startInterrupt();
		void stopInterrupt();
		void resumeInterrupt();
		
		TimeElapsed *add(TimeElapsed *t);
		TimeElapsed *remove(TimeElapsed *t);
		TimeElapsed *removeByPos(int pos);
		
		List<TimeElapsed> *getTimeElapsedList();
		TimeElapsed *getTimeElapsed(int pos);
		TimeElapsed *getTimeElapsed(TimeElapsed *t);
		
		int getTimeElapsedSize();
		
		virtual String toString();
		virtual String getClassName();
    
	private:
		static TimeControl *instance;
		
		SimpleTimer();
	 
	
};


#endif 