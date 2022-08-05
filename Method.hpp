
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Method)
	#define Method_hpp
#endif

#ifndef Method_hpp
#define Method_hpp
#define Method_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Note.hpp"
#include "RawList.hpp"
#include "MethodMap.hpp"
#include "Parameter.hpp"
#include "Annotation.hpp"
#include "cppObject.hpp"
#include "MethodType.hpp"
#include "MethodInvoker.hpp"
#include "MethodReturnInvoker.hpp"
#include "ClassMethodInvoker.hpp"
#include "ClassMethodReturnInvoker.hpp"
#include "TypeErasedInvoke.hpp"
#include "DefaultMethodReturn.hpp"

#ifdef Method_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define MethodLog(location,method,type,mns) ame_Log(this,location,"Method",method,type,mns)
	#define MethodMethodLog(location,method,type,mns) ame_Log(nullptr,location,"RawMethod",method,type,mns)
	#define const_MethodLog(location,method,type,mns) 
	#define StaticMethodLog(pointer,location,method,type,mns) ame_Log(pointer,location,"Method",method,type,mns)
#else
	#ifdef Method_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define MethodLog(location,method,type,mns) ame_LogDebug(this,location,"Method",method,type)
		#define MethodMethodLog(location,method,type,mns) ame_LogDebug(nullptr,location,"RawMethod",method,type)
		#define const_MethodLog(location,method,type,mns) 
		#define StaticMethodLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"Method",method,type)
	#else
		#define MethodLog(location,method,type,mns) 
		#define MethodMethodLog(location,method,type,mns) 
		#define const_MethodLog(location,method,type,mns) 
		#define StaticMethodLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{

class cppObjectClass;

class Method{
public:
	Method(){
		MethodLog(ame_Log_Statement, "Contructor",  "println", "");
	}
	Method(const Method& a_method){
		MethodLog(ame_Log_Statement, "Contructor",  "println", "");
		methodClass = a_method.methodClass;
		m_type = a_method.m_type;
		m_name = a_method.m_name;
	}
	Method(cppObjectClass* cls, Note n, MethodType i_type){
		MethodLog(ame_Log_Statement, "Contructor",  "println", "");
		methodClass = cls;
		m_type = i_type;
		m_name = n;
		MethodLog(ame_Log_Statement, "Contructor",  "println", "");
	}
	virtual ~Method(){
		MethodLog(ame_Log_Statement, "Destructor",  "println", "");
	}
	
	void setName(Note n){
		m_name = n;
	}
	Note getName(){
		return m_name;
	}
	
	template<class T = cppObject, class R = bool, class... Args>
	R invoke(T* t, Args... a){
		MethodLog(ame_Log_Statement, "invoke",  "println", "");
		MethodLog(ame_Log_Statement, "invoke",  "println", Note("Method Type: ") + getType(m_type));
		R r_r = DefaultMethodReturn<T,R>::getReturn();
		if(m_type == MethodType::MethodInvokerType){
			MethodLog(ame_Log_Statement, "invoke",  "println", "MethodInvokerType");
			return MethodReturnInvoker<R,Args...>::invoke(methodClass,m_name, r_r, a...);
		}
		if(m_type == MethodType::MethodPointerInvokerType){
			MethodLog(ame_Log_Statement, "invoke",  "println", "MethodPointerInvokerType");
			return MethodReturnInvoker<R,T*,Args...>::invoke(methodClass,m_name, r_r, t, a...);
		}
		if(m_type == MethodType::ClassMethodInvokerType){
			MethodLog(ame_Log_Statement, "invoke",  "println", "ClassMethodInvokerType");
			return ClassMethodReturnInvoker<T,R,Args...>::invoke(methodClass,m_name, t, r_r, a...);
		}
		if(m_type == MethodType::PolicyBaseMethodInvokerType){
			MethodLog(ame_Log_Statement, "invoke",  "println", "PolicyBaseMethodInvokerType");
			// PolicyBaseMethodInvoker<Args...>::invoke(methodClass,m_name, a...);
			// PrimitiveRawList<void(*)(cppObjectClass*,Note,cppObject*,Args...)>* policyBase = PolicyBaseMethodInvoker<Args..>::getPolicyBaseMethods();
			// policyBase(m_name, a...);
		}
		return r_r;
	}
	
	virtual MethodType getMethodType(){
		return m_type;
	}
	
	virtual Note getType(){
		return getType(m_type);
	}
	
	virtual Note getType(MethodType a_type){
		MethodLog(ame_Log_Statement, "getType",  "println", "");
		if(a_type == MethodType::MethodInvokerType){
			MethodLog(ame_Log_Statement, "getType",  "println", "MethodInvokerType");
			return "MethodInvokerType";
		}
		if(a_type == MethodType::MethodPointerInvokerType){
			MethodLog(ame_Log_Statement, "getType",  "println", "MethodPointerInvokerType");
			return "MethodPointerInvokerType";
		}
		if(a_type == MethodType::ClassMethodInvokerType){
			MethodLog(ame_Log_Statement, "getType",  "println", "ClassMethodInvokerType");
			return "ClassMethodInvokerType";
		}
		if(a_type == MethodType::PolicyBaseMethodInvokerType){
			return "PolicyBaseMethodInvokerType";
		}
		return "";
	}
	
	virtual cppObjectClass* getOwnerClass(){return methodClass;}
	
	virtual Method operator=(const Method& a_method){
		methodClass = a_method.methodClass;
		m_type = a_method.m_type;
		m_name = a_method.m_name;
		return *this;
	}
	virtual bool operator==(const Method& a_method){
		return 	methodClass == a_method.methodClass &&
				m_type == a_method.m_type &&
				m_name == a_method.m_name;
	}
	virtual bool operator!=(const Method& a_method){
		return 	methodClass != a_method.methodClass &&
				m_type != a_method.m_type &&
				m_name != a_method.m_name;
	}

	virtual RawList<Parameter>* getParameters(){return nullptr;}

	virtual cppObjectClass* getClass(){return nullptr;}
		
protected:
	Note m_name;
	cppObjectClass* methodClass = nullptr;
	MethodType m_type = MethodType::MethodInvokerType;
};

}

#endif