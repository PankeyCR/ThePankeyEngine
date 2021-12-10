

#ifndef RelayIncubator_hpp
#define RelayIncubator_hpp

#ifndef ame_Enviroment_Defined
	#include "Arduino.h"
#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Logger.hpp"
#include "Average.hpp"
#include "MetricScale.hpp"
#include "Application.hpp"
#include "AppState.hpp"
#include "TimeControl.hpp"
#include "TemperatureNTC.hpp"
#include "FixPulseGenerator.hpp"

namespace ame{
	
class RelayIncubator : public AppState{
    public:
		RelayIncubator(){
			this->temperature = new ame::TemperatureNTC();
			this->fanPulse = new ame::FixPulseGenerator();
			this->relayPulse = new ame::FixPulseGenerator();
			this->scale = new ame::MetricScale();
			this->average = new ame::Average<float>();
		}
		virtual ~RelayIncubator(){
			if(this->temperature != nullptr){
				delete this->temperature;
			}
			if(this->fanPulse != nullptr){
				delete this->fanPulse;
			}
			if(this->relayPulse != nullptr){
				delete this->relayPulse;
			}
			if(this->scale != nullptr){
				delete this->scale;
			}
			if(this->average != nullptr){
				delete this->average;
			}
		}
		
		virtual void setMaxTemperature(float t){
			this->maxT = t;
		}
		virtual void setTemeraturePin(int pin){
			pinMode(pin, INPUT);
			this->tpin = pin;
		}
		virtual void setRelayPin(int pin){
			this->relayPulse->setPin(pin);
		}
		virtual void setFanPin(int pin){
			this->fanPulse->setPin(pin);
		}
		
		virtual void initialize(Application *app){
			this->temperature->initialize();
			
			this->relayPulse->getMonkeyTime()->restart();
			app->getTimeControl()->add(this->relayPulse);
			
			this->fanPulse->getMonkeyTime()->restart();
			app->getTimeControl()->add(this->fanPulse);
			
			this->scale->setScaleTransform(ame::MetricPrefix::micro, ame::MetricPrefix::none);
			
			// this->relayPulse->enable(false);
			// this->fanPulse->enable(false);
			this->relayPulse->enable(true);
			this->fanPulse->enable(true);
			Log("ame::RelayIncubator", "initialize", "println","ame::RelayIncubator initialize");
		}
		virtual void update(){
			float temp = this->temperature->getTemperature(this->tpin);
			float deltaT = 0;
			
			this->average->addLValue(temp);
			if(this->average->getSize() >= 10){
				temp = this->average->getAverage();
				this->average->reset();
				deltaT = maxT-temp;
			}else{
				return;
			}
			Log("ame::RelayIncubator", "update", "print","temperature ");Log("ame::RelayIncubator", "update", "println",String(temp));
			
			if(temp < this->maxT){
				this->relayPulse->setHighTime(deltaT*this->scale->getValue(4));
				this->relayPulse->setLowTime(this->scale->getValue(4));
				
				this->fanPulse->setHighTime(this->scale->getValue(4));
				this->fanPulse->setLowTime(deltaT*this->scale->getValue(4));
			}else{
				this->relayPulse->setHighTime(this->scale->getValue(4));
				this->relayPulse->setLowTime(deltaT*this->scale->getValue(4));
				
				this->fanPulse->setHighTime(deltaT*this->scale->getValue(4));
				this->fanPulse->setLowTime(this->scale->getValue(4));
			}
		}
		
		cppObjectClass* getClass(){
			return ame::Class<ame::RelayIncubator>::classType;
		}
		String toString(){
			return "ame::RelayIncubator";
		}
		
	protected:
		MetricScale* scale;
		TemperatureNTC* temperature;
		FixPulseGenerator* fanPulse;
		FixPulseGenerator* relayPulse;
		int tpin = 0;
		float maxT = 38;
		Average<float>* average;
};

}

#endif 
