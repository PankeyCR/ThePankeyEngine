
#ifndef PirSensor_cpp
#define PirSensor_cpp

#include "PirSensor.h"

	ame::PirSensor::PirSensor(){
	
	}
	ame::PirSensor::PirSensor(int sensor){
		Sensor = sensor;
	}
	void ame::PirSensor::addPin(int sensor){
		Sensor = sensor;	
	}
	bool ame::PirSensor::isPressed(){
		return pressed;
	}
	bool ame::PirSensor::isReleased(){
		return released;		
	}
	bool ame::PirSensor::isClick(){
		return clicked;		
	}
	bool ame::PirSensor::update(){
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
	
#endif 
