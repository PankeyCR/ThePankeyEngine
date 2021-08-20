

#ifndef LightSensor_cpp
#define LightSensor_cpp

#include "LightSensor.h"

	ame::LightSensor::LightSensor(){
		
	}
	ame::LightSensor::~LightSensor(){
		
	}
	
	ame::LightSensor* ame::LightSensor::monkeytime(ame::MonkeyTime* tim){
		this->timer = tim;
		return this;
	}
	
	ame::LightSensor* ame::LightSensor::delay(float tm){
		this->timing = tm;
		return this;
	}
	
	ame::LightSensor* ame::LightSensor::offset(float tm){
		this->offsetm = tm;
		return this;
	}
	
	ame::LightSensor* ame::LightSensor::timecheck(TimeCheck tm){
		this->timecheckm = tm;
		return this;
	}
	
	ame::LightSensor* ame::LightSensor::close(){
		this->state = false;
		return this;
	}
	
	ame::LightSensor* ame::LightSensor::open(){
		this->state = true;
		return this;
	}
	
	void ame::LightSensor::update(){
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
	ame::LightSensor* ame::LightSensor::attach(int pin){
		this->slpin = pin;
		pinMode(this->slpin , INPUT);
		return this;
	}
	ame::LightSensor* ame::LightSensor::limit(int lm){
		this->limitt = lm;
		return this;
	}
	int ame::LightSensor::getValue(){
		return this->value;
	}
#endif 
