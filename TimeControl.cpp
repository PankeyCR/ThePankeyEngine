
#ifndef TimeControl_cpp
#define TimeControl_cpp

#include "TimeControl.h"


	TimeControl::TimeControl() {
		this->timeList = new PrimitiveList<TimeElapsed>();
		Log("TimeControl", "Constructor", "println","TimeControl: new instance of this class");
	}
	
	TimeControl::~TimeControl() {
		delete this->timeList;
		Log("TimeControl", "Destructor", "println","TimeControl: delete instance of this class");
	}
	
	long TimeControl::getTime() {
		return this->time;
	}
	
	TimeControl* TimeControl::initialize(long timeperiod){
		return this;
	}

	TimeControl* TimeControl::setPeriod(long timeperiod){
		return this;
	}
	
	long TimeControl::getPeriod(){
		return this->period;
	}

	TimeControl* TimeControl::attachInterrupt(){
		return this;										
	}

	TimeControl* TimeControl::detachInterrupt(){
		return this;
	}

	TimeControl* TimeControl::startInterrupt(){
		return this;
	}

	TimeControl* TimeControl::stopInterrupt(){
		return this;
	}

	TimeControl* TimeControl::resumeInterrupt(){
		return this;
	}
	
	TimeElapsed *TimeControl::add(TimeElapsed *t){
		this->timeList->addPointer(t);
		return t;
	}
	
	TimeElapsed *TimeControl::remove(TimeElapsed *t){
		if(this->timeList == nullptr){
			return nullptr;
		}
		return this->timeList->removeByPointer(t);
	}
	
	TimeElapsed *TimeControl::removeByPos(int pos){
		if(this->timeList == nullptr){
			return nullptr;
		}
		return this->timeList->removeByPosition(pos);
	}
		
	List<TimeElapsed> *TimeControl::getTimeElapsedList(){
		if(this->timeList == nullptr){
			return nullptr;
		}
		return this->timeList;
	}
	
	TimeElapsed *TimeControl::getTimeElapsed(int pos){
		if(this->timeList == nullptr){
			return nullptr;
		}
		return this->timeList->getByPosition(pos);
	}
	
	TimeElapsed *TimeControl::getTimeElapsed(TimeElapsed *t){
		if(this->timeList == nullptr){
			return nullptr;
		}
		return this->timeList->getByPointer(t);
	}
	
	
	String TimeControl::toString() {
		return "TimeControl";
	}
	
	String TimeControl::getClassName() {
		return "TimeControl";
	}


#endif