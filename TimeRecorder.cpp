

#ifndef TimeRecorder_cpp
#define TimeRecorder_cpp

#include "TimeRecorder.h"

	TimeRecorder::TimeRecorder(){
			
	}
	TimeRecorder::~TimeRecorder(){
			
	}

	float TimeRecorder::record(float tick){
		this->recordtimeh+=tick;
	}

	float TimeRecorder::getRecord(){
		return this->recordtimeh;
	}

	void TimeRecorder::resetRecord(){
		this->recordtimeh=0;
	}

	void TimeRecorder::setRecord(float time){
		this->recordtimeh=time;
	}

	bool TimeRecorder::isNow(float time,float offset){
		return Now::is(TimeCheck::InBetween, this->getRecord(), time,offset);
	}

	bool TimeRecorder::isNow(TimeCheck check,float time,float offset){
		return Now::is(check, this->getRecord(), time,offset);
	}

	void TimeRecorder::operator=(const float& time){
		this->recordtimeh=time;
	}

	void TimeRecorder::operator+=(const float& tick){
		this->recordtimeh+=tick;
	}

	void TimeRecorder::operator-=(const float& tick){
		this->recordtimeh-=tick;
	}

	bool TimeRecorder::operator==(const float& time){
		return this->recordtimeh==time;
	}

	bool TimeRecorder::operator!=(const float& time){
		return this->recordtimeh!=time;
	}

	bool TimeRecorder::operator==(const float time[2]){
		return this->recordtimeh<=time[0]+time[1] && this->recordtimeh>=time[0]-time[1];
	}

	bool TimeRecorder::operator!=(const float time[2]){
		return this->recordtimeh>=time[0]+time[1] && this->recordtimeh<=time[0]-time[1];
	}

	bool TimeRecorder::operator<=(const float& time){
		return this->recordtimeh<=time;
	}

	bool TimeRecorder::operator>=(const float& time){
		return this->recordtimeh>=time;
	}

	bool TimeRecorder::operator<(const float& time){
		return this->recordtimeh<time;
	}

	bool TimeRecorder::operator>(const float& time){
		return this->recordtimeh>time;
	}


#endif 
