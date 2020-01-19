

#ifndef Event_cpp
#define Event_cpp

#include "Event.h"

	template<class T>
	Event<T>::Event(){
		
	}
	template<class T>
	Event<T>::~Event(){
		
	}
	template<class T>
	void Event<T>::event(){
	}
	template<class T>
	void Event<T>::event(T c){
	}
	template<class T>
	void Event<T>::setName(T n){
		this->var = n;
	}
	template<class T>
	void Event<T>::add(EventMethod c){
	}
	template<class T>
	void Event<T>::add(T name, EventMethod c){
		
	}

	template class Event<String>;
	template class Event<int>;
	template class Event<float>;
	template class Event<bool>;
#endif 
