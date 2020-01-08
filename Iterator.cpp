
#ifndef Iterator_cpp
#define Iterator_cpp
#include "Iterator.h"

	Iterator::Iterator(){
		
	}

	Iterator::~Iterator(){
		
	}
	
	void Iterator::setIteration(int iter){
		this->iterateCount = iter;
	}
	
	int Iterator::getIteration(){
		return this->iterateCount;
	}
	
	int Iterator::getIterationSize(){
		return 0;
	}
	
	void Iterator::last(){
		this->iterateCount--;
	}
	
	void Iterator::next(){
		this->iterateCount++;
	}
	
#endif 
