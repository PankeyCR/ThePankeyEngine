

#ifndef ProcessEntry_cpp
#define ProcessEntry_cpp

#include "ProcessEntry.h"

	template<class P, class V>
	ProcessEntry<P,V>::ProcessEntry(P key, Processing<V>* value){
        this->key = key;
        this->value = value;
	}
	
	template<class P, class V>
	ProcessEntry<P,V>::~ProcessEntry(){
		
	}
		
	template<class P, class V>
	P ProcessEntry<P,V>::getKey(){
        return this->key;
	}
	
	template<class P, class V>
	Processing<V>* ProcessEntry<P,V>::getValue(){
        return this->value;
	}
		
		
		
#endif 
