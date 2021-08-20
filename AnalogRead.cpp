

#ifndef AnalogRead_cpp
#define AnalogRead_cpp

#include "AnalogRead.h"

    ame::AnalogRead::AnalogRead(int pin){
		this->Rpin = pin;
		pinMode(pin,INPUT);
    }

    ame::AnalogRead::~AnalogRead(){
    }
    
    void ame::AnalogRead::Read(){
		this->read = analogRead(this->Rpin);
    }
    
#endif 
