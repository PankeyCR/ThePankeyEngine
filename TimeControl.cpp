
#ifndef TimeControl_cpp
#define TimeControl_cpp

#include "TimeControl.h"


	TimeControl::TimeControl() {
		this->time = new MonkeyTime();
	}
	
	TimeControl::~TimeControl() {
		delete this->time;
		this->time = nullptr;
	}
	
	void TimeControl::setScale(TimeScale scale){
		this->time->setScale(scale);
	}
	
	MonkeyTime *TimeControl::getMonkeyTime() {
		return time;
	}
	
	String TimeControl::toString() {
		return "TimeControl";
	}
	
	String TimeControl::getClassName() {
		return "TimeControl";
	}


#endif