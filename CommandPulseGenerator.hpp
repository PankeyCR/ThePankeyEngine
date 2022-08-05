
#include "ame_Enviroment.hpp"

#if defined(DISABLE_CommandPulseGenerator)
	#define CommandPulseGenerator_hpp
#endif

#ifndef CommandPulseGenerator_hpp
#define CommandPulseGenerator_hpp
#define CommandPulseGenerator_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "TimeControl.hpp"
#include "MonkeyTime.hpp"
#include "Command.hpp"

namespace ame{
	
class CommandPulseGenerator : public TimeElapsed, public Command<int>{
    public:
		CommandPulseGenerator(){
			this->timer = new MonkeyTime();
		}
		virtual ~CommandPulseGenerator(){
			if(this->timer != nullptr){
				delete this->timer;
			}
		}
	
		virtual void Play(TimeControl *t){
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
	
		virtual void setPulseTime(long t){
			this->newtimepulse = t;
		}
	
		virtual long getPulseTime(){
			return this->timepulse;
		}
		
		virtual MonkeyTime* getMonkeyTime(){
			return this->timer;
		}
	
		virtual void setCommand(Command<CommandPulseGenerator>* cmd){
			this->command = cmd;
		}
	
		virtual void enable(bool e){
			this->en = e;
		}
		
	protected:
		Command<CommandPulseGenerator>* command = nullptr;
		MonkeyTime *timer;
		long timepulse = 0;
		long newtimepulse = 0;
		bool en = true;
};

}

#endif