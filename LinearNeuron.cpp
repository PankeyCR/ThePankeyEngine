#ifndef LinearNeuron_cpp
#define LinearNeuron_cpp

#include "LinearNeuron.h"


	LinearNeuron::LinearNeuron(){
		
	}

	LinearNeuron::~LinearNeuron(){
		
	}

	Neuron<float> *LinearNeuron::connect(Neuron<float> *neuron){
		Netmap.add(neuron);
	}

	Neuron<float> *LinearNeuron::getNeuron(int id){
		if(id == 0){
			return Netmap.getByPos(id);
		}
		if(id == 1){
			return Netmap.getByPos(id);
		}
		return NULL;
	}

	Neuron<float> *LinearNeuron::removeNeuron(int id){
		if(id == 0){
			Netmap.removeByPos(id);
		}
		if(id == 1){
			Netmap.removeByPos(id);
		}
	}

	List<Neuron<float>> *LinearNeuron::getNeurons(){
		return &Netmap;
	}

		
	bool LinearNeuron::initialize(){
		
	}

	DataSet<float> *LinearNeuron::compute(DataSet<float> *data){
		// if(info == "back"){
			// RealRandom r;
			// r.setMax(1);
			// r.setMin(0);
			// r.setSeed(54251);
			// setWeight(r.getRandom());
			// float inputN = input * getWeight();
			// inN->compute(info, data);
		// }
		// if(info == "foward"){
			// float inputN = input * getWeight();
			// outN->compute(info, data);
		// }
	}
	
	String LinearNeuron::getClassName(){
		return "LinearNeuron";
	}
	
	String LinearNeuron::toString(){
		return "LinearNeuron";
	}
	
	bool LinearNeuron::equal(cppObject *b){
		if(b == this){
			return true;
		}
		if(b->getClassName() == this->getClassName()){
			return true;
		}
		return false;
	}
	
	Neuron<float> *LinearNeuron::clone(){
		// LinearNeuron *y = new LinearNeuron();
		// y->setWeight(0, this->getWeight(0));
		// y->setWeight(1, this->getWeight(1));
		// y->setWeight(2, this->getWeight(2));
		// y->setWeight(3, this->getWeight(3));
		// y->setWeight(4, this->getWeight(4));
		// return y;
		return this;
	}


#endif