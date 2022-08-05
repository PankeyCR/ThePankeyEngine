
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Reflection)
	#define Reflection_hpp
#endif

#ifndef Reflection_hpp
#define Reflection_hpp
#define Reflection_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "ClassName.hpp"
#include "ClassMethodList.hpp"
#include "DefaultMethod.hpp"
#include "MethodReturnInvoker.hpp"
#include "ClassMethodReturnInvoker.hpp"
#include "TemplateClass.hpp"
#include "RawMap.hpp"
#include "PrimitiveRawMap.hpp"
#include "cppObject.hpp"
#include "Object.hpp"
#include "GenericClass.hpp"
// #include "ClassMethodParameters.hpp"

#ifdef Reflection_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define ReflectionLog(location,method,type,mns) ame_Log(nullptr,location,"Reflection",method,type,mns)
	#define ReflectionMethodLog(location,method,type,mns) ame_Log(nullptr,location,"RawMethod",method,type,mns)
	#define const_ReflectionLog(location,method,type,mns) 
	#define StaticReflectionLog(pointer,location,method,type,mns) ame_Log(pointer,location,"Reflection",method,type,mns)
#else
	#ifdef Reflection_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define ReflectionLog(location,method,type,mns) ame_LogDebug(nullptr,location,"Reflection",method,type)
		#define ReflectionMethodLog(location,method,type,mns) ame_LogDebug(nullptr,location,"RawMethod",method,type)
		#define const_ReflectionLog(location,method,type,mns) 
		#define StaticReflectionLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"Reflection",method,type)
	#else
		#define ReflectionLog(location,method,type,mns) 
		#define ReflectionMethodLog(location,method,type,mns) 
		#define const_ReflectionLog(location,method,type,mns) 
		#define StaticReflectionLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{
	
template<class R = bool, class... Args> 
using Raw_Method = R(*)(Args...);
	
template<class... Args> 
using Raw_NTMethod = void(*)(Args...);
	
template<class T, class R = bool, class... Args> 
using Raw_Class_Method = R(*)(T*,Args...);
	
template<class T, class... Args> 
using Raw_Class_NTMethod = void(*)(T*,Args...);
	
template<class T, class R = bool, class... Args> 
using Class_Method = R(T::*)(Args...);
	
template<class T, class R = bool, class... Args> 
using Class_NTMethod = void(T::*)(Args...);


struct Reflection{
	
	static RawMap<Note,cppObjectClass>* m_classes;
	
	static void addGenericClass(Note a_note){
		addClass(a_note, nullptr);
	}
	
	static void addClass(Note a_note, cppObjectClass* cls){
		ReflectionLog(ame_Log_Statement, "addClass",  "println", Note("Name: ") + a_note);
		if(cls == nullptr){
			cls = new GenericClass(a_note);
		}
		cls->setName(a_note);
		m_classes->addPointer(a_note, cls);
	}
	
	static cppObject* newInstance(Note a_note){
		cppObjectClass* cls = m_classes->getByLValue(a_note);
		if(cls == nullptr){
			return new Object();
		}
		
		return new Object();
	}
	
	static cppObject* invoke(Note a_note){
		
		return new Object();
	}
	
	template<class T, class R = bool, class... Args>
	static void addGenericClassMethod(Note a_cls_name, Note a_method_name, Class_Method<T,R,Args...> a_method){
		ReflectionLog(ame_Log_Statement, "addClassMethod",  "println", Note("Name ") + a_name);
		// cppObjectClass* cls = m_classes->getBylValue(a_cls_name);
		// if(cls == nullptr){
			// return;
		// }
		// RawList<Method>* list = cls->getMethods();
		// list->addPointer(new GenericMethod(Class<T>::classType, a_name, MethodType::MethodInvokerType));
		// ClassMethodReturnInvoker<T,R,Args...>::add(Class<T>::classType, a_name, a_method);
	}
	
	template<class T, class... Args>
	static void addClassRawMethod(Note a_cls_name, Note a_method_name, Class_Method<T,Args...> a_method){
		ReflectionLog(ame_Log_Statement, "addClassMethod",  "println", Note("Name ") + a_name);
		// ClassMethodParameters<T>::add(a_name, ClassMethodParametersSize<Args...>::get());
		ClassMethodList<T>::add(new DefaultMethod<T>(Class<T>::classType, a_method_name, MethodType::MethodInvokerType));
		ClassMethodReturnInvoker<T,R,Args...>::add(Class<T>::classType, a_method_name, a_method);
	}
	
	template<class T, class R = bool, class... Args>
	static void addClassMethod(Note a_cls_name, Note a_method_name, Class_Method<T,R,Args...> a_method){
		ReflectionLog(ame_Log_Statement, "addClassMethod",  "println", Note("Name ") + a_name);
		// ClassMethodParameters<T>::add(a_name, ClassMethodParametersSize<Args...>::get());
		ClassMethodList<T>::add(new DefaultMethod<T>(Class<T>::classType, a_method_name, MethodType::MethodInvokerType));
		ClassMethodReturnInvoker<T,R,Args...>::add(Class<T>::classType, a_method_name, a_method);
	}
	/*
	static void addMethod(Note a_name, Raw_Method a_method){
		ReflectionLog(ame_Log_Statement, "addMethod",  "println", Note("Name ") + a_name);
		// MethodParameter<T>::add<Args...>(a_name);
		ClassMethod<T>::add(new DefaultMethod<T>(Class<T>::classType, a_name, MethodType::MethodInvokerType));
		MethodReturnInvoker<R,Args...>::add(Class<T>::classType, a_name, a_method);
	}
	
	static void addMethod(Note a_name, Raw_Class_Method a_method){
		ReflectionLog(ame_Log_Statement, "addMethod",  "println", Note("Name ") + a_name);
		ClassMethod<T>::add(new DefaultMethod<T>(Class<T>::classType, a_name, MethodType::MethodPointerInvokerType));
		MethodReturnInvoker<R,T*,Args...>::add(Class<T>::classType, a_name, a_method);
	}
	
	static void addMethod(Note a_name, Class_Method a_method){
		ReflectionLog(ame_Log_Statement, "addMethod",  "println", Note("Name ") + a_name);
		ClassMethod<T>::add(new DefaultMethod<T>(Class<T>::classType, a_name, MethodType::ClassMethodInvokerType));
		ClassMethodReturnInvoker<T,R,Args...>::add(Class<T>::classType, a_name, a_method);
	}
	
	static void setDefaultReturn(R a_r){
		ReflectionLog(ame_Log_Statement, "setDefaultReturn",  "println", "");
		DefaultMethodReturn<T,R>::set(a_r);
	}
	
	static R getReturn(){
		ReflectionLog(ame_Log_Statement, "getReturn",  "println", "");
		return DefaultMethodReturn<T,R>::getReturn();
	}*/
};

	RawMap<Note,cppObjectClass>* Reflection::m_classes = new PrimitiveRawMap<Note,cppObjectClass>();

}

#define ReflectClass(T) 															\
  public:																			\
  virtual cppObjectClass* getClass(){return Class<T>::classType;}					\
  virtual bool instanceof(cppObjectClass* cls){return cls == Class<T>::classType || cls == Class<cppObject>::classType;}			\


#endif