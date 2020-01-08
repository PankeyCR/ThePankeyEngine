
#ifndef JoystickCalibrationControl_cpp
#define JoystickCalibrationControl_cpp

#include "JoystickCalibrationControl.h"
	
	JoystickCalibrationControl::JoystickCalibrationControl(){
		
	}
	
	JoystickCalibrationControl::~JoystickCalibrationControl(){
		
	}
	
	bool JoystickCalibrationControl::isValidControl(){
		if(this->object == nullptr){
			return false;
		}
		return this->object->getClassName() == "AnalogJoystick";
	}
	
	void JoystickCalibrationControl::onDelete(){
		delete this;
	}
	
	String JoystickCalibrationControl::getClassName(){
		return "JoystickCalibrationControl";
	}
	
	String JoystickCalibrationControl::toString(){
		return "JoystickCalibrationControl";
	}
	
	JoystickCalibrationControl *JoystickCalibrationControl::clone(){
		JoystickCalibrationControl *control = new JoystickCalibrationControl();
		control->object = this->object;
		return control;
	}
	
	AnalogJoystick *JoystickCalibrationControl::getJoystick(){
		if(!this->isValidControl()){
			return nullptr;
		}
		return (AnalogJoystick*)this->object;
	}
	
	void JoystickCalibrationControl::update(){
		if(!this->isValidControl()){
			this->object->removeControl(this);
			return;
		}
		Joystick *joystick= this->getJoystick();
		joystick->setOrigin(analogRead(joystick->getPinX()),analogRead(joystick->getPinY()));
		delete this->object->removeControl(this);
	}
	
	
	
#endif 
