#ifndef MFNeuron_cpp
#define MFNeuron_cpp

#include "MFNeuron.h"

	template<class dataset,class function_return, class... arr>
	MFNeuron<dataset,function_return,arr...>::MFNeuron(){
	}

	template<class dataset,class function_return, class... arr>
	MFNeuron<dataset,function_return,arr...>::~MFNeuron(){
		if(this->functionList != nullptr){
			delete this->functionList;
			this->functionList = nullptr;
		}
	}

	template<class dataset,class function_return, class... arr>
	MFNeuron<dataset,function_return,arr...>* MFNeuron<dataset,function_return,arr...>::add(	int inputD,int outputD, 
																Function<function_return,arr...>* functionD){
		if(this->functionList == nullptr){
			return this;
		}
		this->functionList->add(new MFNEntry<function_return,arr...>(inputD,outputD,functionD));
		return this;
	}

	template<class dataset,class function_return, class... arr>
	DataSet<dataset>* MFNeuron<dataset,function_return,arr...>::compute(DataSet<dataset> *data){
		Log("println", "MFNeuron virtual compute method");
		return data;
	}
	
	template<class dataset,class function_return, class... arr>
	MFNeuron<dataset,function_return,arr...>* MFNeuron<dataset,function_return,arr...>::functionsetup(FunctionSetup a){
		this->functionse = a;
		return this;
	}
	
	template<class dataset,class function_return, class... arr>
	FunctionSetup MFNeuron<dataset,function_return,arr...>::functionsetup(){
		return this->functionse;
	}
	
	template<class dataset,class function_return, class... arr>
	MFNeuron<dataset,function_return,arr...>* MFNeuron<dataset,function_return,arr...>::output(int n,int p,function_return r){
		ArrayList<float> *l = this->outputs.getByPos(n);
		if(l == nullptr){
			return this;
		}
		l->getSize();
		if(p >= l->getSize()){
			return this;
		}
		l->set(p, r);
		return this;
	}
	
	template<class dataset,class function_return, class... arr>
	function_return MFNeuron<dataset,function_return,arr...>::output(int n,int p){
		ArrayList<float> *l = this->outputs.getByPos(n);
		if(l == nullptr){
			return 0;
		}
		function_return* ro = l->getByPos(p);
		if(ro == nullptr){
			return 0;
		}
		return *ro;
	}
	
	template class MFNeuron<float,float,float>;

#endif