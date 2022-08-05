	
#include "ame_Enviroment.hpp"

#if defined(DISABLE_JoystickCalibrationControl)
	#define JoystickCalibrationControl_hpp
#endif

#ifndef JoystickCalibrationControl_hpp
#define JoystickCalibrationControl_hpp
#define JoystickCalibrationControl_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "GameOn.hpp"
#include "GameObject.hpp"
#include "Joystick.hpp"
#include "AnalogJoystick.hpp"
#include "cppObjectClass.hpp"

namespace ame{

class JoystickCalibrationControl : public GameOn{
    private:
	
    public:
		JoystickCalibrationControl(){}
		~JoystickCalibrationControl(){}
		
        bool isValidControl(){
			if(this->parent == nullptr){
				return false;
			}
			return this->parent->getClass() == ame::Class<AnalogJoystick>::classType;
		}
        AnalogJoystick *getJoystick(){
			if(!this->isValidControl()){
				return nullptr;
			}
			return (AnalogJoystick*)this->parent;
		}
		
        void update(float tpc){
			if(!this->isValidControl()){
				((ame::GameObject*)this->parent)->detach(this->getClass());
				return;
			}
			ame::Joystick *joystick= this->getJoystick();
			joystick->setOrigin(analogRead(joystick->getPinX()),analogRead(joystick->getPinY()));
			delete ((ame::GameObject*)this->parent)->detach(this->getClass());
		}
		
		cppObjectClass* getClass(){
			return ame::Class<ame::JoystickCalibrationControl>::classType;
		}
		Note toNote(){
			return "JoystickCalibrationControl";
		}
		
		JoystickCalibrationControl *clone(){
			ame::JoystickCalibrationControl *control = new ame::JoystickCalibrationControl();
			control->parent = this->parent;
			return control;
		}
};

}

#endif