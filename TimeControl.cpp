
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
	
	void TimeControl::setScale(TimeScale scale){
		if(scale == TimeScale::MicroSecond){
			this->scale = 1l;
			return;
		}
		if(scale == TimeScale::MilliSecond){
			this->scale = 1000l;
			return;
		}
		if(scale == TimeScale::CentiSecond){
			this->scale = 10000l;
			return;
		}
		if(scale == TimeScale::DeciSecond){
			this->scale = 100000l;
			return;
		}
		if(scale == TimeScale::Second){
			this->scale = 1000000l;
			return;
		}
		if(scale == TimeScale::DecaSecond){
			this->scale = 10000000l;
			return;
		}
		if(scale == TimeScale::HectoSecond){
			this->scale = 100000000l;
			return;
		}
		if(scale == TimeScale::KiloSecond){
			this->scale = 1000000000l;
			return;
		}
	}
	
	long TimeControl::getTime() {
		return this->time;
	}
	
	void TimeControl::initialize(long timeperiod){
	}

	void TimeControl::setPeriod(long timeperiod){
	}

	void TimeControl::attachInterrupt(){										
	}

	void TimeControl::detachInterrupt(){
	}

	void TimeControl::startInterrupt(){
	}

	void TimeControl::stopInterrupt(){
	}

	void TimeControl::resumeInterrupt(){
	}
	
	TimeElapsed *TimeControl::add(TimeElapsed *t){
		this->timeList->add(t);
		return t;
	}
	
	TimeElapsed *TimeControl::remove(TimeElapsed *t){
		return this->timeList->remove(t);
	}
	
	TimeElapsed *TimeControl::removeByPos(int pos){
		return this->timeList->removeByPos(pos);
	}
		
	List<TimeElapsed> *TimeControl::getTimeElapsedList(){
		return this->timeList;
	}
	
	TimeElapsed *TimeControl::getTimeElapsed(int pos){
		return this->timeList->getByPos(pos);
	}
	
	TimeElapsed *TimeControl::getTimeElapsed(TimeElapsed *t){
		return this->timeList->get(t);
	}
	
	
	String TimeControl::toString() {
		return "TimeControl";
	}
	
	String TimeControl::getClassName() {
		return "TimeControl";
	}


#endif