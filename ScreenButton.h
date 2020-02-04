
#ifndef ScreenButton_h
#define ScreenButton_h

#include "Button.h"
#include "Vector2f.h"

class ScreenButton : public Button{
    private:
	
    public:
		virtual Vector2f getCursor()=0;
		virtual int getPressure()=0;
};
#endif 
