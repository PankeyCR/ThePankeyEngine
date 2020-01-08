
#ifndef PirSensor_cpp
#define PirSensor_cpp

#include "PirSensor.h"

	PirSensor::PirSensor(){
	
	}
	PirSensor::PirSensor(int sensor){
		Sensor = sensor;
	}
	void PirSensor::addPin(int sensor){
		Sensor = sensor;	
	}
	bool PirSensor::isPressed(){
		return pressed;
	}
	bool PirSensor::isReleased(){
		return released;		
	}
	bool PirSensor::isClick(){
		return clicked;		
	}
	bool PirSensor::update(){
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
