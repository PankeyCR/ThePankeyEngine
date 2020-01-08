

#ifndef AnalogReadPID_cpp
#define AnalogReadPID_cpp

#include "AnalogReadPID.h"

    AnalogReadPID::AnalogReadPID(int pin, PID* controller){
		this->pid = controller;
		this->Rpin = pin;
		pinMode(pin,INPUT);
    }

    AnalogReadPID::~AnalogReadPID(){
    }
    
    void AnalogReadPID::Read(){
		this->read = analogRead(this->Rpin);
		this->pid->setInput(this->read);
		this->pid->Compute();
    }
    
#endif 
