
#include "ame_Enviroment.hpp"

#if defined(DISABLE_RealRandom)
	#define RealRandom_hpp
#endif

#ifndef RealRandom_hpp
#define RealRandom_hpp
#define RealRandom_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Random.hpp"

#ifdef RealRandomLogApp
	#include "Logger.hpp"
	#define RealRandomLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define RealRandomLog(name,method,type,mns) 
#endif

namespace ame{

#ifdef ame_Windows
class RealRandom : public Random{
	private:
		float limitMax;
		
    public:
		RealRandom(){
			limitMax = ((float)2147483646/1000000.0f);
			RealRandomLog("RealRandom", "Contructor", "println",Note(limitMax));
		}
		
		virtual ~RealRandom(){}
		
		virtual float getRandom(){
			return 0;
		}
};
#endif 

#ifdef ame_ArduinoIDE
class RealRandom : public Random{
	private:
		float limitMax;
		
    public:
		RealRandom(){
			limitMax = ((float)2147483646/1000000.0f);
			RealRandomLog("RealRandom", "Contructor", "println",Note(limitMax));
		}
		
		virtual ~RealRandom(){}
		
		virtual float getRandom(){
			float time = ((float)micros()/1000000.0f);
			float d = getMax()-getMin();
			float dx = ((float)limitMax/(this->seed*10.0f));
			float tdx = ((float)(time/dx));
			float tx = (((float)(tdx))-((long)(tdx)));
			float x = d*tx;
			RealRandomLog("RealRandom", "getRandom", "println","");
			RealRandomLog("RealRandom", "getRandom", "println","RealRandom");
			RealRandomLog("RealRandom", "getRandom", "print","time ");RealRandomLog("RealRandom", "getRandom", "println",Note(time));
			RealRandomLog("RealRandom", "getRandom", "print","d ");RealRandomLog("RealRandom", "getRandom", "println",Note(d));
			RealRandomLog("RealRandom", "getRandom", "print","dx ");RealRandomLog("RealRandom", "getRandom", "println",Note(dx));
			RealRandomLog("RealRandom", "getRandom", "print","tdx ");RealRandomLog("RealRandom", "getRandom", "println",Note(tdx));
			RealRandomLog("RealRandom", "getRandom", "print","tx ");RealRandomLog("RealRandom", "getRandom", "println",Note(tx));
			RealRandomLog("RealRandom", "getRandom", "print","x ");RealRandomLog("RealRandom", "getRandom", "println",Note(x));
			RealRandomLog("RealRandom", "getRandom", "println","");
			return x+getMin();
		}
};
#endif 

}

#endif