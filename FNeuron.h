#ifndef FNeuron_h
#define FNeuron_h

#include "DataSet.h"
#include "GameObject.h"
#include "Neuron.h"
#include "Function.h"
#include "FunctionSetup.h"

template<class dataset,class function_return, class... arr>
class FNeuron : public Neuron<dataset>{
	public:
		virtual ~FNeuron(); 
		
		virtual Neuron<dataset>* setFunction(Function<function_return,arr...>* a);
		virtual Function<function_return,arr...>* getFunction();  
		
		virtual Neuron<dataset>* setFuntionSetup(FunctionSetup a);
		virtual FunctionSetup getFuntionSetup();  
	protected:
		Function<function_return,arr...>* function=nullptr;
		FunctionSetup functionse=FunctionSetup::ZeroStart;
};

#endif