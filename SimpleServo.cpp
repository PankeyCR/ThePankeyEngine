

#ifndef SimpleServo_cpp
#define SimpleServo_cpp

#include "SimpleServo.h"

		SimpleServo::SimpleServo(){
			
		}
		
		SimpleServo::~SimpleServo(){
			for(int x=0; x < this->servoSize; x++){
				delete this->servos[x];				
			}
			delete[] this->servos;		
		}
		void SimpleServo::setup(int size){
			this->servoSize = size;
			this->servos = new Servo*[size];
			for(int x=0; x < size; x++){
				this->servos[x] = new Servo();
			}
		}
		
		Servo *SimpleServo::getServo(int sel){
			if(sel >= this->servoSize){
				return nullptr;
			}
			return this->servos[sel];
		}
		
		void SimpleServo::attach(int sel,int i){
			if(sel >= this->servoSize){
				return;
			}
			this->servos[sel]->attach(i);
		}
		
		void SimpleServo::detach(int sel,int i){
			if(sel >= this->servoSize){
				return;
			}
			this->servos[sel]->detach();
		}
		
		int SimpleServo::MoveServo(int sel,int angle){
			if(sel >= this->servoSize){
				return angle;
			}
			this->servos[sel]->write(angle);
			return angle;
		}
    

#endif 
