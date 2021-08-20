
#ifndef CommandPulseGenerator_cpp
#define CommandPulseGenerator_cpp

#include "CommandPulseGenerator.h"

	
	ame::CommandPulseGenerator::CommandPulseGenerator(){
		this->timer = new MonkeyTime();
	}
	
	ame::CommandPulseGenerator::~CommandPulseGenerator(){
		if(this->timer != nullptr){
			delete this->timer;
		}
	}
	
	void ame::CommandPulseGenerator::Play(ame::TimeControl *t){
		if(!this->en){
			return;
		}
		if(this->timer->getTime() >= this->timepulse){
			if(this->command != nullptr){
				this->command->execute(this);
			}
			this->timepulse = this->newtimepulse;
			this->timer->restart();
		}
		this->timer->computeTime();
		Serial.println(this->timer->getTime());
	}
	
	void ame::CommandPulseGenerator::setPulseTime(long t){
		this->newtimepulse = t;
	}
	
	long ame::CommandPulseGenerator::getPulseTime(){
		return this->timepulse;
	}
	
	ame::MonkeyTime* ame::CommandPulseGenerator::getMonkeyTime(){
		return this->timer;
	}
	
	void ame::CommandPulseGenerator::setCommand(Command<CommandPulseGenerator>* cmd){
		this->command = cmd;
	}
	
	void ame::CommandPulseGenerator::enable(bool e){
		this->en = e;
	}

#endif 