#ifndef FNeuron_cpp
#define FNeuron_cpp

#include "FNeuron.h"

	template<class dataset,class funtion_return, class... arr>
	FNeuron<dataset,funtion_return,arr...>::~FNeuron(){
		
	}
	
	template<class dataset,class funtion_return, class... arr>
	Neuron<dataset> *FNeuron<dataset,funtion_return,arr...>::setFuntion(Funtion<funtion_return,arr...> *a){
		this->funtion = a;
		return this;
	}
	
	template<class dataset,class funtion_return, class... arr>
	Funtion<funtion_return,arr...> *FNeuron<dataset,funtion_return,arr...>::getFuntion(){
		return this->funtion;
	}
	
	template class FNeuron<long,float,float>;
	template class FNeuron<char,float,float>;
	template class FNeuron<float,float,float>;
	template class FNeuron<double,float,float>;
	template class FNeuron<String,String,String>;

#endif