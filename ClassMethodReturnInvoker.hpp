
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ClassMethodReturnInvoker)
	#define ClassMethodReturnInvoker_hpp
#endif

#ifndef ClassMethodReturnInvoker_hpp
#define ClassMethodReturnInvoker_hpp
#define ClassMethodReturnInvoker_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "MethodReturnMap.hpp"
#include "PrimitiveRawMap.hpp"

namespace ame{

template<class T, class R, class... Args>
struct ClassMethodReturnInvoker{
	using Class_Method = R(T::*)(Args...);
	static PrimitiveRawMap<cppObjectClass,MethodReturnMap<T,R,Args...>>* methodMap;
	
	static void add(cppObjectClass* cls, Note n, Class_Method i_method){
		if(methodMap == nullptr){
			return;
		}
		MethodReturnMap<T,R,Args...>* methods = methodMap->getByPointer(cls);
		if(methods == nullptr){
			methods = new MethodReturnMap<T,R,Args...>();
			methodMap->addPointers(cls,methods);
		}
		methods->addLValues(n, i_method);
	}
	
	static R invoke(cppObjectClass* cls, Note n, T* a_t, R a_r, Args... a){
		if(methodMap == nullptr){
			return a_r;
		}
		MethodReturnMap<T,R,Args...>* methods = methodMap->getByPointer(cls);
		if(methods == nullptr){
			return a_r;
		}
		return methods->invoke(n,a_t,a_r,a...);
	}
};

template<class T, class R, class... Args>
PrimitiveRawMap<cppObjectClass,MethodReturnMap<T,R,Args...>>* ClassMethodReturnInvoker<T,R,Args...>::methodMap = 
	new PrimitiveRawMap<cppObjectClass,MethodReturnMap<T,R,Args...>>();

}

#endif