

#ifndef DefaultPID_h
#define DefaultPID_h

#include "PID.h"

class DefaultPID : public PID{
  public:
    DefaultPID();
    DefaultPID(float P,float I, float D);
    ~DefaultPID();
    bool Compute();
    
	protected:
		float kisum = 0;
};

#endif 
