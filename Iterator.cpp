
#ifndef Iterator_cpp
#define Iterator_cpp

#include "Iterator.h"

	Iterator::Iterator(){
		
	}
	
	Iterator::Iterator(int size){
		this->iterateCount = 0;
		this->iterateSize = size;
	}
	
	Iterator::Iterator(int count, int size){
		this->iterateCount = count;
		this->iterateSize = size;
	}
	
	Iterator::Iterator(Iterator* i){
		this->iR = i;
		this->iterateCount = i->iterateCount;
		this->iterateSize = i->iterateSize;
	}
	
	Iterator::Iterator(const Iterator& i){
		this->iR = i.iR;
		this->iterateCount = i.iterateCount;
		this->iterateSize = i.iterateSize;
	}

	Iterator::~Iterator(){
		
	}
	
	void Iterator::setIteration(int iter){
		this->iterateCount = iter;
	}
	
	int Iterator::getIteration(){
		return this->iterateCount;
	}
	
	void Iterator::setIterationSize(int size){
		if(this->iR != nullptr){
			this->iR->setIterationSize(size);
		}
		this->iterateSize = size;
	}
	
	int Iterator::getIterationSize(){
		if(this->iR != nullptr){
			return this->iR->getIterationSize();
		}
		return this->iterateSize;
	}
	
	void Iterator::refreshIteration(){
		if(this->iR != nullptr){
			this->iR->setIteration(0);
		}
		this->iterateCount = 0;
	}
	
	bool Iterator::last(){
		if(this->iterateCount < 0){
			return false;
		}
		this->iterateCount--;
		return true;
	}
	
	bool Iterator::next(){
		if(this->iterateCount > this->getIterationSize()){
			return false;
		}
		this->iterateCount++;
		return true;
	}
	
	Iterator Iterator::begin(){
		return Iterator(this);
	}
	
	Iterator Iterator::end(){
		return Iterator(this);
	}
	
	Iterator Iterator::operator *(){
		return Iterator(this->getIteration(),this->getIterationSize());
	}
	
	void Iterator::operator ++(){
		this->next();
	}
	
	bool Iterator::operator !=(Iterator i){
		if(this->getIteration() < i.getIterationSize()){
			return true;
		}
		return false;
	}
	
	Iterator& Iterator::operator =(const Iterator& i){
		this->iR = i.iR;
		this->iterateCount = i.iterateCount;
		this->iterateSize = i.iterateSize;
		return *this;
	}
	
#endif 
