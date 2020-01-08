

#ifndef AnalogReadPID_h
#define AnalogReadPID_h

#include "AbstractRead.h"
#include "PID.h"

class AnalogReadPID : public AbstractRead{
	public:
		AnalogReadPID(int pin,PID *controller);
		~AnalogReadPID();
		virtual void Read();
	protected:
		PID *pid = nullptr;
		int Rpin=0;
};

#endif 
