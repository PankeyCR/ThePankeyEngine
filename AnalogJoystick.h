
#ifndef AnalogJoystick_h
#define AnalogJoystick_h

#include "Arduino.h"
#include "Joystick.h"
#include "GameObject.h"

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
	
		AnalogJoystick();
		~AnalogJoystick();
		void setPins(int analgoX, int analgoY, int button);
		int getPinX();
		int getPinY();
		int getPinButton();
		void setScale(float Scale);
		void setOrigin(float x, float y);
		float getX();
		float getY();
		int getRawX();
		int getRawY();
		
		bool isPressed();
		bool isReleased();
		bool isClick();
		
        void update();
        void onDelete();
		String getClassName();
		String toString();
		AnalogJoystick *clone();
};
#endif 
