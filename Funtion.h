
#ifndef Funtion_h
#define Funtion_h

#include "cppObject.h"

template<class... any>
class Funtion : public cppObject{
	public:
		virtual ~Funtion(){}
    
		virtual float f(any... mf);
		
		//cppObject part
		virtual String getClassName();
		virtual String toString();
		virtual Funtion* clone();
		
		virtual void set(int p, float var);
		virtual void set(String name, float var);
		
	protected:
	
};

#endif 
