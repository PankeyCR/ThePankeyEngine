

#ifndef AnalogRead_cpp
#define AnalogRead_cpp

#include "AnalogRead.h"

    AnalogRead::AnalogRead(int pin){
		this->Rpin = pin;
		pinMode(pin,INPUT);
    }

    AnalogRead::~AnalogRead(){
    }
    
    void AnalogRead::Read(){
		this->read = analogRead(this->Rpin);
    }
    
#endif 
