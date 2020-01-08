

#ifndef RealRandom_h
#define RealRandom_h

#include "Arduino.h"
#include "Random.h"


class RealRandom : public Random{
	private:
		float limitMax;
		
    public:
		RealRandom();
		float getRandom();
		
};

#endif 
