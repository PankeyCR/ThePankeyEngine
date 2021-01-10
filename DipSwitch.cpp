
#ifndef DipSwitch_cpp
#define DipSwitch_cpp

#include "DipSwitch.h"


	DipSwitch::DipSwitch(){
		pinList = new ArrayList<int,10>();
	}
	
	int DipSwitch::getValue(){
		
		return value;
	}
	
	void DipSwitch::addPin(int pin){
		pinList->addLValue(pin);
	}
    
	int DipSwitch::operator &(){
		return value;
	}
    
	void DipSwitch::operator =(const DipSwitch& d){
		DipSwitch nd;
		nd.value = d.value;
			
	}
	
    void DipSwitch::operator =(const int& t){
		value = t;
	}
    
	bool DipSwitch::operator ==(const int& t){
		this->readPins();
		return this->value==t;
	}
    
	bool DipSwitch::operator !=(const int& t){
		this->readPins();
		return this->value!=t;
	}
    
	void DipSwitch::onDelete(){
		pinList->onDelete();
		delete this;
	}
    
	void DipSwitch::readPins(){
		value = 0;
		for(int x =0; x < pinList->getPosition(); x++){
			value += digitalRead(*pinList->getByPosition(x)) * pow(2,x);
		}
	}
	
	
#endif 
