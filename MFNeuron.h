#ifndef MFNeuron_h
#define MFNeuron_h

#include "DataSet.h"
#include "GameObject.h"
#include "PrimitiveList.h"
#include "Neuron.h"
#include "Funtion.h"

//template<class dataset,class sizeZ, class sizeY, class sizeX>
template<class dataset,class funtion_return, class... arr>
class MFNeuron : public Neuron<dataset> , public PrimitiveList<Funtion<funtion_return,arr...>>{
	public:
		MFNeuron();
		virtual ~MFNeuron();
		
		virtual DataSet<dataset> *compute(DataSet<dataset> *data); 
	protected:
		DataSet<dataset>* funtionData=nullptr;
};

#endif