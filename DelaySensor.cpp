

#ifndef DelaySensor_cpp
#define DelaySensor_cpp

#include "DelaySensor.h"

	DelaySensor::~DelaySensor(){
		
	}
	
	DelaySensor* DelaySensor::monkeytime(MonkeyTime* tim){
		this->timer = tim;
		return this;
	}
	
	DelaySensor* DelaySensor::delay(float tm){
		this->timing = tm;
		return this;
	}
	
	DelaySensor* DelaySensor::offset(float tm){
		this->offsetm = tm;
		return this;
	}
	
	DelaySensor* DelaySensor::timecheck(TimeCheck tm){
		this->timecheckm = tm;
		return this;
	}
	
	DelaySensor* DelaySensor::close(){
		this->state = false;
		return this;
	}
	
	DelaySensor* DelaySensor::open(){
		this->state = true;
		return this;
	}
	
	void DelaySensor::update(){
		if(this->timer == nullptr){
			return;
		}
		if(this->state==true){
			openRecorder+=this->timer->getScaleTPC();
			closeRecorder.resetRecord();
		}
		if(this->state==false){
			closeRecorder+=this->timer->getScaleTPC();
			openRecorder.resetRecord();
		}
		if(this->state==unknown){
			openRecorder.resetRecord();
			closeRecorder.resetRecord();
		}
		if(openRecorder.isNow(this->timecheckm,this->timing,this->offsetm)){
			this->openm = true;
		}
		if(closeRecorder.isNow(this->timecheckm,this->timing,this->offsetm)){
			this->closem = true;
		}
	}
	
	DelaySensor* DelaySensor::attach(int pin){
		this->slpin = pin;
		return this;
	}
	
	bool DelaySensor::isClose(){
		return this->closem;
	}
	
	bool DelaySensor::isOpen(){
		return this->openm;
	}
#endif 
