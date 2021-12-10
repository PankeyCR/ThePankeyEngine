
#ifndef MonofasicAngleTrigger_hpp
#define MonofasicAngleTrigger_hpp

#ifndef ame_Enviroment_Defined
	#include "Arduino.h"
#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "ACFrequencyMeasure.hpp"
#include "TimeControl.hpp"
#include "TimeElapsed.hpp"

namespace ame{

class MonofasicAngleTrigger : public ACFrequencyMeasure , public TimeElapsed {
    public:
		MonofasicAngleTrigger(){
		}
		
		virtual ~MonofasicAngleTrigger(){
		}
		
		virtual void Read(){
			this->actualTime = micros();
			this->read = 1.0f/(float)((this->actualTime-this->prevTime))*1000000;
			this->prevTime = this->actualTime;
			this->triggerTimer = 0;
			digitalWrite(this->trigger, LOW);
		}
		
		template<int pin>
		void setTriggerPin(){
			this->trigger = pin;
			pinMode(this->trigger, OUTPUT);
		}
		
		virtual void Play(TimeControl *t){
			if(this->triggerTimer >= this->angleTriggerTime){
				digitalWrite(this->trigger, HIGH);
			}
			if(this->doEnding){
				if(this->triggerTimer >= this->angleStopTime){
					digitalWrite(this->trigger, LOW);
				}
			}
			this->triggerTimer++;
		}
		
		virtual void endReading(){
			digitalWrite(this->trigger, LOW);
		}
		
		template<int frequency, int period, int angleStart>
		void setAngle(){
			this->angleTriggerTime = ((float)(((1.0f/frequency)/period)*1000000l)/180.0f)*angleStart;
			Serial.println("trigger "+String(this->angleTriggerTime));
			this->doEnding = false;
		}
		
		template<int frequency, int period, int angleStart, int angleStop>
		void setAngles(){
			this->angleTriggerTime = ((float)(((1.0f/frequency)/period)*1000000l)/180.0f)*angleStart;
			Serial.println("trigger "+String(this->angleTriggerTime));
			this->angleStopTime = ((float)(((1.0f/frequency)/period)*1000000l)/180.0f)*angleStop;
			Serial.println("stop "+String(this->angleStopTime));
			this->doEnding = true;
		}
		
		void setAngle(float frequency, float period, float angleStart){
			this->angleTriggerTime = ((float)(((1.0f/frequency)/period)*1000000l)/180.0f)*angleStart;
			Serial.println("trigger "+String(this->angleTriggerTime));
			this->doEnding = false;
		}
		
		void setAngles(float frequency, float period, float angleStart, float angleStop){
			this->angleTriggerTime = (((1.0f/frequency)/period)/180.0f)*angleStart;
			this->angleStopTime = (((1.0f/frequency)/period)/180.0f)*angleStop;
			this->doEnding = true;
		}
    
	protected:
		long angleTriggerTime = 100;
		long angleStopTime = 1000;
		int trigger = 3;
		long triggerTimer = 0;
		bool doEnding = true;
};

}

#endif 
