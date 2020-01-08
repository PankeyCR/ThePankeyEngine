
#ifndef AnalogJoystick_cpp
#define AnalogJoystick_cpp

#include "AnalogJoystick.h"

	AnalogJoystick::AnalogJoystick(){
		
	}

	AnalogJoystick::~AnalogJoystick(){
		
	}

	void AnalogJoystick::setOrigin(float x, float y){
		defaultX=x;
		defaultY=y;		
	}

	float AnalogJoystick::getX(){
		return x;
	}

	float AnalogJoystick::getY(){
		return y;
	}

	int AnalogJoystick::getRawX(){
		return rawX;
	}

	int AnalogJoystick::getRawY(){
		return rawY;
	}

	bool AnalogJoystick::isPressed(){
		return pressed;
	}

	bool AnalogJoystick::isReleased(){
		return released;
	}

	bool AnalogJoystick::isClick(){
		return clicked;
	}

	void AnalogJoystick::onDelete(){
		delete this;
	}

	String AnalogJoystick::getClassName(){
		return "AnalogJoystick";
	}

	String AnalogJoystick::toString(){
		return "AnalogJoystick "+String(x)+" "+String(y);
	}

	AnalogJoystick *AnalogJoystick::clone(){
		AnalogJoystick *analog = new AnalogJoystick();
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

	void AnalogJoystick::setPins(int analgoX, int analgoY, int button){
		pinX = analgoX;
		pinY = analgoY;
		pinButton = button;
		pinMode(pinX, INPUT);
		pinMode(pinY, INPUT);
		pinMode(pinButton, INPUT);
	}

	int AnalogJoystick::getPinX(){
		return pinX;
	}

	int AnalogJoystick::getPinY(){
		return pinY;
	}

	int AnalogJoystick::getPinButton(){
		return pinButton;
	}

	void AnalogJoystick::setScale(float Scale){
		scale = Scale;
	}

	void AnalogJoystick::update(){
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
		GameObject::update();
	}
	
#endif 
