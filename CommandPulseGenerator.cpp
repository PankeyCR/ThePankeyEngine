
#ifndef CommandPulseGenerator_cpp
#define CommandPulseGenerator_cpp

#include "CommandPulseGenerator.h"

	
	CommandPulseGenerator::CommandPulseGenerator(){
		this->timer = new MonkeyTime();
	}
	
	CommandPulseGenerator::~CommandPulseGenerator(){
		if(this->timer != nullptr){
			delete this->timer;
		}
	}
	
	void CommandPulseGenerator::Play(TimeControl *t){
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
	
	void CommandPulseGenerator::setPulseTime(long t){
		this->newtimepulse = t;
	}
	
	long CommandPulseGenerator::getPulseTime(){
		return this->timepulse;
	}
	
	MonkeyTime* CommandPulseGenerator::getMonkeyTime(){
		return this->timer;
	}
	
	void CommandPulseGenerator::setCommand(Command<CommandPulseGenerator>* cmd){
		this->command = cmd;
	}
	
	void CommandPulseGenerator::enable(bool e){
		this->en = e;
	}
	
#endif 