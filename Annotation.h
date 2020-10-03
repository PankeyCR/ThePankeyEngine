

#ifndef Annotation_h
#define Annotation_h

#include "PrimitiveMap.h"

template<class A,class R,class T,class... P>
class Annotation : public PrimitiveMap<A,R (T::*)(P...)>{
public:
Annotation(){}
~Annotation(){}

R invoke(T* intance, A a,P... p){
	if(this->get(a) == nullptr){
		return nullptr;
	}
	return ( intance->**this->get(a))(p...);;
}

protected:
};

#endif 
