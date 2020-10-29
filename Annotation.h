

#ifndef Annotation_h
#define Annotation_h

#include "PrimitiveMap.h"

template<class A,class R,class T,class... P>
class Annotation : public PrimitiveMap<A,R (T::*)(P...)>{
public:
Annotation(){}
Annotation(R rtn){r=rtn;}
~Annotation(){}

R invoke(T* intance, A a,P... p){
	if(this->get(a) == nullptr){
		return r;
	}
	return ( intance->**this->get(a))(p...);
}
virtual void operator=(R rtn){r=rtn;}
virtual bool operator==(Annotation<A,R,T,P...> a){
	
	return false;
}
virtual bool operator!=(Annotation<A,R,T,P...> a){
	
	return false;
}
virtual void operator=(Annotation<A,R,T,P...> a){
	this->resetDelete();
	for(int x=0; x < a.getPos(); x++){
		this->add(a.getKeyByPos(x),a.getByPos(x));
	}
}

protected:
	R r;
};

#endif 
