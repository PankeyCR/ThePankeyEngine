
#ifndef Function_cpp
#define Function_cpp

#include "Function.h"


	template<class type,class... any>
	Function<type,any...>::Function(){
	}
	
	template<class type,class... any>
	Function<type,any...>::~Function(){
		
	}
		
	//cppObject part
	template<class type,class... any>
	String Function<type,any...>::getClassName(){
		return "Function";
	}
	template<class type,class... any>
	String Function<type,any...>::toString(){
		return "Function";
	}
	template<class type,class... any>
	Function<type,any...>* Function<type,any...>::clone(){
		return this;
	}
	
	template<class type,class... any>
	void Function<type,any...>::set(int p, type var){
	}
	
	template<class type,class... any>
	void Function<type,any...>::set(String name, type var){
		
	}
		
	template<class type,class... any>
	int Function<type,any...>::getIterationSize(){
	}
		
	template<class type,class... any>
	type Function<type,any...>::getValue(){
	}
		
	template<class type,class... any>
	type *Function<type,any...>::getPointer(){
	}
		
	template<class type,class... any>
	String Function<type,any...>::getName(){
		return "";
	}
		
	template<class type,class... any>
	bool Function<type,any...>::isModifiable(){
		return false;
	}
		
	template<class type,class... any>
	void Function<type,any...>::set(type var){
	}
	
	template<class type,class... any>
	type Function<type,any...>::f(any... x){
	}
	
	
	
	template class Function<float,float>;	
	
	
	
	
#endif 
