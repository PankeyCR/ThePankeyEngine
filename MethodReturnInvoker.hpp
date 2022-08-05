
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MethodReturnInvoker)
	#define MethodReturnInvoker_hpp
#endif

#ifndef MethodReturnInvoker_hpp
#define MethodReturnInvoker_hpp
#define MethodReturnInvoker_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "StaticMethodReturnMap.hpp"
#include "PrimitiveRawMap.hpp"

#ifdef MethodReturnInvoker_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define MethodReturnInvokerLog(location,method,type,mns) ame_Log(this,location,"MethodReturnInvoker",method,type,mns)
	#define MethodReturnInvokerMethodLog(location,method,type,mns) ame_Log(nullptr,location,"MethodReturnInvoker",method,type,mns)
	#define const_MethodReturnInvokerLog(location,method,type,mns) 
	#define StaticMethodReturnInvokerLog(pointer,location,method,type,mns) ame_Log(pointer,location,"MethodReturnInvoker",method,type,mns)
#else
	#ifdef MethodReturnInvoker_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define MethodReturnInvokerLog(location,method,type,mns) ame_LogDebug(this,location,"MethodReturnInvoker",method,type)
		#define MethodReturnInvokerMethodLog(location,method,type,mns) ame_LogDebug(nullptr,location,"MethodReturnInvoker",method,type)
		#define const_MethodReturnInvokerLog(location,method,type,mns) 
		#define StaticMethodReturnInvokerLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"MethodReturnInvoker",method,type)
	#else
		#define MethodReturnInvokerLog(location,method,type,mns) 
		#define MethodReturnInvokerMethodLog(location,method,type,mns) 
		#define const_MethodReturnInvokerLog(location,method,type,mns) 
		#define StaticMethodReturnInvokerLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{

template<class R, class... Args>
struct MethodReturnInvoker{
	using Raw_Method = R(*)(Args...);
	static PrimitiveRawMap<cppObjectClass,StaticMethodReturnMap<Note,R,Args...>>* methodMap;
	
	static void add(cppObjectClass* cls, Note n, Raw_Method i_method){
		if(methodMap == nullptr){
			return;
		}
		StaticMethodReturnMap<Note,R,Args...>* methods = methodMap->getByPointer(cls);
		if(methods == nullptr){
			methods = new StaticMethodReturnMap<Note,R,Args...>();
			methodMap->addPointers(cls,methods);
		}
		methods->addLValues(n, i_method);
	}
	
	static R invoke(cppObjectClass* cls, Note n, R a_r, Args... a){
		MethodReturnInvokerMethodLog(ame_Log_Statement, "invoke",  "println", "");
		if(methodMap == nullptr){
			MethodReturnInvokerMethodLog(ame_Log_Statement, "invoke",  "println", "methodMap == nullptr");
			return a_r;
		}
		StaticMethodReturnMap<Note,R,Args...>* methods = methodMap->getByPointer(cls);
		if(methods == nullptr){
			MethodReturnInvokerMethodLog(ame_Log_Statement, "invoke",  "println", "methods == nullptr");
			return a_r;
		}
		return methods->invoke(n,a_r,a...);
	}
};

template<class R, class... Args>
PrimitiveRawMap<cppObjectClass,StaticMethodReturnMap<Note,R,Args...>>* MethodReturnInvoker<R,Args...>::methodMap = 
	new PrimitiveRawMap<cppObjectClass,StaticMethodReturnMap<Note,R,Args...>>();

}

#endif