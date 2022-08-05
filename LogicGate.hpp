
#include "ame_Enviroment.hpp"

#if defined(DISABLE_LogicGate)
	#define LogicGate_hpp
#endif

#ifndef LogicGate_hpp
#define LogicGate_hpp
#define LogicGate_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Note.hpp"
#include "cppObject.hpp"
#include "Class.hpp"

namespace ame{

class LogicGate : public cppObject{
    public:
		LogicGate(){}
		virtual ~LogicGate(){}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<LogicGate>::classType || cls == Class<cppObject>::classType;
		}
		virtual void operator=(const LogicGate& a_bool){
			m_name = a_bool.m_name;
		}
		virtual bool operator==(const LogicGate& a_bool){
			return this->m_name == a_bool.m_name;
		}
		virtual bool operator!=(const LogicGate& a_bool){
			return this->m_name != a_bool.m_name;
		}
	protected:
		PrimitiveList<LogicGate> m_gates;
};

}

#endif
