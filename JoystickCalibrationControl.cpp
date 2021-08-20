
#ifndef JoystickCalibrationControl_cpp
#define JoystickCalibrationControl_cpp

#include "JoystickCalibrationControl.h"
	
	ame::JoystickCalibrationControl::JoystickCalibrationControl(){
		
	}
	
	ame::JoystickCalibrationControl::~JoystickCalibrationControl(){
		
	}
	
	bool ame::JoystickCalibrationControl::isValidControl(){
		if(this->parent == nullptr){
			return false;
		}
		return this->parent->getClass() == ame::Class<AnalogJoystick>::classType;
	}
	
	ame::cppObjectClass* ame::JoystickCalibrationControl::getClass(){
		return ame::Class<ame::JoystickCalibrationControl>::classType;
	}
	
	String ame::JoystickCalibrationControl::toString(){
		return "JoystickCalibrationControl";
	}
	
	ame::JoystickCalibrationControl *ame::JoystickCalibrationControl::clone(){
		ame::JoystickCalibrationControl *control = new ame::JoystickCalibrationControl();
		control->parent = this->parent;
		return control;
	}
	
	ame::AnalogJoystick *ame::JoystickCalibrationControl::getJoystick(){
		if(!this->isValidControl()){
			return nullptr;
		}
		return (AnalogJoystick*)this->parent;
	}
	
	void ame::JoystickCalibrationControl::update(float tpc){
		if(!this->isValidControl()){
			((ame::GameObject*)this->parent)->detach(this->getClass());
			return;
		}
		ame::Joystick *joystick= this->getJoystick();
		joystick->setOrigin(analogRead(joystick->getPinX()),analogRead(joystick->getPinY()));
		delete ((ame::GameObject*)this->parent)->detach(this->getClass());
	}
	
	
	
#endif 
