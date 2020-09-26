#ifndef SCNeuron_h
#define SCNeuron_h

#include "DataSet.h"
#include "Function.h"

class SCNeuron : public Neuron<float,float,float>{
	public:
		SCNeuron(){}
		SCNeuron(int inputS,int inputD,int inputP
					,int outputS,int outputD,int outputP){
			inputPosition = inputP;
			inputDimention = inputD;
			inputSpace = inputS;
			outputPosition = outputP;
			outputDimention = outputD;
			outputSpace = outputS;
		}
		void setInput(int inputS,int inputD,int inputP){
			inputPosition = inputP;
			inputDimention = inputD;
			inputSpace = inputS;
		}
		void setOutput(int outputS,int outputD,int outputP){
			outputPosition = outputP;
			outputDimention = outputD;
			outputSpace = outputS;
		}
		virtual ~SCNeuron(){}
		
		virtual DataSet<float>* compute(DataSet<float> *data){
			data->space(inputSpace)->dimention(inputDimention)->position(inputPosition);
			float computation = this->fun->f(data->getValue());
			data->space(outputSpace)->dimention(outputDimention)->position(outputPosition);
			data->set(computation);
			return data;
		}
	protected:
		int inputPosition = 0;
		int inputDimention = 0;
		int inputSpace = 0;
		int outputPosition = 0;
		int outputDimention = 0;
		int outputSpace = 0;
};

#endif