#ifndef MFNEntry_cpp
#define MFNEntry_cpp

#include "MFNEntry.h"

	template<class function_return, class... arr>
	MFNEntry<function_return,arr...>::MFNEntry(){
		
	}
	
	template<>
	MFNEntry<float,float>::MFNEntry(	int inputD,int outputD, 
										Function<float,float>* functionD){
		this->inputE=inputD;
		this->outputE=outputD;
		this->functionE=functionD;
	}

	template<class function_return, class... arr>
	MFNEntry<function_return,arr...>::~MFNEntry(){
	}

	template<class function_return, class... arr>
	int MFNEntry<function_return,arr...>::input(){
		return this->inputE;
	}

	template<class function_return, class... arr>
	int MFNEntry<function_return,arr...>::output(){
		return this->outputE;
	}

	template<class function_return, class... arr>
	Function<function_return,arr...>* MFNEntry<function_return,arr...>::function(){
		return this->functionE;
	}
	
	template<class function_return, class... arr>
	void MFNEntry<function_return,arr...>::operator=(MFNEntry<function_return,arr...> b) {
		this->inputE=b.inputE;
		this->outputE=b.outputE;
		this->functionE=b.functionE;
	}
	
	template<class function_return, class... arr>
	bool MFNEntry<function_return,arr...>::operator==(MFNEntry<function_return,arr...> b) {
			return true;
	}
	
	template<class function_return, class... arr>
	bool MFNEntry<function_return,arr...>::operator!=(MFNEntry<function_return,arr...> b) {
			return false;
	}
	
	template class MFNEntry<float,float>;

#endif