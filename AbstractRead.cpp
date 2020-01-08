
#ifndef AbstractRead_cpp
#define AbstractRead_cpp

#include "AbstractRead.h"

	AbstractRead::AbstractRead(){
		
	}
	
	AbstractRead::~AbstractRead(){
		
	}
	
	void AbstractRead::Read(){
		
	}
	
	float AbstractRead::getReading(){
		return this->read;
	}

	void AbstractRead::operator=(AbstractRead b){
		this->read = b.read;
	}

	bool AbstractRead::operator==(AbstractRead b){
		return this->read == b.read;
	}

	bool AbstractRead::operator!=(AbstractRead b){
		return this->read != b.read;
	}
	
#endif 
