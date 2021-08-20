
#ifndef DipSwitch_cpp
#define DipSwitch_cpp

#include "DipSwitch.h"


	ame::DipSwitch::DipSwitch(){
		pinList = new ArrayList<int,10>();
	}
	
	int ame::DipSwitch::getValue(){
		
		return value;
	}
	
	void ame::DipSwitch::addPin(int pin){
		pinList->addLValue(pin);
	}
    
	int ame::DipSwitch::operator &(){
		return value;
	}
    
	void ame::DipSwitch::operator =(const ame::DipSwitch& d){
		ame::DipSwitch nd;
		nd.value = d.value;
			
	}
	
    void ame::DipSwitch::operator =(const int& t){
		value = t;
	}
    
	bool ame::DipSwitch::operator ==(const int& t){
		this->readPins();
		return this->value==t;
	}
    
	bool ame::DipSwitch::operator !=(const int& t){
		this->readPins();
		return this->value!=t;
	}
    
	void ame::DipSwitch::onDelete(){
		pinList->onDelete();
		delete this;
	}
    
	void ame::DipSwitch::readPins(){
		value = 0;
		for(int x =0; x < pinList->getPosition(); x++){
			value += digitalRead(*pinList->getByPosition(x)) * pow(2,x);
		}
	}
	
	
#endif 
