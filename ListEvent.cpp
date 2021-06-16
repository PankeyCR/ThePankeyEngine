

#ifndef ListEvent_cpp
#define ListEvent_cpp

#include "ListEvent.h"

	template<class T>
	ListEvent<T>::ListEvent(){
		this->list = new ArrayList<EventMethod,10>();
	}
	template<class T>
	ListEvent<T>::~ListEvent(){
		delete this->list;
	}
	template<class T>
	void ListEvent<T>::event(){
		for(int x = 0; x < this->list->getPosition(); x++){
			(**this->list->getByPosition(x))(this->var);
		}
	}
	template<class T>
	void ListEvent<T>::event(T c){
		if(this->var != c){
			this->var = c;
			for(int x = 0; x < this->list->getPosition(); x++){
				(**this->list->getByPosition(x))(this->var);
			}
		}
	}
	template<class T>
	void ListEvent<T>::add(EventMethod c){
		this->list->addLValue(c);
	}
	template<class T>
	void ListEvent<T>::add(T name, EventMethod c){
		
	}

	template class ListEvent<String>;
	template class ListEvent<int>;
	template class ListEvent<float>;
#endif 
