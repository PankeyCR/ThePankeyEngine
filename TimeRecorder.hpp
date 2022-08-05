
#include "ame_Enviroment.hpp"

#if defined(DISABLE_TimeRecorder)
	#define TimeRecorder_hpp
#endif

#ifndef TimeRecorder_hpp
#define TimeRecorder_hpp
#define TimeRecorder_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Now.hpp"
#include "TimeCheck.hpp"

namespace ame{

#define isRecorder() 
class TimeRecorder {
    public:		
		TimeRecorder(){}
		virtual ~TimeRecorder(){}
		
		virtual float record(float tick){
			this->recordtimeh+=tick;
		}

		virtual float getRecord(){
			return this->recordtimeh;
		}

		virtual void resetRecord(){
			this->recordtimeh=0;
		}

		virtual void setRecord(float time){
			this->recordtimeh=time;
		}

		virtual bool isNow(float time,float offset){
			return Now::is(TimeCheck::InBetween, this->getRecord(), time,offset);
		}

		virtual bool isNow(TimeCheck check,float time,float offset){
			return Now::is(check, this->getRecord(), time,offset);
		}


		virtual void operator =(const float& time){
			this->recordtimeh=time;
		}

		virtual void operator +=(const float& tick){
			this->recordtimeh+=tick;
		}

		virtual void operator -=(const float& tick){
			this->recordtimeh-=tick;
		}

		virtual bool operator ==(const float& time){
			return this->recordtimeh==time;
		}

		virtual bool operator !=(const float& time){
			return this->recordtimeh!=time;
		}

		virtual bool operator ==(const float time[2]){
			return this->recordtimeh<=time[0]+time[1] && this->recordtimeh>=time[0]-time[1];
		}

		virtual bool operator !=(const float time[2]){
			return this->recordtimeh>=time[0]+time[1] && this->recordtimeh<=time[0]-time[1];
		}

		virtual bool operator <=(const float& time){
			return this->recordtimeh<=time;
		}

		virtual bool operator >=(const float& time){
			return this->recordtimeh>=time;
		}

		virtual bool operator <(const float& time){
			return this->recordtimeh<time;
		}

		virtual bool operator >(const float& time){
			return this->recordtimeh>time;
		}
    
	protected:	
		float recordtimeh = 0.0f;
};

}

#endif