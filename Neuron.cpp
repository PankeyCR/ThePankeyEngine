#ifndef Neuron_cpp
#define Neuron_cpp

#include "Neuron.h"

	template<class dataset>
	Neuron<dataset>::~Neuron(){
		
	}

	template<class dataset>
	DataSet<dataset> *Neuron<dataset>::compute(DataSet<dataset> *data){
		return data;
	}
	
	template class Neuron<long>;
	template class Neuron<char>;
	template class Neuron<float>;
	template class Neuron<double>;
	template class Neuron<String>;

#endif

