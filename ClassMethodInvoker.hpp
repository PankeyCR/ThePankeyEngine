
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ClassMethodInvoker)
	#define ClassMethodInvoker_hpp
#endif

#ifndef ClassMethodInvoker_hpp
#define ClassMethodInvoker_hpp
#define ClassMethodInvoker_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "MethodMap.hpp"
#include "PrimitiveRawMap.hpp"

namespace ame{

template<class... Args>
struct ClassMethodInvoker{
	using Raw_Method = void(*)(Args...);
	static PrimitiveRawMap<cppObjectClass,MethodMap<Note,Args...>>* methodMap;
	
	static void add(cppObjectClass* cls, Note n, Raw_Method i_method){
		if(methodMap == nullptr){
			return;
		}
		MethodMap<Note,Args...>* methods = methodMap->getByPointer(cls);
		if(methods == nullptr){
			methods = new MethodMap<Note,Args...>();
			methodMap->addPointers(cls,methods);
		}
		methods->addLValues(n, i_method);
	}
	
	static void invoke(cppObjectClass* cls, Note n, Args... a){
		if(methodMap == nullptr){
			return;
		}
		MethodMap<Note,Args...>* methods = methodMap->getByPointer(cls);
		if(methods == nullptr){
			return;
		}
		methods->invoke(n,a...);
	}
};

template<class... Args>
PrimitiveRawMap<cppObjectClass,MethodMap<Note,Args...>>* ClassMethodInvoker<Args...>::methodMap = 
	new PrimitiveRawMap<cppObjectClass,MethodMap<Note,Args...>>();

}

#endif