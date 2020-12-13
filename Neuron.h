#ifndef Neuron_h
#define Neuron_h

#include "DataSet.h"
#include "Function.h"
#include "Logger.h"

template<class dataset, class T,class... args>
class Neuron{
	public:
		Neuron(){}
		virtual ~Neuron(){}
		
		virtual DataSet<dataset>* compute(DataSet<dataset>* data){return data;}
		virtual void setFunction(Function<T,args...>* fn){fun = fn;}
		virtual Function<T,args...>* getFunction(){return fun;}
	protected:
		Function<T,args...>* fun = nullptr;
};

#endif