
#ifndef CodeRoute_cpp
#define CodeRoute_cpp

#include "CodeRoute.h"

#define blockRoute(integer) 
	
	CodeRoute::CodeRoute(){
	}
	
	CodeRoute::~CodeRoute(){
	}
	
	bool CodeRoute::block(int v){
		if(bVersion != v){
			bVersion = v ;
			return false;
		}
		return true;
	}
	
	bool CodeRoute::update(int v){
		if(uVersion != v){
			uVersion = v ;
			return false;
		}
		return true;
	}
	
#endif 