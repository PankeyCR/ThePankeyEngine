
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MethodReturnMap)
	#define MethodReturnMap_hpp
#endif

#ifndef MethodReturnMap_hpp
#define MethodReturnMap_hpp
#define MethodReturnMap_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "PrimitiveRawMap.hpp"

namespace ame{

template<class T,class R,class... P>
class MethodReturnMap : public PrimitiveRawMap<Note,R (T::*)(P...)>{
public:
R r;
using EventMethod = R (T::*)(P...);
MethodReturnMap(){}
MethodReturnMap(R rtn){r=rtn;}
virtual ~MethodReturnMap(){}

void add(Note n, EventMethod m){
	this->addLValues(n,m);
}

R invoke(Note a, T* intance, R rr, P... p){
	if(this->getByLValue(a) == nullptr){
		return rr;
	}
	return ( intance->**this->getByLValue(a))(p...);
}

// R invoke(T* intance, EventMethod* a, P... p){
	// return ( intance->**a)(p...);
// }

// R invoke(T* intance, EventMethod a, P... p){
	// return ( intance->*a)(p...);
// }
virtual void operator=(R rtn){r=rtn;}
virtual bool operator==(MethodReturnMap<T,R,P...> a){
	
	return false;
}
virtual bool operator!=(MethodReturnMap<T,R,P...> a){
	
	return false;
}
virtual void operator=(MethodReturnMap<T,R,P...> a){
	this->resetDelete();
	for(int x=0; x < a.getPosition(); x++){
		this->addPointers(a.getKeyByPosition(x),a.getByPosition(x));
	}
}

protected:
};

}

#endif