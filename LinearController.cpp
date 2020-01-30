

#ifndef LinearController_cpp
#define LinearController_cpp

#include "LinearController.h"

	
	LinearController::LinearController(){
		this->inputm = new float();
		this->outputm = new float();
	}
	
	LinearController::~LinearController(){
		if(this->inputm != nullptr){
			delete this->inputm;
		}
		if(this->outputm != nullptr){
			delete this->outputm;
		}
	}
	
	LinearController* LinearController::setup(Controlling ctl){
		this->controlling = ctl;
		return this;
	}
	
	LinearController* LinearController::input(float* in){
		*this->inputm = *in;
		*this->outputm = *in;
		return this;
	}
	
	LinearController* LinearController::control(Map<String,float>* ot){
		this->controlm = ot;
		return this;
	}
	
	LinearController* LinearController::output(float* ot){
		*this->outputm = *ot;
		return this;
	}
	
	LinearController* LinearController::input(float in){
		*this->inputm = in;
		*this->outputm = in;
		return this;
	}
	
	LinearController* LinearController::output(float ot){
		*this->outputm = ot;
		return this;
	}
	
	float LinearController::outputValue(){
		return *this->outputm;
	}
	
	void LinearController::update(float tpf){
		if(this->controlling == Controlling::Default){
			if(this->controlm->get("kp") == nullptr &&
					this->controlm->get("setpoint") == nullptr &&
					this->controlm->get("error") == nullptr){
				return;
			}
			float setpoint = *this->controlm->get("setpoint");
			float error = *this->controlm->get("error");
			if(abs(setpoint - *this->outputm) < error){
				return;
			}
			float kp = *this->controlm->get("kp");
			if(setpoint - *this->outputm > 0){
				*this->outputm = *this->outputm + kp;
			}else{
				*this->outputm = *this->outputm - kp;
			}
			return;
		}
		if(this->controlling == Controlling::SetpointOutputError){
			if(this->controlm->get("output") == nullptr &&
					this->controlm->get("kp") == nullptr &&
					this->controlm->get("setpoint") == nullptr &&
					this->controlm->get("error") == nullptr){
				return;
			}
			float setpoint = *this->controlm->get("setpoint");
			float error = *this->controlm->get("error");
			float output = *this->controlm->get("output");
			if(abs(setpoint - output) < error){
				return;
			}
			float kp = *this->controlm->get("kp");
			if(setpoint - output > 0){
				*this->outputm = *this->outputm + kp;
			}else{
				*this->outputm = *this->outputm - kp;
			}
			return;
		}
		if(this->controlling == Controlling::KpError){
			if(this->controlm->get("kp") == nullptr &&
					this->controlm->get("setpoint") == nullptr &&
					this->controlm->get("error") == nullptr){
				return;
			}
			float setpoint = *this->controlm->get("setpoint");
			float error = *this->controlm->get("error");
			float kp = *this->controlm->get("kp");
			if(abs(setpoint - *this->outputm) < error){
				return;
			}
			if(setpoint - *this->outputm > 0){
				*this->outputm = *this->outputm + kp;
			}else{
				*this->outputm = *this->outputm - kp;
			}
			return;
		}
		
		this->controlling = Controlling::Default;
	}
		
	String LinearController::getClassName(){
		return "LinearController";
	}
		
	String LinearController::toString(){
		if(this->controlling == Controlling::Default){
			return "LinearController Default";
		}
		if(this->controlling == Controlling::SetpointOutputError){
			return "LinearController SetpointOutputError";
		}
		if(this->controlling == Controlling::KpError){
			return "LinearController KpError";
		}
		return "LinearController";
	}
		
	LinearController* LinearController::clone(){
		return this;
	}
#endif 
