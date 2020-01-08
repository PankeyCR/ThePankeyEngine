#ifndef DefaultNeuron_cpp
#define DefaultNeuron_cpp

#include "DefaultNeuron.h"

	
	DefaultNeuron::DefaultNeuron(){
		this->weightList = new PrimitiveList<float>();
		this->neuronList = new PrimitiveList<Neuron<float>>();
	}
	
	
	DefaultNeuron::~DefaultNeuron(){
		if(this->weightList != nullptr){
			delete this->weightList;
			this->weightList = nullptr;
		}		
		if(this->neuronList != nullptr){
			delete this->neuronList;
			this->neuronList = nullptr;
		}
	}

	
	bool DefaultNeuron::initialize(){
		return true;
	}

	
	DataSet<float> *DefaultNeuron::compute(DataSet<float> *data){
		iterate(data){
			float value =this->funtion->f(data->getValue());
			data->set(value);
			iterate(this->neuronList){
				DataSet<float> *ndata = this->neuronList->getPointer()->compute(data);
				if(ndata == nullptr){
					return ndata;
				}
			}
		}
		return data;
	}
	
	
	String DefaultNeuron::getClassName(){
		return "DefaultNeuron";
	}
	
	
	String DefaultNeuron::toString(){
		return "DefaultNeuron";
	}
	
	
	DefaultNeuron *DefaultNeuron::clone(){
		DefaultNeuron *dn = new DefaultNeuron();
		dn->setFuntion(this->getFuntion());
		return dn;
	}
	
	

#endif