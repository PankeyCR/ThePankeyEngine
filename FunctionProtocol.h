
#ifndef FunctionProtocol_h
#define FunctionProtocol_h

#include "Function.h"
#include "FunctionMetric.h"

template<class T,class... args>
class FunctionProtocol{
	public:
		FunctionProtocol(){}
		virtual ~FunctionProtocol(){}
		
		virtual Function<T,args...>* createFunction(FunctionMetric<T,args...>* metric){
			return nullptr;
		}
		virtual void initializeFunction(FunctionMetric<T,args...>* metric){
			
		}
		virtual void fit(FunctionMetric<T,args...>* metric, args... a){
			
		}
		virtual bool evaluate(Function<T,args...>* fx, FunctionMetric<T,args...>* metric, args... a){
			return fx->f(a...) < metric->getError();
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

#endif 
