
#include "ame_Enviroment.hpp"

#if defined(DISABLE_SumFunction)
	#define SumFunction_hpp
#endif

#ifndef SumFunction_hpp
#define SumFunction_hpp
#define SumFunction_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Function.hpp"

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
		Note toNote(){return "SumFunction";}
		
	protected:
};
template<>
float SumFunction<float,float>::f(float x){
	return x;
}

}

#endif