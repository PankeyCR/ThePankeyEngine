
#include "ame_Enviroment.hpp"

#ifndef DuoArray1Neuron_hpp
#define DuoArray1Neuron_hpp

#include "DataSet.hpp"
#include "Function.hpp"
#include "ModifiableFunction.hpp"
#include "Logger.hpp"

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