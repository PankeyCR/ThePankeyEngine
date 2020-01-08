

#ifndef TimeControl_h
#define TimeControl_h

#include "Arduino.h"
#include "MonkeyTime.h"
#include "cppObject.h"

class Application;

class TimeControl : public cppObject{
    public:
		TimeControl();
		virtual ~TimeControl();
		virtual MonkeyTime *getMonkeyTime();
		virtual String toString();
		virtual String getClassName();
		
	protected:
		MonkeyTime *time;
	
};


#endif 
