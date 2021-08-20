

#ifndef AnnotationMap_h
#define AnnotationMap_h

#include "PrimitiveMap.h"

namespace ame{

template<class A,class R,class T,class... P>
class AnnotationMap : public PrimitiveMap<A,R (T::*)(P...)>{
public:
using EventMethod = R (T::*)(P...);
AnnotationMap(){}
AnnotationMap(R rtn){r=rtn;}
virtual ~AnnotationMap(){}

R invoke(T* intance, A a, P... p){
	if(this->getByLValue(a) == nullptr){
		return r;
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
virtual bool operator==(AnnotationMap<A,R,T,P...> a){
	
	return false;
}
virtual bool operator!=(AnnotationMap<A,R,T,P...> a){
	
	return false;
}
virtual void operator=(AnnotationMap<A,R,T,P...> a){
	this->resetDelete();
	for(int x=0; x < a.getPosition(); x++){
		this->addPointers(a.getKeyByPosition(x),a.getByPosition(x));
	}
}

protected:
	R r;
};

}

#endif 
