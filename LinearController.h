

#ifndef LinearController_h
#define LinearController_h

#include "Arduino.h"
#include "Controller.h"
#include "Map.h"

class LinearController : public Controller<float,Map<String,float>,float>{
	public:
		LinearController();
		virtual ~LinearController();
		virtual LinearController* setup(Controlling ctl);
		virtual LinearController* input(float* in);
		virtual LinearController* control(Map<String,float>* ot);
		virtual LinearController* output(float* ot);
		virtual LinearController* input(float in);
		virtual LinearController* output(float ot);
		virtual float outputValue();
		
		virtual void update(float tpf);
		
		//cppObject part
		virtual String getClassName();
		virtual String toString();
		virtual LinearController* clone();
		
	protected:
};

#endif 
