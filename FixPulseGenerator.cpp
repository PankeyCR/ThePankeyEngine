
#ifndef FixPulseGenerator_cpp
#define FixPulseGenerator_cpp

#include "FixPulseGenerator.h"

	
	FixPulseGenerator::FixPulseGenerator(){
		this->timer = new MonkeyTime();
		this->timer->start();
	}
	
	FixPulseGenerator::~FixPulseGenerator(){
		if(this->timer != nullptr){
			delete this->timer;
		}
	}
	
	void FixPulseGenerator::Play(TimeControl *t){
		if(!this->en){
			return;
		}
		if(this->statePulse){
			if(this->timer->getTime() >= this->highTime){
				digitalWrite(this->pin, HIGH);
				this->statePulse = false;
				this->highTime = this->newhighTime;
				this->timer->restart();
			}
		}else{
			if(this->timer->getTime() >= this->lowTime){
				digitalWrite(this->pin, LOW);
				this->statePulse = true;
				this->lowTime = this->newlowTime;
				this->timer->restart();
			}
		}
		this->timer->computeTime();
		Serial.println(this->timer->getTime());
	}
	
	void FixPulseGenerator::setPin(int p){
		pinMode(pin, OUTPUT);
		this->pin = p;
	}
	
	void FixPulseGenerator::setHighTime(long t){
		this->newhighTime = t;
	}
	
	void FixPulseGenerator::forceHighTime(long t){
		this->highTime = t;
		this->timer->restart();
	}
	
	long FixPulseGenerator::getHighTime(){
		return this->highTime;
	}
	
	void FixPulseGenerator::setLowTime(long t){
		this->newlowTime = t;
	}
	
	void FixPulseGenerator::forceLowTime(long t){
		this->lowTime = t;
		this->timer->restart();
	}
	
	long FixPulseGenerator::getLowTime(){
		return this->lowTime;
	}
	
	bool FixPulseGenerator::isHigh(){
		return this->statePulse;
	}
	
	MonkeyTime* FixPulseGenerator::getMonkeyTime(){
		return this->timer;
	}
	
	void FixPulseGenerator::enable(bool e){
		this->en = e;
	}
	
#endif 