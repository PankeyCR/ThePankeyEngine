
#ifndef FunctionConfiguration_cpp
#define FunctionConfiguration_cpp

#include "FunctionConfiguration.h"
	
	template<class type,class... any>
	FunctionConfiguration<type,any...>::FunctionConfiguration(){
		
	}
	
	template<class type,class... any>
	FunctionConfiguration<type,any...>::~FunctionConfiguration(){
		
	}
	
	template<class type,class... any>
    Function<type,any...>* FunctionConfiguration<type,any...>::build(){
		return nullptr;
	}
	
	template<class type,class... any>
	FunctionConfiguration<type,any...>* FunctionConfiguration<type,any...>::functionsetup(FunctionSetup a){
		this->functionse = a;
		return this;
	}
	
	template<class type,class... any>
	FunctionSetup FunctionConfiguration<type,any...>::functionsetup(){
		return this->functionse;
	}

	template class FunctionConfiguration<float,float>;
#endif 
