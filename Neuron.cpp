#ifndef Neuron_cpp
#define Neuron_cpp

#include "Neuron.h"

	template<class dataset,class funtion_return, class... arr>
	Neuron<dataset,funtion_return,arr...>::~Neuron(){
		
	}

	template<class dataset,class funtion_return, class... arr>
	DataSet<dataset> *Neuron<dataset,funtion_return,arr...>::compute(DataSet<dataset> *data){
		return data;
	}
	
	template<class dataset,class funtion_return, class... arr>
	Neuron<dataset,funtion_return,arr...> *Neuron<dataset,funtion_return,arr...>::setFuntion(Funtion<funtion_return,arr...> *a){
		this->funtion = a;
		return this;
	}
	
	template<class dataset,class funtion_return, class... arr>
	Funtion<funtion_return,arr...> *Neuron<dataset,funtion_return,arr...>::getFuntion(){
		return this->funtion;
	}
	
	template class Neuron<long,float,float>;
	template class Neuron<char,float,float>;
	template class Neuron<float,float,float>;
	template class Neuron<double,float,float>;
	template class Neuron<String,String,String>;

#endif