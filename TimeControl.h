

#ifndef TimeControl_h
#define TimeControl_h

#ifndef ame_Enviroment_Defined
	#include "Arduino.h"
#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "cppObject.hpp"
#include "PrimitiveList.hpp"
#include "List.hpp"
#include "TimeElapsed.hpp"

namespace ame{

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
		virtual cppObjectClass* getClass();
		
	protected:
	
};

}


#endif 
