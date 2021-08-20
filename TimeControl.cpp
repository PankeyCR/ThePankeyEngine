
#ifndef TimeControl_cpp
#define TimeControl_cpp

#include "TimeControl.h"


	ame::TimeControl::TimeControl() {
		this->timeList = new PrimitiveList<TimeElapsed>();
		Log("ame::TimeControl", "Constructor", "println","ame::TimeControl: new instance of this class");
	}
	
	ame::TimeControl::~TimeControl() {
		delete this->timeList;
		Log("ame::TimeControl", "Destructor", "println","ame::TimeControl: delete instance of this class");
	}
	
	long ame::TimeControl::getTime() {
		return this->time;
	}
	
	ame::TimeControl* ame::TimeControl::initialize(long timeperiod){
		return this;
	}

	ame::TimeControl* ame::TimeControl::setPeriod(long timeperiod){
		return this;
	}
	
	long ame::TimeControl::getPeriod(){
		return this->period;
	}

	ame::TimeControl* ame::TimeControl::attachInterrupt(){
		return this;										
	}

	ame::TimeControl* ame::TimeControl::detachInterrupt(){
		return this;
	}

	ame::TimeControl* ame::TimeControl::startInterrupt(){
		return this;
	}

	ame::TimeControl* ame::TimeControl::stopInterrupt(){
		return this;
	}

	ame::TimeControl* ame::TimeControl::resumeInterrupt(){
		return this;
	}
	
	ame::TimeElapsed *ame::TimeControl::add(ame::TimeElapsed *t){
		this->timeList->addPointer(t);
		return t;
	}
	
	ame::TimeElapsed *ame::TimeControl::remove(ame::TimeElapsed *t){
		if(this->timeList == nullptr){
			return nullptr;
		}
		return this->timeList->removeByPointer(t);
	}
	
	ame::TimeElapsed *ame::TimeControl::removeByPos(int pos){
		if(this->timeList == nullptr){
			return nullptr;
		}
		return this->timeList->removeByPosition(pos);
	}
		
	ame::List<ame::TimeElapsed> *ame::TimeControl::getTimeElapsedList(){
		if(this->timeList == nullptr){
			return nullptr;
		}
		return this->timeList;
	}
	
	ame::TimeElapsed *ame::TimeControl::getTimeElapsed(int pos){
		if(this->timeList == nullptr){
			return nullptr;
		}
		return this->timeList->getByPosition(pos);
	}
	
	ame::TimeElapsed *ame::TimeControl::getTimeElapsed(ame::TimeElapsed *t){
		if(this->timeList == nullptr){
			return nullptr;
		}
		return this->timeList->getByPointer(t);
	}
	
	
	String ame::TimeControl::toString() {
		return "ame::TimeControl";
	}
	
	ame::cppObjectClass* ame::TimeControl::getClass() {
		return ame::Class<ame::TimeControl>::classType;
	}


#endif