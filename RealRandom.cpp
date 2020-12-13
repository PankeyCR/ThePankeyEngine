

#ifndef RealRandom_cpp
#define RealRandom_cpp

#include "RealRandom.h"

	RealRandom::RealRandom(){
		limitMax = ((float)2147483646/1000000.0f);
		Log("RealRandom", "Contructor", "println",String(limitMax));
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
		Log("RealRandom", "getRandom", "println","");
		Log("RealRandom", "getRandom", "println","realrandom");
		Log("RealRandom", "getRandom", "print","time ");Log("RealRandom", "getRandom", "println",String(time));
		Log("RealRandom", "getRandom", "print","d ");Log("RealRandom", "getRandom", "println",String(d));
		Log("RealRandom", "getRandom", "print","dx ");Log("RealRandom", "getRandom", "println",String(dx));
		Log("RealRandom", "getRandom", "print","tdx ");Log("RealRandom", "getRandom", "println",String(tdx));
		Log("RealRandom", "getRandom", "print","tx ");Log("RealRandom", "getRandom", "println",String(tx));
		Log("RealRandom", "getRandom", "print","x ");Log("RealRandom", "getRandom", "println",String(x));
		Log("RealRandom", "getRandom", "println","");
		return x+getMin();
	}
	
#endif 
