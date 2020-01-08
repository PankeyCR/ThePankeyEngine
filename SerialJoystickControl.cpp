
#ifndef SerialJoystickControl_cpp
#define SerialJoystickControl_cpp

#include "SerialJoystickControl.h"
	
	SerialJoystickControl::SerialJoystickControl(){
		
	}
	
	bool SerialJoystickControl::isValidControl(){
		if(this->object == nullptr){
			return false;
		}
		bool valid=false;
		if(this->object->getClassName() == "SerialJoystickObject"){
			valid = true;
			connection = (SerialConnection*)this->object;
			joystick = (AnalogJoystick*)this->object;			
		}
		if(this->object->getChild("SerialConnection") != nullptr 
			&& this->object->getChild("AnalogJoystick") != nullptr ){
			valid = true;
			connection = (SerialConnection*)this->object->getChild("SerialConnection");
			joystick = (AnalogJoystick*)this->object->getChild("AnalogJoystick");
		}
		return valid;
	}
	
	void SerialJoystickControl::onDelete(){
		delete this;
	}
	
	String SerialJoystickControl::getClassName(){
		return "SerialJoystickControl";
	}
	
	String SerialJoystickControl::toString(){
		return "SerialJoystickControl";
	}
	
	SerialJoystickControl *SerialJoystickControl::clone(){
		SerialJoystickControl *control = new SerialJoystickControl();
		control->object = this->object;
		return control;
	}
	
	Joystick *SerialJoystickControl::getJoystick(){
		return joystick;
	}
	
	SerialConnection *SerialJoystickControl::getSerial(){
		return connection;
	}
	
	void SerialJoystickControl::update(){
		
	}
	
	
	
#endif 
