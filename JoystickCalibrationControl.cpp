
#ifndef JoystickCalibrationControl_cpp
#define JoystickCalibrationControl_cpp

#include "JoystickCalibrationControl.h"
	
	JoystickCalibrationControl::JoystickCalibrationControl(){
		
	}
	
	JoystickCalibrationControl::~JoystickCalibrationControl(){
		
	}
	
	bool JoystickCalibrationControl::isValidControl(){
		if(this->parent == nullptr){
			return false;
		}
		return this->parent->getClassName() == "AnalogJoystick";
	}
	
	String JoystickCalibrationControl::getClassName(){
		return "JoystickCalibrationControl";
	}
	
	String JoystickCalibrationControl::toString(){
		return "JoystickCalibrationControl";
	}
	
	JoystickCalibrationControl *JoystickCalibrationControl::clone(){
		JoystickCalibrationControl *control = new JoystickCalibrationControl();
		control->parent = this->parent;
		return control;
	}
	
	AnalogJoystick *JoystickCalibrationControl::getJoystick(){
		if(!this->isValidControl()){
			return nullptr;
		}
		return (AnalogJoystick*)this->parent;
	}
	
	void JoystickCalibrationControl::update(float tpc){
		if(!this->isValidControl()){
			((GameObject*)this->parent)->detach(this->idm);
			return;
		}
		Joystick *joystick= this->getJoystick();
		joystick->setOrigin(analogRead(joystick->getPinX()),analogRead(joystick->getPinY()));
		delete ((GameObject*)this->parent)->detach(this->idm);
	}
	
	
	
#endif 
