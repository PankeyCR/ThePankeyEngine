
#ifndef PirSensor_hpp
#define PirSensor_hpp

#ifndef ame_Enviroment_Defined
	#include "Arduino.h"
#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Button.hpp"

namespace ame{

class PirSensor : public Button{
    private:
		int Sensor=2;
		bool pressed=false;
		bool released=false;
		bool clicked=false;
		int valor=0;
	
    public:
		PirSensor(){}
		PirSensor(int sensor){
			Sensor = sensor;
		}
		void addPin(int sensor){
			Sensor = sensor;
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
		bool update(){
			valor = digitalRead(Sensor);
			
			if(valor == HIGH){
			  if(!clicked && !pressed){
				clicked = true;
			  }
			  if(clicked && pressed){
				clicked = false;
			  }
			  pressed=true;
			  released=false;
			}
			if(valor ==0){
			  if(!released && pressed){
				released = true;
			  }
			  if(released && !pressed){
				released = false;
			  }
			  clicked = false;
			  pressed=false;
			}
		}
};

}

#endif 
