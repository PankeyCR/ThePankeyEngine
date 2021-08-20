

#ifndef TimeRecorder_cpp
#define TimeRecorder_cpp

#include "TimeRecorder.h"

	ame::TimeRecorder::TimeRecorder(){
			
	}
	ame::TimeRecorder::~TimeRecorder(){
			
	}

	float ame::TimeRecorder::record(float tick){
		this->recordtimeh+=tick;
	}

	float ame::TimeRecorder::getRecord(){
		return this->recordtimeh;
	}

	void ame::TimeRecorder::resetRecord(){
		this->recordtimeh=0;
	}

	void ame::TimeRecorder::setRecord(float time){
		this->recordtimeh=time;
	}

	bool ame::TimeRecorder::isNow(float time,float offset){
		return Now::is(TimeCheck::InBetween, this->getRecord(), time,offset);
	}

	bool ame::TimeRecorder::isNow(TimeCheck check,float time,float offset){
		return Now::is(check, this->getRecord(), time,offset);
	}

	void ame::TimeRecorder::operator=(const float& time){
		this->recordtimeh=time;
	}

	void ame::TimeRecorder::operator+=(const float& tick){
		this->recordtimeh+=tick;
	}

	void ame::TimeRecorder::operator-=(const float& tick){
		this->recordtimeh-=tick;
	}

	bool ame::TimeRecorder::operator==(const float& time){
		return this->recordtimeh==time;
	}

	bool ame::TimeRecorder::operator!=(const float& time){
		return this->recordtimeh!=time;
	}

	bool ame::TimeRecorder::operator==(const float time[2]){
		return this->recordtimeh<=time[0]+time[1] && this->recordtimeh>=time[0]-time[1];
	}

	bool ame::TimeRecorder::operator!=(const float time[2]){
		return this->recordtimeh>=time[0]+time[1] && this->recordtimeh<=time[0]-time[1];
	}

	bool ame::TimeRecorder::operator<=(const float& time){
		return this->recordtimeh<=time;
	}

	bool ame::TimeRecorder::operator>=(const float& time){
		return this->recordtimeh>=time;
	}

	bool ame::TimeRecorder::operator<(const float& time){
		return this->recordtimeh<time;
	}

	bool ame::TimeRecorder::operator>(const float& time){
		return this->recordtimeh>time;
	}


#endif 
