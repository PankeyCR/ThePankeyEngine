
#include "ame_Enviroment.hpp"

#if defined(DISABLE_cppObjectMacros)
	#define cppObjectMacros_hpp
#endif

#ifndef cppObjectMacros_hpp
#define cppObjectMacros_hpp
#define cppObjectMacros_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "cppObjectcppObjectMacros.hpp"

#define IMPLEMENTING_CPPOBJECT_POLYMORPHISM(TYPE_CLASS_IN){												\
	virtual bool instanceof(cppObjectClass* cls){														\
		return cls == Class<TYPE_CLASS_IN>::classType || cls == Class<cppObject>::classType;			\
	}																									\
	virtual cppObjectClass* getClass(){																	\
		return Class<TYPE_CLASS_IN>::classType;															\
	}																									\
}

#endif



