
#include "ame_Enviroment.hpp"

#if defined(DISABLE_PrivateClass)
	#define PrivateClass_hpp
#endif

#ifndef PrivateClass_hpp
#define PrivateClass_hpp
#define PrivateClass_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "ClassCount.hpp"
#include "cppObjectClass.hpp"
#include "cppObject.hpp"
#include "ClassName.hpp"
#include "Note.hpp"
#include "Number.hpp"

namespace ame{

template<class cls = cppObject>
struct PrivateClass{
	static cppObjectClass* classType;
	
	static cppObjectClass* getClass(){return classType;}
	
	static long getType(){
		return ClassCount<cls>::get();
	}
	
	static Note getName(){
		return ClassName<cls>::get();
	}
};

template<class cls> cppObjectClass* PrivateClass<cls>::classType = new cppObjectClass();

}

#endif