
#ifndef Funtion_h
#define Funtion_h

#include "cppObject.h"
#include "Iterator.h"

template<class type,class... any>
class Funtion : public cppObject , public Iterator{
	public:
		virtual ~Funtion(){}
    
		virtual type f(any... mf);
		
		//cppObject part
		virtual String getClassName();
		virtual String toString();
		virtual Funtion<type,any...>* clone();
		
		virtual void set(int p, type var);
		virtual void set(String name, type var);
		
		virtual int getIterationSize();
		virtual type getValue();
		virtual type* getPointer();
		virtual String getName();
		virtual bool isModifiable();
		virtual void set(type var);
		
	protected:
	
};

#endif 
