

#ifndef RealRandom_cpp
#define RealRandom_cpp

#include "RealRandom.h"

	RealRandom::RealRandom(){
		limitMax = ((float)2147483646/1000000.0f);
	}
	
	float RealRandom::getRandom(){
		float time = ((float)micros()/1000000.0f);
		float d = getMax()-getMin();
		float dx = ((float)limitMax/(getSeed()*10000.0f));
		float tdx = abs((float)(time/dx));
		float tx = (((float)(tdx))-((long)(tdx)));
		float x = d*tx;
		return x+getMin();
	}
	
#endif 
