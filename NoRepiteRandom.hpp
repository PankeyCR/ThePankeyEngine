//1747
#include "ame_Level.hpp"

#if defined(ame_untilLevel_1)

#ifndef NoRepiteRandom_hpp
#define NoRepiteRandom_hpp

#ifndef ame_Enviroment_Defined
	#include "Arduino.h"
#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Random.hpp"
#include "RealRandom.hpp"

#ifdef NoRepiteRandomLogApp
	#include "Logger.hpp"
	#define NoRepiteRandomLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define NoRepiteRandomLog(name,method,type,mns) 
#endif

namespace ame{

//seed from 0 - 1000
class NoRepiteRandom : public Random{
	protected:
		RealRandom *realRandom = nullptr;
		float limitMax;
		float relation = 0;
		
    public:
		NoRepiteRandom(){
			this->realRandom = new RealRandom();
			this->realRandom->setSeed(78545l);
			this->realRandom->setMax(78545l);
			setMax(100);
			setMin(0);
			limitMax = ((float)2147483646/1000000.0f);
		}
		NoRepiteRandom(const NoRepiteRandom& r){
			this->realRandom = new RealRandom();
			this->realRandom->setSeed(r.getSeed());
			this->realRandom->setMax(78545l);
			setMax(100);
			setMin(0);
			limitMax = ((float)2147483646/1000000.0f);
		}
		NoRepiteRandom(float seed){
			this->realRandom = new RealRandom();
			this->realRandom->setSeed(seed);
			this->realRandom->setMax(seed);
			setMax(100);
			setMin(0);
			limitMax = ((float)2147483646/1000000.0f);
		}
		NoRepiteRandom(float max, float min, float seed){
			this->realRandom = new RealRandom();
			this->realRandom->setSeed(seed);
			this->realRandom->setMax(seed);
			setMax(max);
			setMin(min);
			limitMax = ((float)2147483646/1000000.0f);
		}
		virtual ~NoRepiteRandom(){
			delete this->realRandom;
		}
		virtual float getRandom(){
			float eseed = this->realRandom->getRandom();
			if(eseed!=0){
				this->seed = eseed;
			}
			float time = ((float)micros()/1000000.0f);
			float d = getMax()-getMin();
			float dx = (limitMax/(this->seed*relation));
			float tdx = ((float)(time/dx));
			float tx = (((float)(tdx))-((long)(tdx)));
			float x = d*tx;
			NoRepiteRandomLog("NoRepiteRandom", "getRandom", "println","");
			NoRepiteRandomLog("NoRepiteRandom", "getRandom", "println","NoRepiteRandom");
			NoRepiteRandomLog("NoRepiteRandom", "getRandom", "print","time ");NoRepiteRandomLog("NoRepiteRandom", "getRandom", "println",String(time));
			NoRepiteRandomLog("NoRepiteRandom", "getRandom", "print","d ");NoRepiteRandomLog("NoRepiteRandom", "getRandom", "println",String(d));
			NoRepiteRandomLog("NoRepiteRandom", "getRandom", "print","dx ");NoRepiteRandomLog("NoRepiteRandom", "getRandom", "println",String(dx));
			NoRepiteRandomLog("NoRepiteRandom", "getRandom", "print","tdx ");NoRepiteRandomLog("NoRepiteRandom", "getRandom", "println",String(tdx));
			NoRepiteRandomLog("NoRepiteRandom", "getRandom", "print","tx ");NoRepiteRandomLog("NoRepiteRandom", "getRandom", "println",String(tx));
			NoRepiteRandomLog("NoRepiteRandom", "getRandom", "print","x ");NoRepiteRandomLog("NoRepiteRandom", "getRandom", "println",String(x));
			NoRepiteRandomLog("NoRepiteRandom", "getRandom", "println","");
			relation =  1.0f / (x+getMin()+ 0.1f);
			return x+getMin();
		}
		
};

}

#endif 

#endif 
