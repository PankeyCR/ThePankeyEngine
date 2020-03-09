#ifndef MFNeuron_h
#define MFNeuron_h

#include "DataSet.h"
#include "GameObject.h"
#include "PrimitiveList.h"
#include "Neuron.h"
#include "Function.h"
#include "MFNEntry.h"
#include "PrimitiveList.h"
#include "FunctionSetup.h"
#include "ArrayList.h"

//template<class dataset,class sizeZ, class sizeY, class sizeX>
template<class dataset,class function_return, class... arr>
class MFNeuron : public Neuron<dataset>{
	public:
		MFNeuron();
		virtual ~MFNeuron();
		
		virtual DataSet<dataset>* compute(DataSet<dataset> *data); 
		virtual MFNeuron<dataset,function_return,arr...>* add(	int inputD,int outputD, 
																Function<function_return,arr...>* functionD); 
		
		virtual MFNeuron<dataset,function_return,arr...>* functionsetup(FunctionSetup a);
		virtual FunctionSetup functionsetup();
		
		virtual MFNeuron<dataset,function_return,arr...>* output(int n,int p,function_return r);
		virtual function_return output(int n,int p);  
	protected:
		List<MFNEntry<function_return,arr...>>* functionList=nullptr;
		FunctionSetup functionse=FunctionSetup::ZeroStart;
		ArrayList<ArrayList<function_return>> outputs;
};

#endif