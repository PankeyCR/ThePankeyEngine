
#ifndef Iterator_h
#define Iterator_h

#include "Arduino.h"

class Iterator{
	public:
		Iterator();
		Iterator(int size);
		Iterator(int count, int size);
		Iterator(Iterator* i);
		Iterator(const Iterator& i);
		virtual ~Iterator();
		virtual void setIteration(int iter);
		virtual int getIteration();
		virtual void setIterationSize(int size);
		virtual int getIterationSize();
		virtual bool last();
		virtual bool next();
		virtual Iterator begin();
		virtual Iterator end();
		virtual Iterator operator *();
		virtual void operator ++();
		virtual bool operator !=(Iterator i);
		virtual Iterator& operator =(const Iterator& i);
	protected:
		int iterateCount = 0;
		int iterateSize = 0;
		Iterator* iR = nullptr;
};

#endif 
