
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Iterator)
	#define Iterator_hpp
#endif

#ifndef Iterator_hpp
#define Iterator_hpp
#define Iterator_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

class Iterator{
	public:
		Iterator(){}
		Iterator(int size){
			this->iterateCount = 0;
			this->iterateSize = size;
		}
	
		Iterator(int count, int size){
			this->iterateCount = count;
			this->iterateSize = size;
		}
		
		Iterator(Iterator* i){
			this->iR = i;
			this->iterateCount = i->iterateCount;
			this->iterateSize = i->iterateSize;
		}
		
		Iterator(const Iterator& i){
			this->iR = i.iR;
			this->iterateCount = i.iterateCount;
			this->iterateSize = i.iterateSize;
		}

		virtual ~Iterator(){}
		virtual void setIteration(int iter){
			this->iterateCount = iter;
		}
		
		virtual int getIteration(){
			return this->iterateCount;
		}
		
		virtual void setIterationSize(int size){
			if(this->iR != nullptr){
				this->iR->setIterationSize(size);
			}
			this->iterateSize = size;
		}
		
		virtual int getIterationSize(){
			if(this->iR != nullptr){
				return this->iR->getIterationSize();
			}
			return this->iterateSize;
		}
		
		virtual void refreshIteration(){
			if(this->iR != nullptr){
				this->iR->setIteration(0);
			}
			this->iterateCount = 0;
		}
		
		virtual bool last(){
			if(this->iterateCount < 0){
				return false;
			}
			this->iterateCount--;
			return true;
		}
		
		virtual bool next(){
			if(this->iterateCount > this->getIterationSize()){
				return false;
			}
			this->iterateCount++;
			return true;
		}
		
		virtual Iterator begin(){
			return ame::Iterator(this);
		}
		
		virtual Iterator end(){
			return ame::Iterator(this);
		}
		
		virtual Iterator operator *(){
			return ame::Iterator(this->getIteration(),this->getIterationSize());
		}
		
		virtual void operator ++(){
			this->next();
		}
		
		virtual bool operator !=(Iterator i){
			if(this->getIteration() < i.getIterationSize()){
				return true;
			}
			return false;
		}
		
		virtual Iterator& operator =(const Iterator& i){
			this->iR = i.iR;
			this->iterateCount = i.iterateCount;
			this->iterateSize = i.iterateSize;
			return *this;
		}
		
	protected:
		int iterateCount = 0;
		int iterateSize = 0;
		Iterator* iR = nullptr;
};

}

#endif