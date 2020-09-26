

#ifndef PIDController_h
#define PIDController_h

#include "Arduino.h"
#include "Controller.h"
#include "Map.h"
#include "List.h"

template<class T>
class PIDController : public Controller<T,T,T>{
	public:
		PIDController(){
		}
		PIDController(float p,float i, float d){
			this->kp = p;
			this->ki = i;
			this->kd = d;
		}
		virtual ~PIDController(){
		}
		
		void setPID(float p,float i, float d){
			this->kp = p;
			this->ki = i;
			this->kd = d;
		}
		
		void setP(float p){
			this->kp = p;
		}
		
		void setI(float i){
			this->ki = i;
		}
		
		void setD(float d){
			this->kd = d;
		}
		
		//cppObject part
		virtual String getClassName(){
			return "PIDController";
		}
		virtual String toString(){
			return "PIDController";
		}
		
		virtual void update(float tpc){
			this->error = ((*this->input_m)-(*this->control_m)) * tpc;
			
			this->iSum += this->error * this->ki;
			
			(*this->output_m) = (this->error * this->kp) + this->iSum - (this->error * this->kd);
		}
		
	protected:
		float kp=0;
		float ki=0;
		float kd=0;
		
		T error;
		
		T iSum;
};

#endif 
