
#ifndef Joystick_h
#define Joystick_h

#include "Button.h"

class Joystick : public Button{
    private:
	
    public:
		virtual void setPins(int analgoX, int analgoY, int button)=0;
		virtual int getPinX()=0;
		virtual int getPinY()=0;
		virtual int getPinButton()=0;
		virtual void setScale(float scale)=0;
		virtual void setOrigin(float x, float y)=0;
		virtual float getX()=0;
		virtual float getY()=0;
		virtual int getRawX()=0;
		virtual int getRawY()=0;
};
#endif 
