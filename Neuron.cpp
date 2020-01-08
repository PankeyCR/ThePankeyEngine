#ifndef Neuron_cpp
#define Neuron_cpp

#include "Neuron.h"

	template<class dataset>
	Neuron<dataset>::Neuron(){
		
	}

	template<class dataset>
	Neuron<dataset>::~Neuron(){
		
	}
	
	template<class dataset>
	void Neuron<dataset>::setWeight(int id, float set){
		
	}
	
	template<class dataset>
	float Neuron<dataset>::getWeight(int id){
		
		return 0;
	}

	template<class dataset>
	Neuron<dataset> *Neuron<dataset>::connect(Neuron<dataset> *neuron){
		
	}

	template<class dataset>
	Neuron<dataset> *Neuron<dataset>::getNeuron(int id ){
		
	}

	template<class dataset>
	Neuron<dataset> *Neuron<dataset>::removeNeuron(int id ){
		
	}

	template<class dataset>
	List<Neuron<dataset>> *Neuron<dataset>::getNeurons(){
		
	}

	template<class dataset>
	bool Neuron<dataset>::initialize(){
		
	}

	template<class dataset>
	DataSet<dataset> *Neuron<dataset>::compute(DataSet<dataset> *data){
		
	}
	
	template<class dataset>
	String Neuron<dataset>::getClassName(){
		return "Neuron";
	}
	
	template<class dataset>
	String Neuron<dataset>::toString(){
		return "Neuron";
	}
	
	template<class dataset>
	bool Neuron<dataset>::equal(cppObject *b){
		if(b == this){
			return true;
		}
		if(b->getClassName() == this->getClassName()){
			return true;
		}
		return false;
	}
	
	template<class dataset>
	Neuron<dataset> *Neuron<dataset>::clone(){
		// Neuron *y = new Neuron();
		// y->setWeight(0, this->getWeight(0));
		// y->setWeight(1, this->getWeight(1));
		// y->setWeight(2, this->getWeight(2));
		// y->setWeight(3, this->getWeight(3));
		// y->setWeight(4, this->getWeight(4));
		// return y;
		return this;
	}
	
	template<class dataset>
	Neuron<dataset> Neuron<dataset>::operator=(Neuron<dataset> n){
		
	}
	
	template<class dataset>
	bool Neuron<dataset>::operator==(Neuron<dataset> n){
		return this->getClassName() == n.getClassName();
	}
	
	template<class dataset>
	bool Neuron<dataset>::operator!=(Neuron<dataset> n){
		return this->getClassName() != n.getClassName();
	}
	
	template class Neuron<long>;
	template class Neuron<char>;
	template class Neuron<float>;
	template class Neuron<double>;

#endif