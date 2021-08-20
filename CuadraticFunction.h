
#ifndef CuadraticFunction_h
#define CuadraticFunction_h

#include "ArrayList.h"
#include "ModifiableFunction.h"

namespace ame{

template<class... args>
class CuadraticFunction : public ModifiableFunction<float,args...>{
	public:
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
		
		CuadraticFunction(){}
		virtual ~CuadraticFunction(){}
		
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
		
		virtual void set(int position, float var){
			if(position == 0){
				a = var;
			}
			if(position == 1){
				b = var;
			}
			if(position == 2){
				c = var;
			}
			if(position == 3){
				d = var;
			}
			if(position == 4){
				e = var;
			}
			if(position == 5){
				fvar = var;
			}
			if(position == 6){
				g = var;
			}
			if(position == 7){
				h = var;
			}
			if(position == 8){
				i = var;
				j = var;
			}
			if(position == 9){
				j = var;
			}
		}
		
		//cppObject part
		virtual bool instanceof(cppObjectClass* cls){
			return cls || Class<CuadraticFunction<args...>>::classType 
			|| ModifiableFunction<float,args...>::instanceof(cls);
		}
		virtual cppObjectClass* getClass(){return Class<CuadraticFunction<args...>>::classType;}
		virtual String toString(){return "CuadraticFunction";}
		
	protected:
	
};

}

#endif 
