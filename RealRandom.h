

#ifndef RealRandom_h
#define RealRandom_h

#include "Arduino.h"
#include "Random.h"
#include "Logger.h"

//seed from 0 - 1000
class RealRandom : public Random{
	private:
		float limitMax;
		
    public:
		RealRandom();
		virtual ~RealRandom();
		virtual float getRandom();
		
};

#endif 
