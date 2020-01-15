

#ifndef RealRandom_h
#define RealRandom_h

#include "Arduino.h"
#include "Random.h"

//seed from 0 - 1000
class RealRandom : public Random{
	private:
		float limitMax;
		
    public:
		RealRandom();
		virtual ~RealRandom();
		float getRandom();
		
};

#endif 
