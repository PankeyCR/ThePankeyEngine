

#ifndef RealRandom_h
#define RealRandom_h

#include "Random.h"
#include "Logger.h"

#ifdef RealRandomLogApp
	#define RealRandomLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define RealRandomLog(name,method,type,mns) 
#endif

namespace ame{

//seed from 0 - 1000
class RealRandom : public Random{
	private:
		float limitMax;
		
    public:
		RealRandom();
		virtual ~RealRandom();
		virtual float getRandom();
};

}

#endif 
