

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
		Log("AbsoluteRandom", "getRandom", "println","");
		Log("AbsoluteRandom", "getRandom", "println","absoluterandom");
		Log("AbsoluteRandom", "getRandom", "print","time ");Log("AbsoluteRandom", "getRandom", "println",String(time));
		Log("AbsoluteRandom", "getRandom", "print","d ");Log("AbsoluteRandom", "getRandom", "println",String(d));
		Log("AbsoluteRandom", "getRandom", "print","dx ");Log("AbsoluteRandom", "getRandom", "println",String(dx));
		Log("AbsoluteRandom", "getRandom", "print","tdx ");Log("AbsoluteRandom", "getRandom", "println",String(tdx));
		Log("AbsoluteRandom", "getRandom", "print","tx ");Log("AbsoluteRandom", "getRandom", "println",String(tx));
		Log("AbsoluteRandom", "getRandom", "print","x ");Log("AbsoluteRandom", "getRandom", "println",String(x));
		Log("AbsoluteRandom", "getRandom", "println","");
		return x+getMin();
	}
	
#endif 
