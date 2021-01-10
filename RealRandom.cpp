

#ifndef RealRandom_cpp
#define RealRandom_cpp

#include "RealRandom.h"

	RealRandom::RealRandom(){
		limitMax = ((float)2147483646/1000000.0f);
		RealRandomLog("RealRandom", "Contructor", "println",String(limitMax));
	}
	
	RealRandom::~RealRandom(){
	}
	
	float RealRandom::getRandom(){
		float time = ((float)micros()/1000000.0f);
		float d = getMax()-getMin();
		float dx = ((float)limitMax/(this->seed*10.0f));
		float tdx = ((float)(time/dx));
		float tx = (((float)(tdx))-((long)(tdx)));
		float x = d*tx;
		RealRandomLog("RealRandom", "getRandom", "println","");
		RealRandomLog("RealRandom", "getRandom", "println","realrandom");
		RealRandomLog("RealRandom", "getRandom", "print","time ");RealRandomLog("RealRandom", "getRandom", "println",String(time));
		RealRandomLog("RealRandom", "getRandom", "print","d ");RealRandomLog("RealRandom", "getRandom", "println",String(d));
		RealRandomLog("RealRandom", "getRandom", "print","dx ");RealRandomLog("RealRandom", "getRandom", "println",String(dx));
		RealRandomLog("RealRandom", "getRandom", "print","tdx ");RealRandomLog("RealRandom", "getRandom", "println",String(tdx));
		RealRandomLog("RealRandom", "getRandom", "print","tx ");RealRandomLog("RealRandom", "getRandom", "println",String(tx));
		RealRandomLog("RealRandom", "getRandom", "print","x ");RealRandomLog("RealRandom", "getRandom", "println",String(x));
		RealRandomLog("RealRandom", "getRandom", "println","");
		return x+getMin();
	}
	
#endif 
