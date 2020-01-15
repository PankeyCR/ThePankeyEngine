

#ifndef AbsoluteRandom_h
#define AbsoluteRandom_h

#include "Arduino.h"
#include "Random.h"
#include "RealRandom.h"

//seed from 0 - 1000
class AbsoluteRandom : public Random{
	private:
		RealRandom *realRandom = nullptr;
		float limitMax;
		
    public:
		AbsoluteRandom();
		AbsoluteRandom(float seed);
		virtual ~AbsoluteRandom();
		float getRandom();
		
};

#endif 
