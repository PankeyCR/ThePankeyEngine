

#ifndef SolenoidLock_cpp
#define SolenoidLock_cpp

#include "SolenoidLock.h"

	SolenoidLock::SolenoidLock(){
		
	}
	SolenoidLock::~SolenoidLock(){
		
	}
	
	SolenoidLock* SolenoidLock::monkeytime(MonkeyTime* tim){
		this->timer = tim;
		return this;
	}
	
	SolenoidLock* SolenoidLock::delay(float tm){
		this->timing = tm;
		return this;
	}
	
	SolenoidLock* SolenoidLock::offset(float tm){
		this->offsetm = tm;
		return this;
	}
	
	SolenoidLock* SolenoidLock::timecheck(TimeCheck tm){
		this->timecheckm = tm;
		return this;
	}
	SolenoidLock* SolenoidLock::attach(int pin){
		this->slpin = pin;
		pinMode(this->slpin, OUTPUT);
		return this;
	}
	SolenoidLock* SolenoidLock::close(){
		this->state = false;
		this->closem = false;
		this->openm = false;
		digitalWrite(this->slpin,LOW);
		return this;
	}
	SolenoidLock* SolenoidLock::open(){
		this->state = true;
		this->closem = false;
		this->openm = false;
		digitalWrite(this->slpin,HIGH);
		return this;
	}
#endif 
