

#ifndef SimpleEvent_cpp
#define SimpleEvent_cpp

#include "SimpleEvent.h"

	template<class T>
	ame::SimpleEvent<T>::SimpleEvent(){
		
	}
	template<class T>
	ame::SimpleEvent<T>::~SimpleEvent(){
		
	}
	template<class T>
	void ame::SimpleEvent<T>::event(){
		this->m(this->var);
	}
	template<class T>
	void ame::SimpleEvent<T>::event(T c){
		if(this->var != c){
			this->var = c;
			this->m(this->var);
		}
	}
	template<class T>
	void ame::SimpleEvent<T>::add(EventMethod c){
		this->m = c;
	}
	template<class T>
	void ame::SimpleEvent<T>::add(T name, EventMethod c){
		
	}

	template class ame::SimpleEvent<String>;
	template class ame::SimpleEvent<int>;
	template class ame::SimpleEvent<float>;
	template class ame::SimpleEvent<bool>;
#endif 
