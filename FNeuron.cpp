#ifndef FNeuron_cpp
#define FNeuron_cpp

#include "FNeuron.h"

	template<class dataset,class function_return, class... arr>
	FNeuron<dataset,function_return,arr...>::~FNeuron(){
		
	}
	
	template<class dataset,class function_return, class... arr>
	Neuron<dataset> *FNeuron<dataset,function_return,arr...>::setFunction(Function<function_return,arr...> *a){
		this->function = a;
		return this;
	}
	
	template<class dataset,class function_return, class... arr>
	Function<function_return,arr...> *FNeuron<dataset,function_return,arr...>::getFunction(){
		return this->function;
	}
	
	template<class dataset,class function_return, class... arr>
	Neuron<dataset> *FNeuron<dataset,function_return,arr...>::setFuntionSetup(FunctionSetup a){
		this->functionse = a;
		return this;
	}
	
	template<class dataset,class function_return, class... arr>
	FunctionSetup FNeuron<dataset,function_return,arr...>::getFuntionSetup(){
		return this->functionse;
	}
	
	template class FNeuron<long,float,float>;
	template class FNeuron<char,float,float>;
	template class FNeuron<float,float,float>;
	template class FNeuron<double,float,float>;
	template class FNeuron<String,String,String>;

#endif