

#ifndef SolenoidLock_cpp
#define SolenoidLock_cpp

#include "SolenoidLock.h"

	ame::SolenoidLock::SolenoidLock(){
		
	}
	ame::SolenoidLock::~SolenoidLock(){
		
	}
	
	ame::SolenoidLock* ame::SolenoidLock::monkeytime(ame::MonkeyTime* tim){
		this->timer = tim;
		return this;
	}
	
	ame::SolenoidLock* ame::SolenoidLock::delay(float tm){
		this->timing = tm;
		return this;
	}
	
	ame::SolenoidLock* ame::SolenoidLock::offset(float tm){
		this->offsetm = tm;
		return this;
	}
	
	ame::SolenoidLock* ame::SolenoidLock::timecheck(TimeCheck tm){
		this->timecheckm = tm;
		return this;
	}
	ame::SolenoidLock* ame::SolenoidLock::attach(int pin){
		this->slpin = pin;
		pinMode(this->slpin, OUTPUT);
		return this;
	}
	ame::SolenoidLock* ame::SolenoidLock::close(){
		this->state = false;
		this->closem = false;
		this->openm = false;
		digitalWrite(this->slpin,LOW);
		return this;
	}
	ame::SolenoidLock* ame::SolenoidLock::open(){
		this->state = true;
		this->closem = false;
		this->openm = false;
		digitalWrite(this->slpin,HIGH);
		return this;
	}
#endif 
