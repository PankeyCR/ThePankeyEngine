
#ifndef NetSet_h
#define NetSet_h

#include "DataSet.h"

class NetSet : public DataSet<float>{
	public:
		NetSet();
		virtual ~NetSet();
		virtual DataSet<float>* dimention(int dimentionPos);
		
		virtual DataSet<float>* vector(int vectorPos, int pointPos);		
		virtual DataSet<float>* set(float t);
		virtual DataSet<float>* remove();		
		virtual float getValue();	
		virtual float *getPointer();
		
		virtual int dimentionSize();
		virtual int vectorSize(int dimentionPos);
		
		virtual void setIteration(int iter);
		virtual int getIterationSize();
		virtual void last();
		virtual void next();
		
		virtual int dimention();
		virtual int vector(int dimentionPos);
    
		//cppObject part
		virtual String getClassName();
		virtual String toString();
		virtual DataSet<float>* clone();
		
	protected:
		int dimentionMap = 0;
		
		int dimentionLimit = 0;
		Map<int,int> *vectorLimit = nullptr;
		Map<int,int> *pointLimit = nullptr;
		Map<int,int> *vectorMap = nullptr;
		
		int fullSize = 0;
};

#endif 
