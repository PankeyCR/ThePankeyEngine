

#ifndef AbsoluteRandom_cpp
#define AbsoluteRandom_cpp

#include "AbsoluteRandom.h"

	AbsoluteRandom::AbsoluteRandom(){
		this->realRandom = new RealRandom();
		this->realRandom->setSeed(78545);
		limitMax = ((float)2147483646/1000000.0f);
	}

	AbsoluteRandom::AbsoluteRandom(float seed){
		this->realRandom = new RealRandom();
		this->realRandom->setSeed(seed);
		this->realRandom->setMax(seed);
		limitMax = ((float)2147483646/1000000.0f);
	}
	
	AbsoluteRandom::~AbsoluteRandom(){
		delete this->realRandom;
	}
	
	float AbsoluteRandom::getRandom(){
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
		AbsoluteRandomLog("AbsoluteRandom", "getRandom", "print","time ");AbsoluteRandomLog("AbsoluteRandom", "getRandom", "println",String(time));
		AbsoluteRandomLog("AbsoluteRandom", "getRandom", "print","d ");AbsoluteRandomLog("AbsoluteRandom", "getRandom", "println",String(d));
		AbsoluteRandomLog("AbsoluteRandom", "getRandom", "print","dx ");AbsoluteRandomLog("AbsoluteRandom", "getRandom", "println",String(dx));
		AbsoluteRandomLog("AbsoluteRandom", "getRandom", "print","tdx ");AbsoluteRandomLog("AbsoluteRandom", "getRandom", "println",String(tdx));
		AbsoluteRandomLog("AbsoluteRandom", "getRandom", "print","tx ");AbsoluteRandomLog("AbsoluteRandom", "getRandom", "println",String(tx));
		AbsoluteRandomLog("AbsoluteRandom", "getRandom", "print","x ");AbsoluteRandomLog("AbsoluteRandom", "getRandom", "println",String(x));
		AbsoluteRandomLog("AbsoluteRandom", "getRandom", "println","");
		return x+getMin();
	}
	
#endif 
