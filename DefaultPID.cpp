

#ifndef DefaultPID_cpp
#define DefaultPID_cpp

#include "DefaultPID.h"

	DefaultPID::DefaultPID(){		
	}
 
	DefaultPID::DefaultPID(float P,float I, float D){
	}
 
	bool DefaultPID::Compute(){
		this->error = this->setpoint - this->input;
		
		this->output = this->kp * this->error;
		
		this->kisum += (this->ki * this->error);
		
		this->output += this->kisum - (this->kd * this->error);
		
		return true;
	}
	
#endif 
