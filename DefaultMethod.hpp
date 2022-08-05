
#include "ame_Enviroment.hpp"

#if defined(DISABLE_DefaultMethod)
	#define DefaultMethod_hpp
#endif

#ifndef DefaultMethod_hpp
#define DefaultMethod_hpp
#define DefaultMethod_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Method.hpp"
#include "TemplateClass.hpp"
#include "Class.hpp"

namespace ame{

template<class T>
class DefaultMethod : public Method{
public:
	DefaultMethod(){
		MethodLog(ame_Log_Statement, "Contructor",  "println", "");
	}
	DefaultMethod(const DefaultMethod& a_method){
		MethodLog(ame_Log_Statement, "Contructor",  "println", "");
		methodClass = a_method.methodClass;
		m_type = a_method.m_type;
		m_name = a_method.m_name;
	}
	DefaultMethod(cppObjectClass* cls, Note n, MethodType i_type){
		MethodLog(ame_Log_Statement, "Contructor",  "println", "");
		methodClass = cls;
		m_type = i_type;
		m_name = n;
		MethodLog(ame_Log_Statement, "Contructor",  "println", "");
	}
	virtual ~DefaultMethod(){
		MethodLog(ame_Log_Statement, "Destructor",  "println", "");
	}

	virtual cppObjectClass* getClass(){return Class<DefaultMethod>::classType;}

	// virtual RawList<Parameter>* getParameters(){return MethodParameter<T>::parameters;}
		
protected:
};

}

#endif