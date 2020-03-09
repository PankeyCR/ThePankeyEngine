#ifndef Neuron_cpp
#define Neuron_cpp

#include "Neuron.h"

	template<class dataset>
	Neuron<dataset>::~Neuron(){
		
	}

	template<class dataset>
	DataSet<dataset> *Neuron<dataset>::compute(DataSet<dataset> *data){
		Log("println", "Neuron virtual compute method");
		return data;
	}

	template<class dataset>
	Neuron<dataset> *Neuron<dataset>::computability(Computability comp){
		this->computabilitym = comp;
		return this;
	}

	template<class dataset>
	Computability Neuron<dataset>::computability(){
		return this->computabilitym;
	}

	template<class dataset>
	Neuron<dataset> *Neuron<dataset>::logic(Logic logi){
		this->logicm = logi;
		return this;
	}

	template<class dataset>
	Logic Neuron<dataset>::logic(){
		return this->logicm;
	}

	template<class dataset>
	Neuron<dataset> *Neuron<dataset>::error(dataset e){
		this->err = e;
		return this;
	}

	template<class dataset>
	dataset Neuron<dataset>::error(){
		return this->err;
	}
	
	template class Neuron<long>;
	template class Neuron<char>;
	template class Neuron<float>;
	template class Neuron<double>;
	template class Neuron<String>;

#endif

