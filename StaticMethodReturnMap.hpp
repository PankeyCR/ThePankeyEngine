
#include "ame_Enviroment.hpp"

#if defined(DISABLE_StaticMethodReturnMap)
	#define StaticMethodReturnMap_hpp
#endif

#ifndef StaticMethodReturnMap_hpp
#define StaticMethodReturnMap_hpp
#define StaticMethodReturnMap_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Note.hpp"
#include "PrimitiveRawMap.hpp"

namespace ame{

template<class A, class R, class... P>
class StaticMethodReturnMap : public PrimitiveRawMap<A,R (*)(P...)>{
public:
using StaticEventMethod = R (*)(P...);
StaticMethodReturnMap(){}
virtual ~StaticMethodReturnMap(){}

void add(Note n, StaticEventMethod m){
	this->addLValues(n,m);
}

R invoke(A a, R a_r, P... p){
	if(this->getByLValue(a) == nullptr){
		return a_r;
	}
	return (**this->getByLValue(a))(p...);
}

void invokeAll(P... p){
	for(int x = 0; x < this->pos; x++){
		(**this->getByPosition(x))(p...);
	}
}

R invokeByPosition(int x, R a_r, P... p){
	if(x >= this->getPosition()){
		return a_r;
	}
	return (**this->getByPosition(x))(p...);
}

virtual bool operator==(StaticMethodReturnMap<A,R,P...> a){

	return true;
}
virtual bool operator!=(StaticMethodReturnMap<A,R,P...> a){

	return false;
}
virtual void operator=(StaticMethodReturnMap<A,R,P...> a){
	this->resetDelete();
	for(int x=0; x < a.getPosition(); x++){
		this->addPointers(a.getKeyByPosition(x),a.getByPosition(x));
	}
}

protected:
};

}

#endif