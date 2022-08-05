
#include "ame_Enviroment.hpp"

#if defined(DISABLE_StaticMethodMap)
	#define StaticMethodMap_hpp
#endif

#ifndef StaticMethodMap_hpp
#define StaticMethodMap_hpp
#define StaticMethodMap_AVAILABLE

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

template<class A,class... P>
class StaticMethodMap : public PrimitiveRawMap<A,void (*)(P...)>{
public:
using StaticEventMethod = void (*)(P...);
StaticMethodMap(){}
virtual ~StaticMethodMap(){}

void add(Note n, StaticEventMethod m){
	this->addLValues(n,m);
}

void invoke(StaticEventMethod* a_method, P... p){
	if(a_method == nullptr){
		return;
	}
	(**a_method)(p...);
}

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

virtual bool operator==(StaticMethodMap<A,P...> a){

	return true;
}
virtual bool operator!=(StaticMethodMap<A,P...> a){

	return false;
}
virtual void operator=(StaticMethodMap<A,P...> a){
	this->resetDelete();
	for(int x=0; x < a.getPosition(); x++){
		this->addPointers(a.getKeyByPosition(x),a.getByPosition(x));
	}
}

protected:
};

}

#endif