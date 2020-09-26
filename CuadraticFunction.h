
#ifndef CuadraticFunction_h
#define CuadraticFunction_h

#include "ArrayList.h"
#include "ModifiableFunction.h"

template<class... any>
class CuadraticFunction : public ModifiableFunction<float,any...>{
	public:
		
		CuadraticFunction(){}
		~CuadraticFunction(){}
		
		float f(float x){
			return a*x*x + b*x + c;
		}
		
		float f(float x,float y){
			return a*x*x + b*y*y + c*x*y + d*x + e*y + fvar;
		}
		
		float f(float x,float y,float z){
			return a*x*x + b*y*y + c*z*z + d*x*y + e*x*z + fvar*y*z + g*x + h*y + i*z + j;
		}
		
		float f(float x,float y,float z,float w){
			return a*x*x + b*y*y + c*z*z + d*w*w + e;
		}
		
		float f(float x,float y,float z,float w,float t){
			return a*x*x + b*y*y + c*z*z + d*w*w + e*t*t + fvar;
		}
		
		int getIterationSize(){
			return 10;
		}
		
		//cppObject part
		String getClassName(){return "CuadraticFunction";}
		String toString(){return "CuadraticFunction";}
		
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
