

#ifndef LightSensor_cpp
#define LightSensor_cpp

#include "LightSensor.h"

	LightSensor::LightSensor(){
		
	}
	LightSensor::~LightSensor(){
		
	}
	
	LightSensor* LightSensor::monkeytime(MonkeyTime* tim){
		this->timer = tim;
		return this;
	}
	
	LightSensor* LightSensor::delay(float tm){
		this->timing = tm;
		return this;
	}
	
	LightSensor* LightSensor::offset(float tm){
		this->offsetm = tm;
		return this;
	}
	
	LightSensor* LightSensor::timecheck(TimeCheck tm){
		this->timecheckm = tm;
		return this;
	}
	
	LightSensor* LightSensor::close(){
		this->state = false;
		return this;
	}
	
	LightSensor* LightSensor::open(){
		this->state = true;
		return this;
	}
	
	void LightSensor::update(){
		if(this->timer == nullptr){
			return;
		}
		this->value = analogRead(this->slpin);
		if(this->value > this->limitt){
			openRecorder+=this->timer->getTPC();
			closeRecorder.resetRecord();
			this->closem = false;
		}else{
			closeRecorder+=this->timer->getTPC();
			openRecorder.resetRecord();
			this->openm = false;
		}
		if(openRecorder.isNow(this->timecheckm,this->timing,this->offsetm)){
			this->openm = true;
		}
		if(closeRecorder.isNow(this->timecheckm,this->timing,this->offsetm)){
			this->closem = true;
		}
	}
	LightSensor* LightSensor::attach(int pin){
		this->slpin = pin;
		pinMode(this->slpin , INPUT);
		return this;
	}
	LightSensor* LightSensor::limit(int lm){
		this->limitt = lm;
		return this;
	}
	int LightSensor::getValue(){
		return this->value;
	}
#endif 
