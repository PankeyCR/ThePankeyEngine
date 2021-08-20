

#ifndef SimpleServo_cpp
#define SimpleServo_cpp

#include "SimpleServo.h"

		ame::SimpleServo::SimpleServo(){
			
		}
		
		ame::SimpleServo::~SimpleServo(){
			for(int x=0; x < this->servoSize; x++){
				delete this->servos[x];				
			}
			delete[] this->servos;		
		}
		void ame::SimpleServo::setup(int size){
			this->servoSize = size;
			this->servos = new Servo*[size];
			for(int x=0; x < size; x++){
				this->servos[x] = new Servo();
			}
		}
		
		Servo *ame::SimpleServo::getServo(int sel){
			if(sel >= this->servoSize){
				return nullptr;
			}
			return this->servos[sel];
		}
		
		void ame::SimpleServo::attach(int sel,int i){
			if(sel >= this->servoSize){
				return;
			}
			this->servos[sel]->attach(i);
		}
		
		void ame::SimpleServo::detach(int sel,int i){
			if(sel >= this->servoSize){
				return;
			}
			this->servos[sel]->detach();
		}
		
		int ame::SimpleServo::MoveServo(int sel,int angle){
			if(sel >= this->servoSize){
				return angle;
			}
			this->servos[sel]->write(angle);
			return angle;
		}
    

#endif 
