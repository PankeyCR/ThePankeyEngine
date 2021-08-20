#ifndef DuoArray1Neuron_h
#define DuoArray1Neuron_h

#include "DataSet.h"
#include "Function.h"
#include "ModifiableFunction.h"
#include "Logger.h"

namespace ame{

class DuoArray1Neuron : public Neuron<float,float,float>{
	public:
		DuoArray1Neuron(){}
		virtual ~DuoArray1Neuron(){}
		
		virtual DataSet<float>* compute(DataSet<float>* data){
			if(!this->fun->instanceof("ModifiableFunction")){
				return data;
			}
			ModifiableFunction<float,float>* mf = (ModifiableFunction<float,float>*)this->fun;
			int inputDimentionSize = data->dimentionSize(0);
			int outputDimentionSize = data->dimentionSize(1);
			data->space(0)->dimention(0);
			for(int x = 0; x < inputDimentionSize; x++){
				mf->setConstante(x, data->position(x)->getValue());
			}
			data->space(1)->dimention(0);
			for(int x = 0; x < outputDimentionSize; x++){
				data->position(x)->set(mf->f(x));
			}
			return data;
		}
	protected:
};

}

#endif