#ifndef Neuron_h
#define Neuron_h

#include "DataSet.h"
#include "GameObject.h"

template<class dataset>
class Neuron : public GameObject{
	public:
		virtual ~Neuron();
		
		virtual DataSet<dataset> *compute(DataSet<dataset> *data); 
	protected:
	
};

#endif