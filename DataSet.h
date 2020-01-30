

#ifndef DataSet_h
#define DataSet_h

#include "Iterator.h"
#include "cppObject.h"
#include "Map.h"

template <class T>
class DataSet : public Iterator , public cppObject{
	public:
		DataSet();
		virtual ~DataSet();
		virtual DataSet<T>* dimention(int dimentionPos);
		
		virtual DataSet<T>* vector(int vectorPos, int pointPos);		
		virtual DataSet<T>* set(T t);
		virtual DataSet<T>* remove();		
		virtual T getValue();	
		virtual T *getPointer();
		
		virtual int dimentionSize();
		virtual int dimentionVectorSize(int dimentionPos);
		virtual int vectorSize(int dimentionPos, int vectorPos);
		
		virtual DataSet<T>* iterateDimention(int dimention);
		virtual void setIteration(int iter);
		virtual int getIterationSize();
		virtual void last();
		virtual void next();
		
		virtual int dimention();
		virtual int vector(int dimentionPos);
    
		//cppObject part
		virtual String getClassName();
		virtual String toString();
		virtual bool equal(cppObject *b);
		virtual DataSet<T>* clone();
		virtual void operator=(DataSet<T> b);
		virtual bool operator==(DataSet<T> b);
		virtual bool operator!=(DataSet<T> b);
		
	protected:
		int iteratedimention=-1;
};

#endif 
