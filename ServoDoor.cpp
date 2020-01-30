

#ifndef ServoDoor_cpp
#define ServoDoor_cpp

#include "ServoDoor.h"

	ServoDoor::ServoDoor(){
		
	}
	ServoDoor::~ServoDoor(){
		
	}
	
	ServoDoor* ServoDoor::monkeytime(MonkeyTime* tim){
		this->timer = tim;
		return this;
	}
	
	ServoDoor* ServoDoor::delay(float tm){
		this->timing = tm;
		return this;
	}
	
	ServoDoor* ServoDoor::offset(float tm){
		this->offsetm = tm;
		return this;
	}
	
	ServoDoor* ServoDoor::timecheck(TimeCheck tm){
		this->timecheckm = tm;
		return this;
	}
	ServoDoor* ServoDoor::attach(int pin){
		this->slpin = pin;
		this->servo.attach(pin);
		return this;
	}
	ServoDoor* ServoDoor::close(){
		this->state = false;
		this->closem = false;
		this->openm = false;
		this->servo.write(this->cAngle);
		return this;
	}
	ServoDoor* ServoDoor::open(){
		this->state = true;
		this->closem = false;
		this->openm = false;
		this->servo.write(this->oAngle);
		return this;
	}
	ServoDoor* ServoDoor::openAngle(int angle){
		this->oAngle = angle;
		return this;
	}
	ServoDoor* ServoDoor::closeAngle(int angle){
		this->cAngle = angle;
		return this;
	}
#endif 
