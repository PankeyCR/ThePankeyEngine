
#include "ame_Enviroment.hpp"

#if defined(DISABLE_FunctionConfiguration)
	#define FunctionConfiguration_hpp
#endif

#ifndef FunctionConfiguration_hpp
#define FunctionConfiguration_hpp
#define FunctionConfiguration_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "GameBuilder.hpp"
#include "Function.hpp"
#include "FunctionProtocol.hpp"
#include "FunctionMetric.hpp"
#include "LinkedList.hpp"

#ifdef FunctionConfigurationLogApp
	#include "Logger.hpp"
	#define FunctionConfigurationLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define FunctionConfigurationLog(name,method,type,mns)
#endif

namespace ame{

template<class T,class... args>
class FunctionConfiguration{
	public:
	FunctionConfiguration(){}
	virtual ~FunctionConfiguration(){}
	
	virtual void add(FunctionMetric<T,args...>* metric, FunctionProtocol<T,args...>* protocol){
		metrics.addPointer(metric);
		protocols.addPointer(protocol);
	}
	
	virtual Function<T,args...>* build(args... a){
		Function<T,args...>* fx = nullptr;
		for(int x = 0; x < protocols.getPosition(); x++){
			FunctionMetric<T,args...>* metric = metrics.getByPosition(x);
			FunctionProtocol<T,args...>* protocol = protocols.getByPosition(x);
			fx = protocol->createFunction(metric);
			protocol->initializeFunction(fx, metric);
			protocol->fit(fx, metric, a...);
			if(protocol->evaluate(fx, metric, a...)){
				break;
			}else{
				if(fx != nullptr){
					delete fx;
					fx = nullptr;
				}
			}
		}
		return fx;
	}  
		
	protected:
	LinkedList<FunctionMetric<T,args...>> metrics;
	LinkedList<FunctionProtocol<T,args...>> protocols;
};

}

#endif