
#ifndef SumFunction_h
#define SumFunction_h

#include "Function.h"

namespace ame{

template<class T, class... any>
class SumFunction : public Function<T,any...>{
	public:
		
		SumFunction(){}
		~SumFunction(){}
		
		T f(any... x){
			return function(x...);
		}
		
		template<class... tt>
		T function(T x,tt... y){
			SumFunction<T,tt...> t;
			return x + t.f(y...);
		}
		
		//cppObject part
		cppObjectClass* getClass(){return Class<SumFunction>::classType;}
		String toString(){return "SumFunction";}
		
	protected:
};
template<>
float SumFunction<float,float>::f(float x){
	return x;
}

}

#endif 
