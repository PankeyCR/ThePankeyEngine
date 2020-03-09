#ifndef Neuron_h
#define Neuron_h

#include "DataSet.h"
#include "GameObject.h"
#include "Computability.h"
#include "Logic.h"
#include "Logger.h"

template<class dataset>
class Neuron : public GameObject{
	public:
		virtual ~Neuron();
		
		virtual DataSet<dataset>* compute(DataSet<dataset> *data); 
		virtual Neuron<dataset>* computability(Computability comp); 
		virtual Computability computability(); 
		virtual Neuron<dataset>* logic(Logic logi); 
		virtual Logic logic(); 
		virtual Neuron<dataset>* error(dataset e); 
		virtual dataset error(); 
	protected:
		Computability computabilitym = Computability::Computable;
		Logic logicm = Logic::LogicGate1x1;
		dataset err;
};

#endif