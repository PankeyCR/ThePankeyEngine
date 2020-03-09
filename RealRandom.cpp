

#ifndef RealRandom_cpp
#define RealRandom_cpp

#include "RealRandom.h"

	RealRandom::RealRandom(){
		limitMax = ((float)2147483646/1000000.0f);
		Log("println",String(limitMax));
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
		Log("println","");
		Log("println","realrandom");
		Log("print","time ");Log("println",String(time));
		Log("print","d ");Log("println",String(d));
		Log("print","dx ");Log("println",String(dx));
		Log("print","tdx ");Log("println",String(tdx));
		Log("print","tx ");Log("println",String(tx));
		Log("print","x ");Log("println",String(x));
		Log("println","");
		return x+getMin();
	}
	
#endif 
