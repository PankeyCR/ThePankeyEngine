
#ifndef MethodMap_hpp
#define MethodMap_hpp

#include "PrimitiveRawMap.hpp"

namespace ame{

template<class T,class R,class... P>
class MethodMap : public PrimitiveRawMap<String,R (T::*)(P...)>{
public:
R r;
using EventMethod = R (T::*)(P...);
MethodMap(){}
MethodMap(R rtn){r=rtn;}
virtual ~MethodMap(){}

void add(String n, EventMethod m){
	this->addLValues(n,m);
}

R invoke(String a, T* intance, P... p){
	if(this->getByLValue(a) == nullptr){
		return r;
	}
	return ( intance->**this->getByLValue(a))(p...);
}

R invoke(String a, T* intance, R rr, P... p){
	if(this->getByLValue(a) == nullptr){
		return rr;
	}
	return ( intance->**this->getByLValue(a))(p...);
}

R invoke(T* intance, EventMethod* a, P... p){
	return ( intance->**a)(p...);
}

R invoke(T* intance, EventMethod a, P... p){
	return ( intance->*a)(p...);
}
virtual void operator=(R rtn){r=rtn;}
virtual bool operator==(MethodMap<T,R,P...> a){
	
	return false;
}
virtual bool operator!=(MethodMap<T,R,P...> a){
	
	return false;
}
virtual void operator=(MethodMap<T,R,P...> a){
	this->resetDelete();
	for(int x=0; x < a.getPosition(); x++){
		this->addPointers(a.getKeyByPosition(x),a.getByPosition(x));
	}
}

protected:
};

}

#endif 
