#ifndef LogicNeuron_h
#define LogicNeuron_h

#include "DataSet.h"
#include "GameObject.h"
#include "PrimitiveList.h"
#include "Neuron.h"
#include "Function.h"
#include "MFNeuron.h"
#include "ArrayList.h"
#include "PrimitiveList.h"
#include "Logger.h"

class LogicNeuron : public MFNeuron<float,float,float>{
	public:
		LogicNeuron();
		virtual ~LogicNeuron();
		
		virtual DataSet<float>* compute(DataSet<float> *data);
	protected:
};

#endif