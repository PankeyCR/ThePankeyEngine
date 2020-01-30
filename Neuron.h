#ifndef Neuron_h
#define Neuron_h

#include "DataSet.h"
#include "GameObject.h"
#include "Funtion.h"

template<class dataset,class funtion_return, class... arr>
class Neuron : public GameObject{
	public:
		virtual ~Neuron();
		
		virtual DataSet<dataset> *compute(DataSet<dataset> *data);  
		
		virtual Neuron<dataset,funtion_return,arr...>* setFuntion(Funtion<funtion_return,arr...>* a);
		virtual Funtion<funtion_return,arr...>* getFuntion();  
	protected:
		Funtion<funtion_return,arr...>* funtion=nullptr;
};

#endif