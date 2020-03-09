

#ifndef Random_cpp
#define Random_cpp

#include "Random.h"
	
	Random::~Random(){
	}
	
	void Random::setMax(float Max){
		max = Max;
	}
	
	void Random::setMin(float Min){
		min = Min;
	}
	
	float Random::getMax(){
		return max;
	}
	
	float Random::getMin(){
		return min;
	}
	
	void Random::setSeed(float Seed){
		seed = Seed;
	}
	
	float Random::getSeed(){
		return seed;
	}
	
	float Random::getRandom(){
		return 0;
	}
	
#endif 
