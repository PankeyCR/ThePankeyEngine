

#ifndef TimeRecorder_h
#define TimeRecorder_h

#include "Arduino.h"
#include "Now.h"
#include "TimeCheck.h"

#define isRecorder() 
class TimeRecorder {
    public:		
		TimeRecorder();
		virtual ~TimeRecorder();
		
		virtual float record(float tick);
		virtual float getRecord();
		virtual void resetRecord();
		virtual void setRecord(float time);
		virtual bool isNow(float time,float offset);
		virtual bool isNow(TimeCheck check,float time,float offset);

		virtual void operator =(const float& time);
		virtual void operator +=(const float& tick);
		virtual void operator -=(const float& tick);
		virtual bool operator ==(const float& time);
		virtual bool operator !=(const float& time);
		virtual bool operator ==(const float time[2]);
		virtual bool operator !=(const float time[2]);
		virtual bool operator <=(const float& time);
		virtual bool operator >=(const float& time);
		virtual bool operator <(const float& time);
		virtual bool operator >(const float& time);
    
	protected:	
		float recordtimeh = 0.0f;
};


#endif 
