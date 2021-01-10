
#ifndef RelayIncubator_cpp
#define RelayIncubator_cpp

#include "RelayIncubator.h"

	
	RelayIncubator::RelayIncubator(){
		this->temperature = new TemperatureNTC();
		this->fanPulse = new FixPulseGenerator();
		this->relayPulse = new FixPulseGenerator();
		this->scale = new MetricScale();
		this->average = new Average<float>();
	}
	
	RelayIncubator::~RelayIncubator(){
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
	
	void RelayIncubator::setMaxTemperature(float t){
		this->maxT = t;
	}
	
	void RelayIncubator::setTemeraturePin(int pin){
		pinMode(pin, INPUT);
		this->tpin = pin;
	}
	
	void RelayIncubator::setRelayPin(int pin){
		this->relayPulse->setPin(pin);
	}
	
	void RelayIncubator::setFanPin(int pin){
		this->fanPulse->setPin(pin);
	}
	
	String RelayIncubator::getClassName(){
		return "RelayIncubator";
	}
	
	String RelayIncubator::toString(){
		return "RelayIncubator";
	}
	
	void RelayIncubator::initialize(Application *app){
		this->temperature->initialize();
		
		this->relayPulse->getMonkeyTime()->restart();
		app->getTimeControl()->add(this->relayPulse);
		
		this->fanPulse->getMonkeyTime()->restart();
		app->getTimeControl()->add(this->fanPulse);
		
		this->scale->setScaleTransform(MetricPrefix::micro, MetricPrefix::none);
		
		// this->relayPulse->enable(false);
		// this->fanPulse->enable(false);
		this->relayPulse->enable(true);
		this->fanPulse->enable(true);
		Log("RelayIncubator", "initialize", "println","RelayIncubator initialize");
	}
	
	void RelayIncubator::update(){
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
		Log("RelayIncubator", "update", "print","temperature ");Log("RelayIncubator", "update", "println",String(temp));
		
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
	
#endif 