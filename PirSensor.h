
#ifndef PirSensor_h
#define PirSensor_h

#include "Arduino.h"
#include "Button.h"

class PirSensor : public Button{
    private:
		int Sensor=2;
		bool pressed=false;
		bool released=false;
		bool clicked=false;
		int valor=0;
	
    public:
		PirSensor();
		PirSensor(int sensor);
		void addPin(int sensor);
		bool isPressed();		
		bool isReleased();
		bool isClick();
		bool update();
};
#endif 
