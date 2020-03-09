
#ifndef CuadraticFunction_h
#define CuadraticFunction_h

#include "Function.h"

template<class... any>
class CuadraticFunction : public Function<float,any...>{
	public:
		
		CuadraticFunction();
		virtual ~CuadraticFunction();
    
		virtual float f(any... mf);
		
		//cppObject part
		virtual String getClassName();
		virtual String toString();
		virtual CuadraticFunction<any...>* clone();
		
		virtual void set(int p, float var);
		virtual void set(String name, float var);
		
		virtual int getIterationSize();
		virtual float getValue();
		virtual float* getPointer();
		virtual String getName();
		virtual bool isModifiable();
		virtual void set(float var);
		
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
