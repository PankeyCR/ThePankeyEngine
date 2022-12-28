
#ifndef DebounceInputAction_hpp
#define DebounceInputAction_hpp
#define DebounceInputAction_AVAILABLE

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "InputState.hpp"

#ifdef DebounceInput_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define DebounceInputLog(location,method,type,mns) ame_Log(nullptr,location,"Free Function",method,type,mns)
#else
	#ifdef DebounceInput_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define DebounceInputLog(location,method,type,mns) ame_LogDebug(nullptr,location,"Free Function",method,type)
	#else
		#define DebounceInputLog(location,method,type,mns) 
	#endif
#endif

namespace ame{

class DebounceInput : public Input{
	public:
	long time = 0;
	long time_limit = 100;
	long ready = true;

	DebounceInput(){}
	DebounceInput(long c_time_limit, int c_pin, bool c_inveted, bool c_state){
		pin = c_pin;
		inverted = c_inveted;
		state = c_state;
		time_limit = c_time_limit;
	}

	#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
	virtual cppObjectClass* getClass(){return Class<DebounceInput>::getClass();}
	virtual bool instanceof(cppObjectClass* cls){return cls == Class<DebounceInput>::getClass();}
	#endif

};

bool DebounceInputAction(int interrupt, long milli, DebounceInput* input){
	DebounceInputLog(ame_Log_StartMethod, "DebounceInputAction", "println", "");
	long i_time = milli - input->time;
	if(i_time > input->time_limit){
		input->ready = true;
	}
	if(!input->ready){
		return false;
	}
	input->time = milli;
	bool pinState = digitalRead(input->pin);
	if(pinState == input->state){
		return false;
	}
	input->time = milli;
	input->ready = false;
	input->state = pinState;
	DebounceInputLog(ame_Log_EndMethod, "DebounceInputAction", "println", "");
	return true;
}

}

#endif