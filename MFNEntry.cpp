#ifndef MFNEntry_cpp
#define MFNEntry_cpp

#include "MFNEntry.h"

	template<class function_return, class... arr>
	ame::MFNEntry<function_return,arr...>::MFNEntry(){
		
	}
	
	template<class function_return, class... arr>
	ame::MFNEntry<function_return,arr...>::MFNEntry(	int inputD,int outputD, 
										ame::Function<function_return,arr...>* functionD){
		this->inputE=inputD;
		this->outputE=outputD;
		this->functionE=functionD;
	}

	template<class function_return, class... arr>
	ame::MFNEntry<function_return,arr...>::~MFNEntry(){
	}

	template<class function_return, class... arr>
	int ame::MFNEntry<function_return,arr...>::input(){
		return this->inputE;
	}

	template<class function_return, class... arr>
	int ame::MFNEntry<function_return,arr...>::output(){
		return this->outputE;
	}

	template<class function_return, class... arr>
	ame::Function<function_return,arr...>* ame::MFNEntry<function_return,arr...>::function(){
		return this->functionE;
	}
	
	template<class function_return, class... arr>
	void ame::MFNEntry<function_return,arr...>::operator=(ame::MFNEntry<function_return,arr...> b) {
		this->inputE=b.inputE;
		this->outputE=b.outputE;
		this->functionE=b.functionE;
	}
	
	template<class function_return, class... arr>
	bool ame::MFNEntry<function_return,arr...>::operator==(ame::MFNEntry<function_return,arr...> b) {
			return true;
	}
	
	template<class function_return, class... arr>
	bool ame::MFNEntry<function_return,arr...>::operator!=(ame::MFNEntry<function_return,arr...> b) {
			return false;
	}
	
	template class ame::MFNEntry<float,float>;

#endif