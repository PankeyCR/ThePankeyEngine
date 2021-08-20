

#ifndef DigitalRead_cpp
#define DigitalRead_cpp

#include "DigitalRead.h"

    ame::DigitalRead::DigitalRead(int pin){
		this->Rpin = pin;
		pinMode(pin,INPUT);
    }

    ame::DigitalRead::~DigitalRead(){
    }
    
    void ame::DigitalRead::Read(){
		this->read = digitalRead(this->Rpin);
    }
    
#endif 
