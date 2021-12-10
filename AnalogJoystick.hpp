
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef AnalogJoystick_hpp
#define AnalogJoystick_hpp

#include "Arduino.h"
#include "Joystick.hpp"
#include "GameObject.hpp"

namespace ame{
	
class AnalogJoystick : public Joystick , public GameObject {
    private:
	
    public:
		float defaultX=0;
		float defaultY=0;
		float x=0;
		float y=0;
		float rawX=0;
		float rawY=0;
		int pinX=0;
		int pinY=0;
		int pinButton=0;
		float scale=1;
		
		bool pressed=false;
		bool clicked=false;
		bool released=false;
	
		AnalogJoystick(){}
		
		virtual ~AnalogJoystick(){}
		
		void setPins(int analgoX, int analgoY, int button){
			pinX = analgoX;
			pinY = analgoY;
			pinButton = button;
			pinMode(pinX, INPUT);
			pinMode(pinY, INPUT);
			pinMode(pinButton, INPUT);
		}
		
		int getPinX(){
			return pinX;
		}
		
		int getPinY(){
			return pinY;
		}
		
		int getPinButton(){
			return pinButton;
		}
		
		void setScale(float Scale){
			scale = Scale;
		}
		
		void setOrigin(float x, float y){
			defaultX=x;
			defaultY=y;		
		}
		
		float getX(){
			return x;
		}
		
		float getY(){
			return y;
		}
		
		int getRawX(){
			return rawX;
		}
		
		int getRawY(){
			return rawY;
		}
		
		bool isPressed(){
			return pressed;
		}
		
		bool isReleased(){
			return released;
		}
		
		bool isClick(){
			return clicked;
		}
		
        void update(float tpc){
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
		
		cppObjectClass* getClass(){
			return ame::Class<AnalogJoystick>::classType;
		}
		
		String toString(){
			return "AnalogJoystick "+String(x)+" "+String(y);
		}
		
		AnalogJoystick *clone(){
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
		
};

}

#endif 

#endif 