
#ifndef Iterator_cpp
#define Iterator_cpp

#include "Iterator.h"

	ame::Iterator::Iterator(){
		
	}
	
	ame::Iterator::Iterator(int size){
		this->iterateCount = 0;
		this->iterateSize = size;
	}
	
	ame::Iterator::Iterator(int count, int size){
		this->iterateCount = count;
		this->iterateSize = size;
	}
	
	ame::Iterator::Iterator(ame::Iterator* i){
		this->iR = i;
		this->iterateCount = i->iterateCount;
		this->iterateSize = i->iterateSize;
	}
	
	ame::Iterator::Iterator(const ame::Iterator& i){
		this->iR = i.iR;
		this->iterateCount = i.iterateCount;
		this->iterateSize = i.iterateSize;
	}

	ame::Iterator::~Iterator(){
		
	}
	
	void ame::Iterator::setIteration(int iter){
		this->iterateCount = iter;
	}
	
	int ame::Iterator::getIteration(){
		return this->iterateCount;
	}
	
	void ame::Iterator::setIterationSize(int size){
		if(this->iR != nullptr){
			this->iR->setIterationSize(size);
		}
		this->iterateSize = size;
	}
	
	int ame::Iterator::getIterationSize(){
		if(this->iR != nullptr){
			return this->iR->getIterationSize();
		}
		return this->iterateSize;
	}
	
	void ame::Iterator::refreshIteration(){
		if(this->iR != nullptr){
			this->iR->setIteration(0);
		}
		this->iterateCount = 0;
	}
	
	bool ame::Iterator::last(){
		if(this->iterateCount < 0){
			return false;
		}
		this->iterateCount--;
		return true;
	}
	
	bool ame::Iterator::next(){
		if(this->iterateCount > this->getIterationSize()){
			return false;
		}
		this->iterateCount++;
		return true;
	}
	
	ame::Iterator ame::Iterator::begin(){
		return ame::Iterator(this);
	}
	
	ame::Iterator ame::Iterator::end(){
		return ame::Iterator(this);
	}
	
	ame::Iterator ame::Iterator::operator *(){
		return ame::Iterator(this->getIteration(),this->getIterationSize());
	}
	
	void ame::Iterator::operator ++(){
		this->next();
	}
	
	bool ame::Iterator::operator !=(ame::Iterator i){
		if(this->getIteration() < i.getIterationSize()){
			return true;
		}
		return false;
	}
	
	ame::Iterator& ame::Iterator::operator =(const ame::Iterator& i){
		this->iR = i.iR;
		this->iterateCount = i.iterateCount;
		this->iterateSize = i.iterateSize;
		return *this;
	}
	
#endif 
