

#ifndef TimeControl_h
#define TimeControl_h

#include "Arduino.h"
#include "cppObject.h"
#include "PrimitiveList.h"
#include "List.h"
#include "TimeElapsed.h"
#include "Logger.h"

class Application;

class TimeControl : public cppObject{
    public:
		List<TimeElapsed> *timeList;
		long time=0;
		long period=0;
		
		TimeControl();
		virtual ~TimeControl();
		virtual long getTime();
		
		virtual TimeControl* initialize(long timeperiod);
		virtual TimeControl* setPeriod(long timeperiod);
		virtual long getPeriod();
		
		virtual TimeControl* attachInterrupt();
		virtual TimeControl* detachInterrupt();
		virtual TimeControl* startInterrupt();
		virtual TimeControl* stopInterrupt();
		virtual TimeControl* resumeInterrupt();
		
		virtual TimeElapsed *add(TimeElapsed *t);
		virtual TimeElapsed *remove(TimeElapsed *t);
		virtual TimeElapsed *removeByPos(int pos);
		 
		virtual List<TimeElapsed> *getTimeElapsedList();
		virtual TimeElapsed *getTimeElapsed(int pos);
		virtual TimeElapsed *getTimeElapsed(TimeElapsed *t);
				
		virtual String toString();
		virtual String getClassName();
		
	protected:
	
};


#endif 
