
// #ifndef iterateFor

// #define iterateFor

// #define iterate(list) for(list->setIteration(0) ; list->getIteration() < list->getIterationSize(); list->next())
// #define iterateN(list) for(list->setIteration(list->getIterationSize()-1) ; list->getIteration() >= 0; list->last())

// #define iterateLength(list,start,end) for(list->setIteration(start) ; list->getIteration() < end; list->next())
// #define iterateNLength(list,start,end) for(list->setIteration(start-1) ; list->getIteration() >= end; list->last())

// #define iterateV(list) for(list.setIteration(0) ; list.getIteration() < list.getIterationSize(); list.next())
// #define iterateVN(list) for(list.setIteration(list.getIterationSize()-1) ; list.getIteration() >= 0; list.last())

// #define iterateVLength(list,start,end) for(list.setIteration(start) ; list.getIteration() < end; list.next())
// #define iterateVNLength(list,start,end) for(list.setIteration(start-1) ; list.getIteration() >= end; list.last())

// #define fun(method) {IteratorFuntion funtion = method;funtion();}

// #endif


#ifndef Iterator_h
#define Iterator_h

#include "Arduino.h"

// typedef void (*IteratorFuntion)();

class Iterator{
	public:
		Iterator();
		Iterator(int size);
		Iterator(int count, int size);
		Iterator(Iterator* i);
		Iterator(const Iterator& i);
		// Iterator(Iterator&& i);
		virtual ~Iterator();
		virtual void setIteration(int iter);
		virtual int getIteration();
		virtual void setIterationSize(int size);
		virtual int getIterationSize();
		virtual void last();
		virtual void next();
		virtual Iterator begin();
		virtual Iterator end();
		virtual Iterator operator *();
		virtual void operator ++();
		virtual bool operator !=(Iterator i);
		virtual Iterator& operator =(const Iterator& i);
		// virtual Iterator& operator =(Iterator&& i);
	protected:
		int iterateCount = 0;
		int iterateSize = 0;
		Iterator* iR = nullptr;
};

#endif 
