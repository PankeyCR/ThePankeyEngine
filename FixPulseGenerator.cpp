
#ifndef FixPulseGenerator_cpp
#define FixPulseGenerator_cpp

#include "FixPulseGenerator.h"

	
	ame::FixPulseGenerator::FixPulseGenerator(){
		this->timer = new MonkeyTime();
		this->timer->start();
	}
	
	ame::FixPulseGenerator::~FixPulseGenerator(){
		if(this->timer != nullptr){
			delete this->timer;
		}
	}
	
	void ame::FixPulseGenerator::Play(TimeControl *t){
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
	
	void ame::FixPulseGenerator::setPin(int p){
		pinMode(pin, OUTPUT);
		this->pin = p;
	}
	
	void ame::FixPulseGenerator::setHighTime(long t){
		this->newhighTime = t;
	}
	
	void ame::FixPulseGenerator::forceHighTime(long t){
		this->highTime = t;
		this->timer->restart();
	}
	
	long ame::FixPulseGenerator::getHighTime(){
		return this->highTime;
	}
	
	void ame::FixPulseGenerator::setLowTime(long t){
		this->newlowTime = t;
	}
	
	void ame::FixPulseGenerator::forceLowTime(long t){
		this->lowTime = t;
		this->timer->restart();
	}
	
	long ame::FixPulseGenerator::getLowTime(){
		return this->lowTime;
	}
	
	bool ame::FixPulseGenerator::isHigh(){
		return this->statePulse;
	}
	
	ame::MonkeyTime* ame::FixPulseGenerator::getMonkeyTime(){
		return this->timer;
	}
	
	void ame::FixPulseGenerator::enable(bool e){
		this->en = e;
	}
	
#endif 