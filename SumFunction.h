
#ifndef SumFunction_h
#define SumFunction_h

#include "Function.h"

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
		String getClassName(){return "SumFunction";}
		String toString(){return "SumFunction";}
		
	protected:
};
template<>
float SumFunction<float,float>::f(float x){
	return x;
}

#endif 
