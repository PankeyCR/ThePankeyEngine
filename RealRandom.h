

#ifndef RealRandom_h
#define RealRandom_h

#include "Random.h"
#include "Logger.h"

#ifdef RealRandomLogApp
	#define RealRandomLog(name,method,type,mns) Logger::StaticLog(name,method,type,mns)
#else
	#define RealRandomLog(name,method,type,mns) 
#endif

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
