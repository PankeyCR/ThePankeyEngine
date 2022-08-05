
#include "ame_Enviroment.hpp"

#if defined(DISABLE_AbsoluteRandom)
	#define AbsoluteRandom_hpp
#endif

#ifndef AbsoluteRandom_hpp
#define AbsoluteRandom_hpp
#define AbsoluteRandom_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Note.hpp"
#include "Random.hpp"
#include "RealRandom.hpp"

#ifdef AbsoluteRandomLogApp
	#include "Logger.hpp"
	#define AbsoluteRandomLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define AbsoluteRandomLog(name,method,type,mns) 
#endif

namespace ame{

//seed from 0 - 1000
class AbsoluteRandom : public Random{
	protected:
		RealRandom *realRandom = nullptr;
		float limitMax;
		
    public:
		AbsoluteRandom(){
			this->realRandom = new RealRandom();
			this->realRandom->setSeed(78545l);
			this->realRandom->setMax(78545l);
			setMax(100);
			setMin(0);
			limitMax = ((float)2147483646/1000000.0f);
		}
		AbsoluteRandom(const AbsoluteRandom& r){
			this->realRandom = new RealRandom();
			this->realRandom->setSeed(r.getSeed());
			this->realRandom->setMax(78545l);
			setMax(100);
			setMin(0);
			limitMax = ((float)2147483646/1000000.0f);
		}
		AbsoluteRandom(float seed){
			this->realRandom = new RealRandom();
			this->realRandom->setSeed(seed);
			this->realRandom->setMax(seed);
			setMax(100);
			setMin(0);
			limitMax = ((float)2147483646/1000000.0f);
		}
		AbsoluteRandom(float max, float min, float seed){
			this->realRandom = new RealRandom();
			this->realRandom->setSeed(seed);
			this->realRandom->setMax(seed);
			setMax(max);
			setMin(min);
			limitMax = ((float)2147483646/1000000.0f);
		}
		virtual ~AbsoluteRandom(){
			delete this->realRandom;
		}
		virtual float getRandom(){
			float eseed = this->realRandom->getRandom();
			if(eseed!=0){
				this->seed = eseed;
			}
			float time = ((float)micros()/1000000.0f);
			float d = getMax()-getMin();
			float dx = (limitMax/(this->seed*10.0f));
			float tdx = ((float)(time/dx));
			float tx = (((float)(tdx))-((long)(tdx)));
			float x = d*tx;
			AbsoluteRandomLog("AbsoluteRandom", "getRandom", "println","");
			AbsoluteRandomLog("AbsoluteRandom", "getRandom", "println","absoluterandom");
			AbsoluteRandomLog("AbsoluteRandom", "getRandom", "print","time ");AbsoluteRandomLog("AbsoluteRandom", "getRandom", "println",Note(time));
			AbsoluteRandomLog("AbsoluteRandom", "getRandom", "print","d ");AbsoluteRandomLog("AbsoluteRandom", "getRandom", "println",Note(d));
			AbsoluteRandomLog("AbsoluteRandom", "getRandom", "print","dx ");AbsoluteRandomLog("AbsoluteRandom", "getRandom", "println",Note(dx));
			AbsoluteRandomLog("AbsoluteRandom", "getRandom", "print","tdx ");AbsoluteRandomLog("AbsoluteRandom", "getRandom", "println",Note(tdx));
			AbsoluteRandomLog("AbsoluteRandom", "getRandom", "print","tx ");AbsoluteRandomLog("AbsoluteRandom", "getRandom", "println",Note(tx));
			AbsoluteRandomLog("AbsoluteRandom", "getRandom", "print","x ");AbsoluteRandomLog("AbsoluteRandom", "getRandom", "println",Note(x));
			AbsoluteRandomLog("AbsoluteRandom", "getRandom", "println","");
			return x+getMin();
		}
		
};

}

#endif