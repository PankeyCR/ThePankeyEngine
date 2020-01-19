

#ifndef SimpleEvent_cpp
#define SimpleEvent_cpp

#include "SimpleEvent.h"

	template<class T>
	SimpleEvent<T>::SimpleEvent(){
		
	}
	template<class T>
	SimpleEvent<T>::~SimpleEvent(){
		
	}
	template<class T>
	void SimpleEvent<T>::event(){
		this->m(this->var);
	}
	template<class T>
	void SimpleEvent<T>::event(T c){
		if(this->var != c){
			this->var = c;
			this->m(this->var);
		}
	}
	template<class T>
	void SimpleEvent<T>::add(EventMethod c){
		this->m = c;
	}
	template<class T>
	void SimpleEvent<T>::add(T name, EventMethod c){
		
	}

	template class SimpleEvent<String>;
	template class SimpleEvent<int>;
	template class SimpleEvent<float>;
	template class SimpleEvent<bool>;
#endif 
