
#ifndef TimeControl_cpp
#define TimeControl_cpp

#include "TimeControl.h"


	TimeControl::TimeControl() {
		this->timeList = new PrimitiveList<TimeElapsed>();
		Log("println","TimeControl: new instance of this class");
	}
	
	TimeControl::~TimeControl() {
		delete this->timeList;
		this->timeList = nullptr;
		Log("println","TimeControl: delete instance of this class");
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
		if(this->timeList == nullptr){
			return nullptr;
		}
		this->timeList->add(t);
		return t;
	}
	
	TimeElapsed *TimeControl::remove(TimeElapsed *t){
		if(this->timeList == nullptr){
			return nullptr;
		}
		return this->timeList->remove(t);
	}
	
	TimeElapsed *TimeControl::removeByPos(int pos){
		if(this->timeList == nullptr){
			return nullptr;
		}
		return this->timeList->removeByPos(pos);
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
		return this->timeList->getByPos(pos);
	}
	
	TimeElapsed *TimeControl::getTimeElapsed(TimeElapsed *t){
		if(this->timeList == nullptr){
			return nullptr;
		}
		return this->timeList->get(t);
	}
	
	
	String TimeControl::toString() {
		return "TimeControl";
	}
	
	String TimeControl::getClassName() {
		return "TimeControl";
	}


#endif