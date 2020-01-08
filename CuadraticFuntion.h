
#ifndef CuadraticFuntion_h
#define CuadraticFuntion_h

#include "Funtion.h"

template<class... any>
class CuadraticFuntion : public Funtion<any...>{
	public:
		
		CuadraticFuntion();
		virtual ~CuadraticFuntion();
    
		virtual float f(any... mf);
		
		//cppObject part
		virtual String getClassName();
		virtual String toString();
		virtual CuadraticFuntion* clone();
		
		virtual void set(int p, float var);
		virtual void set(String name, float var);
		
	protected:
		float a = 1;
		float b = 1;
		float c = 1;
		float d = 1;
		float e = 1;
		float fvar = 1;
		float g = 1;
		float h = 1;
		float i = 1;
		float j = 1;
	
};

#endif 
