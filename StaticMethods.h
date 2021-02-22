

#ifndef StaticMethods_h
#define StaticMethods_h

#include "PrimitiveMap.h"

template<class A,class... P>
class StaticMethods : public PrimitiveMap<A,void (*)(P...)>{
public:
using StaticEventMethod = void (*)(P...);
StaticMethods(){}
virtual ~StaticMethods(){}

void invoke(A a, P... p){
	if(this->getByLValue(a) == nullptr){
		return;
	}
	(**this->getByLValue(a))(p...);
}

void invoke(P... p){
	for(int x = 0; x < this->pos; x++){
		(**this->getByPosition(x))(p...);
	}
}

virtual bool operator==(StaticMethods<A,P...> a){
	
	return true;
}
virtual bool operator!=(StaticMethods<A,P...> a){
	
	return false;
}
virtual void operator=(StaticMethods<A,P...> a){
	this->resetDelete();
	for(int x=0; x < a.getPosition(); x++){
		this->addPointers(a.getKeyByPosition(x),a.getByPosition(x));
	}
}

protected:
};

#endif 
