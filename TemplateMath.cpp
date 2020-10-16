

#ifndef TemplateMath_cpp
#define TemplateMath_cpp

#include "TemplateMath.h"

	TemplateMath::TemplateMath(){
	}
	
	TemplateMath::~TemplateMath(){
	}
	
	template<>
	long TemplateMath::exp<0>(){
		return 1l;
	}
		
	long TemplateMath::exp(int x){
		if(x <= 0){
			return 1l;
		}
		return 10l * exp(x-1);
	}
	

#endif 
