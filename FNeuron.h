#ifndef FNeuron_h
#define FNeuron_h

#include "DataSet.h"
#include "GameObject.h"
#include "Neuron.h"
#include "Funtion.h"

template<class dataset,class funtion_return, class... arr>
class FNeuron : public Neuron<dataset>{
	public:
		virtual ~FNeuron(); 
		
		virtual Neuron<dataset>* setFuntion(Funtion<funtion_return,arr...>* a);
		virtual Funtion<funtion_return,arr...>* getFuntion();  
	protected:
		Funtion<funtion_return,arr...>* funtion=nullptr;
};

#endif