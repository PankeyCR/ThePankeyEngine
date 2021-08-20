

#ifndef ServoDoor_cpp
#define ServoDoor_cpp

#include "ServoDoor.h"

	ame::ServoDoor::ServoDoor(){
		
	}
	ame::ServoDoor::~ServoDoor(){
		
	}
	
	ame::ServoDoor* ame::ServoDoor::monkeytime(ame::MonkeyTime* tim){
		this->timer = tim;
		return this;
	}
	
	ame::ServoDoor* ame::ServoDoor::delay(float tm){
		this->timing = tm;
		return this;
	}
	
	ame::ServoDoor* ame::ServoDoor::offset(float tm){
		this->offsetm = tm;
		return this;
	}
	
	ame::ServoDoor* ame::ServoDoor::timecheck(ame::TimeCheck tm){
		this->timecheckm = tm;
		return this;
	}
	ame::ServoDoor* ame::ServoDoor::attach(int pin){
		this->slpin = pin;
		this->servo.attach(pin);
		return this;
	}
	ame::ServoDoor* ame::ServoDoor::close(){
		this->state = false;
		this->closem = false;
		this->openm = false;
		this->servo.write(this->cAngle);
		return this;
	}
	ame::ServoDoor* ame::ServoDoor::open(){
		this->state = true;
		this->closem = false;
		this->openm = false;
		this->servo.write(this->oAngle);
		return this;
	}
	ame::ServoDoor* ame::ServoDoor::openAngle(int angle){
		this->oAngle = angle;
		return this;
	}
	ame::ServoDoor* ame::ServoDoor::closeAngle(int angle){
		this->cAngle = angle;
		return this;
	}
#endif 
