

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
		float tdx = abs((float)(time/dx));
		float tx = (((float)(tdx))-((long)(tdx)));
		float x = d*tx;
		return x+getMin();
	}
	
#endif 
