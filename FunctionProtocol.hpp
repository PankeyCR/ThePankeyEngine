
#include "ame_Enviroment.hpp"

#if defined(DISABLE_FunctionProtocol)
	#define FunctionProtocol_hpp
#endif

#ifndef FunctionProtocol_hpp
#define FunctionProtocol_hpp
#define FunctionProtocol_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Function.hpp"
#include "FunctionMetric.hpp"

namespace ame{

template<class T,class... args>
class FunctionProtocol{
	public:
		FunctionProtocol(){}
		virtual ~FunctionProtocol(){}
		
		virtual Function<T,args...>* createFunction(FunctionMetric<T,args...>* metric){
			return nullptr;
		}
		virtual void initializeFunction(Function<T,args...>* fx, FunctionMetric<T,args...>* metric){
			
		}
		virtual void fit(Function<T,args...>* fx, FunctionMetric<T,args...>* metric, args... a){
			
		}
		virtual bool evaluate(Function<T,args...>* fx, FunctionMetric<T,args...>* metric, args... a){
			return ((metric->getOutput() - fx->f(a...)) < metric->getError()) && 
					((metric->getOutput() - fx->f(a...)) > 0);
		}
		virtual void operator=(FunctionProtocol b){
			
		}
		virtual bool operator==(FunctionProtocol b){
			return false;
		}
		virtual bool operator!=(FunctionProtocol b){
			return false;
		}
		
	protected:
};

}

#endif