
#ifndef TouchScreen_2_4tft_cpp
#define TouchScreen_2_4tft_cpp

#include "TouchScreen_2_4tft.h"
/*
	TouchScreen_2_4tft::TouchScreen_2_4tft(){
		
	}

	TouchScreen_2_4tft::~TouchScreen_2_4tft(){
		delete screen;
		delete screenTouch;
	}

	void TouchScreen_2_4tft::onDelete(){
		delete screen;
		delete screenTouch;
		delete this;
	}

	String TouchScreen_2_4tft::getClassName(){
		return "TouchScreen_2_4tft";
	}

	SDClass TouchScreen_2_4tft::getSD(){
		return SD;
	}

	void TouchScreen_2_4tft::update(){
        TSPoint p = screenTouch->getPoint();
		cursor.set(p.x,p.y);
        pressure = screenTouch->pressure();
        if(pressure<1000 && pressure!=0){
			if(!clicked && !pressed){
				clicked = true;
			}
			if(clicked && pressed){
				clicked = false;
			}
			pressed=true;
			released=false;
        }
        if(pressure>1000 || pressure ==0){
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
     
    bool TouchScreen_2_4tft::isPressed(){
		return pressed;
    }
     
    bool TouchScreen_2_4tft::isReleased(){
        return released;
    }
     
    bool TouchScreen_2_4tft::isClick(){
        return clicked;
    }
      
    Vector2f TouchScreen_2_4tft::getCursor(){
        return cursor;
    }
      
    uint16_t TouchScreen_2_4tft::getPressure(){
        return pressure;
    }
	*/
	
#endif 
