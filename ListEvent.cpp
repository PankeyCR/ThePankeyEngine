

#ifndef ListEvent_cpp
#define ListEvent_cpp

#include "ListEvent.h"

	template<class T>
	ame::ListEvent<T>::ListEvent(){
		this->list = new ArrayList<EventMethod,10>();
	}
	template<class T>
	ame::ListEvent<T>::~ListEvent(){
		delete this->list;
	}
	template<class T>
	void ame::ListEvent<T>::event(){
		for(int x = 0; x < this->list->getPosition(); x++){
			(**this->list->getByPosition(x))(this->var);
		}
	}
	template<class T>
	void ame::ListEvent<T>::event(T c){
		if(this->var != c){
			this->var = c;
			for(int x = 0; x < this->list->getPosition(); x++){
				(**this->list->getByPosition(x))(this->var);
			}
		}
	}
	template<class T>
	void ame::ListEvent<T>::add(EventMethod c){
		this->list->addLValue(c);
	}
	template<class T>
	void ame::ListEvent<T>::add(T name, EventMethod c){
		
	}

	template class ame::ListEvent<String>;
	template class ame::ListEvent<int>;
	template class ame::ListEvent<float>;
#endif 
