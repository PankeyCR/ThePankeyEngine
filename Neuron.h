#ifndef Neuron_h
#define Neuron_h

#include "DataSet.h"
#include "Function.h"
#include "Logger.h"

template<class T,class... args>
class Neuron{
	public:
		Neuron(){}
		virtual ~Neuron(){}
		
		virtual DataSet<T>* compute(DataSet<T>* data){return data;}
		
		virtual void setFunction(Function<T,args...>* fn){function = fn;}
		virtual Function<T,args...>* getFunction(){return function;}
		
		virtual void setOperator(Operator<T,Function<T,args...>>* o){functionOperator = o;}
		virtual Operator<T,Function<T,args...>>* getOperator(){return functionOperator;}
		
		virtual void setWeight(float w){weight = w;}
		virtual float getWeight(){return weight;}
	protected:
		Function<T,args...>* function = nullptr;
		Operator<T,Function<T,args...>>* functionOperator = nullptr;
		float weight = 1;
};

#endif