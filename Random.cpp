

#ifndef Random_cpp
#define Random_cpp

#include "Random.h"
	
	ame::Random::~Random(){
	}
	
	void ame::Random::setMax(float Max){
		max = Max;
	}
	
	void ame::Random::setMin(float Min){
		min = Min;
	}
	
	float ame::Random::getMax(){
		return max;
	}
	
	float ame::Random::getMin(){
		return min;
	}
	
	void ame::Random::setSeed(float Seed){
		seed = Seed;
	}
	
	float ame::Random::getSeed(){
		return seed;
	}
	
	float ame::Random::getRandom(){
		return 0;
	}
	
#endif 
