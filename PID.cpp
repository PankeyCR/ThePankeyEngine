

#ifndef PID_cpp
#define PID_cpp

#include "PID.h"
	
	void PID::setInput(float input){
		input = input;
	}
	
	void PID::setPoint(float point){
		this->setpoint = point;
		
	}
 
	void PID::setPID(float P,float I, float D){
		this->kp = P;
		this->ki = I;
		this->kd = D;
	}
	
	void PID::setP(float P){
		this->kp = P;
	}
	
	void PID::setI(float I){
		this->ki = I;
	}
	
	void PID::setD(float D){
		this->kd = D;
	}
	
	float PID::getOutput(){
		return this->output;	
	}
	
    float PID::getP(){
		return this->kp;		
	}
	
	float PID::getI(){
		return this->ki;		
	}
	
	float PID::getD(){
		return this->kd;		
	}
	
	float PID::getError(){
		return this->error;
	}
#endif 
