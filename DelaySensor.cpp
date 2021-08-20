

#ifndef DelaySensor_cpp
#define DelaySensor_cpp

#include "DelaySensor.h"

	ame::DelaySensor::~DelaySensor(){
		
	}
	
	ame::DelaySensor* ame::DelaySensor::monkeytime(ame::MonkeyTime* tim){
		this->timer = tim;
		return this;
	}
	
	ame::DelaySensor* ame::DelaySensor::delay(float tm){
		this->timing = tm;
		return this;
	}
	
	ame::DelaySensor* ame::DelaySensor::offset(float tm){
		this->offsetm = tm;
		return this;
	}
	
	ame::DelaySensor* ame::DelaySensor::timecheck(TimeCheck tm){
		this->timecheckm = tm;
		return this;
	}
	
	ame::DelaySensor* ame::DelaySensor::close(){
		this->state = false;
		return this;
	}
	
	ame::DelaySensor* ame::DelaySensor::open(){
		this->state = true;
		return this;
	}
	
	void ame::DelaySensor::update(){
		if(this->timer == nullptr){
			return;
		}
		if(this->state==true){
			openRecorder+=this->timer->getTPC();
			closeRecorder.resetRecord();
		}
		if(this->state==false){
			closeRecorder+=this->timer->getTPC();
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
	
	ame::DelaySensor* ame::DelaySensor::attach(int pin){
		this->slpin = pin;
		return this;
	}
	
	bool ame::DelaySensor::isClose(){
		return this->closem;
	}
	
	bool ame::DelaySensor::isOpen(){
		return this->openm;
	}
	
	float ame::DelaySensor::closeTime(){
		return this->openRecorder.getRecord();
	}
	
	float ame::DelaySensor::openTime(){
		return this->closeRecorder.getRecord();
	}
#endif 
