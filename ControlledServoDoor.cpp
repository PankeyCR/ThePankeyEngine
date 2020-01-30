

#ifndef ControlledServoDoor_cpp
#define ControlledServoDoor_cpp

#include "ControlledServoDoor.h"

	ControlledServoDoor::ControlledServoDoor(){
		this->controllerm = new LinearController();
		this->controlmap = new KVMap<String,float,4>();
		this->controlmap->add("setpoint",0.0f);
		this->controlmap->add("kp",0.05f);
		this->controlmap->add("error",0.001f);
		this->controllerm	->input(0.0f)
							->setup(Controlling::KpError)//Default , SetpointOutputError , KpError
							->control(this->controlmap);
	}
	ControlledServoDoor::~ControlledServoDoor(){
		delete this->controllerm;
		delete this->controlmap;
	}
	
	ControlledServoDoor* ControlledServoDoor::input(int in){
		this->controllerm->input(in);
		this->servo.write(in);
		return this;
	}
	
	ControlledServoDoor* ControlledServoDoor::monkeytime(MonkeyTime* tim){
		this->timer = tim;
		return this;
	}
	
	ControlledServoDoor* ControlledServoDoor::delay(float tm){
		this->timing = tm;
		return this;
	}
	
	ControlledServoDoor* ControlledServoDoor::offset(float tm){
		this->offsetm = tm;
		return this;
	}
	
	ControlledServoDoor* ControlledServoDoor::timecheck(TimeCheck tm){
		this->timecheckm = tm;
		return this;
	}
	ControlledServoDoor* ControlledServoDoor::attach(int pin){
		this->slpin = pin;
		this->servo.attach(pin);
		return this;
	}
	ControlledServoDoor* ControlledServoDoor::close(){
		this->state = false;
		this->closem = false;
		this->openm = false;
		this->controlmap->set("setpoint",this->cAngle);
		return this;
	}
	ControlledServoDoor* ControlledServoDoor::open(){
		this->state = true;
		this->closem = false;
		this->openm = false;
		this->controlmap->set("setpoint",this->oAngle);
		return this;
	}
	ControlledServoDoor* ControlledServoDoor::openAngle(int angle){
		this->oAngle = angle;
		return this;
	}
	ControlledServoDoor* ControlledServoDoor::closeAngle(int angle){
		this->cAngle = angle;
		return this;
	}
	LinearController* ControlledServoDoor::controller(){
		return this->controllerm;
	}
	Map<String,float>* ControlledServoDoor::control(){
		return this->controlmap;
	}
	float ControlledServoDoor::angle(){
		return this->controllerm->outputValue();
	}
	float ControlledServoDoor::closetime(){
		return this->closeRecorder.getRecord();
	}
	float ControlledServoDoor::opentime(){
		return this->openRecorder.getRecord();
	}
	
	void ControlledServoDoor::update(float tpc){
		if(this->timer == nullptr || this->controllerm == nullptr ){
			return;
		}
		this->controllerm->update(tpc);
		// if(this->state==true){
			// openRecorder+=this->timer->getScaleTPC();
			// closeRecorder.resetRecord();
		// }
		// if(this->state==false){
			// closeRecorder+=this->timer->getScaleTPC();
			// openRecorder.resetRecord();
		// }
		// if(this->state==unknown){
			// openRecorder.resetRecord();
			// closeRecorder.resetRecord();
		// }
		if((int)this->controllerm->outputValue() == this->oAngle){
			this->openm = true;
			this->state = unknown;
		}
		if((int)this->controllerm->outputValue() == this->cAngle){
			this->closem = true;
			this->state = unknown;
		}
		this->servo.write((int)this->controllerm->outputValue());
	}
#endif 
