

#ifndef ProcessEntry_cpp
#define ProcessEntry_cpp

#include "ProcessEntry.h"

	template<class P, class V>
	ame::ProcessEntry<P,V>::ProcessEntry(P key, ame::Processing<V>* value){
        this->key = key;
        this->value = value;
	}
	
	template<class P, class V>
	ame::ProcessEntry<P,V>::~ProcessEntry(){
		
	}
		
	template<class P, class V>
	P ame::ProcessEntry<P,V>::getKey(){
        return this->key;
	}
	
	template<class P, class V>
	ame::Processing<V>* ame::ProcessEntry<P,V>::getValue(){
        return this->value;
	}
		
		
		
#endif 
