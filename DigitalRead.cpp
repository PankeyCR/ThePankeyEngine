

#ifndef DigitalRead_cpp
#define DigitalRead_cpp

#include "DigitalRead.h"

    DigitalRead::DigitalRead(int pin){
		this->Rpin = pin;
		pinMode(pin,INPUT);
    }

    DigitalRead::~DigitalRead(){
    }
    
    void DigitalRead::Read(){
		this->read = digitalRead(this->Rpin);
    }
    
#endif 
