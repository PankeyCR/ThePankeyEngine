
#include "ame_Level.hpp"

#if defined(ame_untilLevel_6)

#ifndef FunctionProtocol_hpp
#define FunctionProtocol_hpp

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

#endif 