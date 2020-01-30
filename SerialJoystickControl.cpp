
#ifndef SerialJoystickControl_cpp
#define SerialJoystickControl_cpp

#include "SerialJoystickControl.h"
	
	SerialJoystickControl::SerialJoystickControl(){
		
	}
	
	bool SerialJoystickControl::isValidControl(){
		if(this->parent == nullptr){
			return false;
		}
		bool valid=false;
		if(this->parent->getClassName() == "SerialJoystickparent"){
			valid = true;
			connection = (SerialConnection*)this->parent;
			joystick = (AnalogJoystick*)this->parent;			
		}
		if(((GameObject*)this->parent)->getChild("SerialConnection") != nullptr 
			&& ((GameObject*)this->parent)->getChild("AnalogJoystick") != nullptr ){
			valid = true;
			connection = (SerialConnection*)((GameObject*)this->parent)->getChild("SerialConnection");
			joystick = (AnalogJoystick*)((GameObject*)this->parent)->getChild("AnalogJoystick");
		}
		return valid;
	}
	
	String SerialJoystickControl::getClassName(){
		return "SerialJoystickControl";
	}
	
	String SerialJoystickControl::toString(){
		return "SerialJoystickControl";
	}
	
	SerialJoystickControl *SerialJoystickControl::clone(){
		SerialJoystickControl *control = new SerialJoystickControl();
		control->parent = this->parent;
		return control;
	}
	
	Joystick *SerialJoystickControl::getJoystick(){
		return joystick;
	}
	
	SerialConnection *SerialJoystickControl::getSerial(){
		return connection;
	}
	
	void SerialJoystickControl::update(float tpc){
		
	}
	
	
	
#endif 
