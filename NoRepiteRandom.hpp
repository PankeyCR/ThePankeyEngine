
#include "ame_Enviroment.hpp"

#if defined(DISABLE_NoRepiteRandom)
	#define NoRepiteRandom_hpp
#endif

#ifndef NoRepiteRandom_hpp
#define NoRepiteRandom_hpp
#define NoRepiteRandom_AVAILABLE

#ifndef ame_Enviroment_Defined

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

#ifdef ame_Windows
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
			return 0;
		}
		
};
#endif

#ifdef ame_ArduinoIDE
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
			NoRepiteRandomLog("NoRepiteRandom", "getRandom", "print","time ");NoRepiteRandomLog("NoRepiteRandom", "getRandom", "println",Note(time));
			NoRepiteRandomLog("NoRepiteRandom", "getRandom", "print","d ");NoRepiteRandomLog("NoRepiteRandom", "getRandom", "println",Note(d));
			NoRepiteRandomLog("NoRepiteRandom", "getRandom", "print","dx ");NoRepiteRandomLog("NoRepiteRandom", "getRandom", "println",Note(dx));
			NoRepiteRandomLog("NoRepiteRandom", "getRandom", "print","tdx ");NoRepiteRandomLog("NoRepiteRandom", "getRandom", "println",Note(tdx));
			NoRepiteRandomLog("NoRepiteRandom", "getRandom", "print","tx ");NoRepiteRandomLog("NoRepiteRandom", "getRandom", "println",Note(tx));
			NoRepiteRandomLog("NoRepiteRandom", "getRandom", "print","x ");NoRepiteRandomLog("NoRepiteRandom", "getRandom", "println",Note(x));
			NoRepiteRandomLog("NoRepiteRandom", "getRandom", "println","");
			relation =  1.0f / (x+getMin()+ 0.1f);
			return x+getMin();
		}
		
};
#endif

}

#endif