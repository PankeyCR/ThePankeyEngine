
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MethodMap)
	#define MethodMap_hpp
#endif

#ifndef MethodMap_hpp
#define MethodMap_hpp
#define MethodMap_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "PrimitiveRawMap.hpp"

namespace ame{

template<class T,class... P>
class MethodMap : public PrimitiveRawMap<Note,void (T::*)(P...)>{
public:
using EventMethod = void (T::*)(P...);
MethodMap(){}
virtual ~MethodMap(){}

void add(Note n, EventMethod m){
	this->addLValues(n,m);
}

void invoke(Note a, T* intance, P... p){
	if(this->getByLValue(a) == nullptr){
		return;
	}
	( intance->**this->getByLValue(a))(p...);
}

void invoke(T* intance, EventMethod* a, P... p){
	( intance->**a)(p...);
}

void invoke(T* intance, EventMethod a, P... p){
	( intance->*a)(p...);
}
virtual bool operator==(MethodMap<T,P...> a){
	
	return false;
}
virtual bool operator!=(MethodMap<T,P...> a){
	
	return false;
}
virtual void operator=(MethodMap<T,P...> a){
	this->resetDelete();
	for(int x=0; x < a.getPosition(); x++){
		this->addPointers(a.getKeyByPosition(x),a.getByPosition(x));
	}
}

protected:
};

}

#endif