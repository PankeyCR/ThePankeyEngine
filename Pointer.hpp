
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Pointer)
	#define Pointer_hpp
#endif

#ifndef Pointer_hpp
#define Pointer_hpp
#define Pointer_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

template<class P>
class Pointer{
	public:
		Pointer(P* p){
			pointer = p;
		}
		Pointer(const Pointer &p){
			pointer = p.pointer;
		}
		virtual ~Pointer(){
			delete pointer;
		}
		virtual P* operator ->(){
			return pointer;
		}
	protected:
		P* pointer;
};

}

#endif