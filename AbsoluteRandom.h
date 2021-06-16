

#ifndef AbsoluteRandom_h
#define AbsoluteRandom_h

#include "Arduino.h"
#include "Random.h"
#include "RealRandom.h"

#ifdef AbsoluteRandomLogApp
	#include "Logger.h"
	#define AbsoluteRandomLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define AbsoluteRandomLog(name,method,type,mns) 
#endif

//seed from 0 - 1000
class AbsoluteRandom : public Random{
	private:
		RealRandom *realRandom = nullptr;
		float limitMax;
		
    public:
		AbsoluteRandom();
		AbsoluteRandom(float seed);
		virtual ~AbsoluteRandom();
		virtual float getRandom();
		
};

#endif 
