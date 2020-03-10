

#ifndef TimeControl_h
#define TimeControl_h

#include "Arduino.h"
#include "TimeScale.h"
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
		long scale=0;
		TimeControl();
		virtual ~TimeControl();
		virtual void setScale(TimeScale sc);
		virtual long getTime();
		
		virtual void initialize(long timeperiod);
		virtual void setPeriod(long timeperiod);
		
		virtual void attachInterrupt();
		virtual void detachInterrupt();
		virtual void startInterrupt();
		virtual void stopInterrupt();
		virtual void resumeInterrupt();
		
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
