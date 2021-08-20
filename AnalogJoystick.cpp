
#ifndef AnalogJoystick_cpp
#define AnalogJoystick_cpp

#include "AnalogJoystick.h"

	ame::AnalogJoystick::AnalogJoystick(){
		
	}

	ame::AnalogJoystick::~AnalogJoystick(){
		
	}

	void ame::AnalogJoystick::setOrigin(float x, float y){
		defaultX=x;
		defaultY=y;		
	}

	float ame::AnalogJoystick::getX(){
		return x;
	}

	float ame::AnalogJoystick::getY(){
		return y;
	}

	int ame::AnalogJoystick::getRawX(){
		return rawX;
	}

	int ame::AnalogJoystick::getRawY(){
		return rawY;
	}

	bool ame::AnalogJoystick::isPressed(){
		return pressed;
	}

	bool ame::AnalogJoystick::isReleased(){
		return released;
	}

	bool ame::AnalogJoystick::isClick(){
		return clicked;
	}

	ame::cppObjectClass* ame::AnalogJoystick::getClass(){
		return ame::Class<AnalogJoystick>::classType;
	}

	String ame::AnalogJoystick::toString(){
		return "AnalogJoystick "+String(x)+" "+String(y);
	}

	ame::AnalogJoystick *ame::AnalogJoystick::clone(){
		ame::AnalogJoystick *analog = new ame::AnalogJoystick();
		analog->defaultX=this->defaultX;
		analog->defaultY=this->defaultY;
		analog->x=this->x;
		analog->y=this->y;
		analog->rawX=this->rawX;
		analog->rawY=this->rawY;
		analog->pressed=false;
		analog->clicked=false;
		analog->released=false;
		return analog;
	}

	void ame::AnalogJoystick::setPins(int analgoX, int analgoY, int button){
		pinX = analgoX;
		pinY = analgoY;
		pinButton = button;
		pinMode(pinX, INPUT);
		pinMode(pinY, INPUT);
		pinMode(pinButton, INPUT);
	}

	int ame::AnalogJoystick::getPinX(){
		return pinX;
	}

	int ame::AnalogJoystick::getPinY(){
		return pinY;
	}

	int ame::AnalogJoystick::getPinButton(){
		return pinButton;
	}

	void ame::AnalogJoystick::setScale(float Scale){
		scale = Scale;
	}

	void ame::AnalogJoystick::update(float tpc){
		rawX = analogRead(pinX);
		rawY = analogRead(pinY);
		x = (rawX-defaultX)*scale;
		y = (rawY-defaultY)*scale;
		int read = digitalRead(pinButton);
        if(read==1){
          if(!clicked && !pressed){
            clicked = true;
          }
          if(clicked && pressed){
            clicked = false;
          }
          pressed=true;
          released=false;
        }
        if(read==0){
          if(!released && pressed){
            released = true;
          }
          if(released && !pressed){
            released = false;
          }
          clicked = false;
          pressed=false;
        }		
		GameObject::update(tpc);
	}
	
#endif 
