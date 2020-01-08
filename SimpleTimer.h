
#ifndef SimpleTimer_h
#define SimpleTimer_h

#include "TimeControl.h"
#include "TimeElapsed.h"
#include "MonkeyTime.h"
#include "List.h"
#include "PList.h"
#include <avr/io.h>
#include <avr/interrupt.h>

class Application;
#define RESOLUTION 65536

class SimpleTimer : public TimeControl{
    public:
		
		unsigned char clockSelectBits;
		char oldSREG;
		long _micros=1000000;
		List<TimeElapsed> *timeList;
		
		virtual ~SimpleTimer();
		
		static TimeControl *getInstance();
		void initialize(long microsec=1000000);
		void setPeriod(long microsec=1000000);
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