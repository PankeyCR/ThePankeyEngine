
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Class)
	#define Class_hpp
#endif

#ifndef Class_hpp
#define Class_hpp
#define Class_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "ClassCount.hpp"
#include "ClassName.hpp"
#include "cppObjectClass.hpp"
#include "TemplateClass.hpp"
#include "Note.hpp"

namespace ame{

template<class cls>
struct Class{
	static cppObjectClass* classType;
	
	static cppObjectClass* getClass(){return classType;}
	
	static long getType(){
		return ClassCount<cls>::get();
	}
	
	static Note getName(){
		return ClassName<cls>::get();
	}
};
	
#if defined(ClassType_AVAILABLE)

template<class cls> cppObjectClass* Class<cls>::classType = new ClassType<cls>();

#else

template<class cls> cppObjectClass* Class<cls>::classType = new cppObjectClass();

#endif

}

#endif