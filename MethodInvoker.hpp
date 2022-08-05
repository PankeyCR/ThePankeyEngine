
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MethodInvoker)
	#define MethodInvoker_hpp
#endif

#ifndef MethodInvoker_hpp
#define MethodInvoker_hpp
#define MethodInvoker_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "StaticMethodMap.hpp"
#include "PrimitiveRawMap.hpp"

namespace ame{

template<class... Args>
struct MethodInvoker{
	using Raw_Method = void(*)(Args...);
	static PrimitiveRawMap<cppObjectClass,StaticMethodMap<Note,Args...>>* methodMap;
	
	static void add(cppObjectClass* cls, Note n, Raw_Method i_method){
		if(methodMap == nullptr){
			return;
		}
		StaticMethodMap<Note,Args...>* methods = methodMap->getByPointer(cls);
		if(methods == nullptr){
			methods = new StaticMethodMap<Note,Args...>();
			methodMap->addPointers(cls,methods);
		}
		methods->addLValues(n, i_method);
	}
	
	static void invoke(cppObjectClass* cls, Note n, Args... a){
		if(methodMap == nullptr){
			return;
		}
		StaticMethodMap<Note,Args...>* methods = methodMap->getByPointer(cls);
		if(methods == nullptr){
			return;
		}
		methods->invoke(n,a...);
	}
};

template<class... Args>
PrimitiveRawMap<cppObjectClass,StaticMethodMap<Note,Args...>>* MethodInvoker<Args...>::methodMap = 
	new PrimitiveRawMap<cppObjectClass,StaticMethodMap<Note,Args...>>();

}

#endif