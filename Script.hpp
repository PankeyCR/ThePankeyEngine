
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Script)
	#define Script_hpp
#endif

#ifndef Script_hpp
#define Script_hpp
#define Script_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Statement.hpp"

namespace ame{

class Script{
    public:
		Script(const String& name, List<Statement>* s){}
		Script(const char* name, List<Statement>* s){}
		virtual ~Script(){}
		
		String name(){return m_name;}
		void run(){}
		
		void operator=(const Script& script){}
		bool operator==(const Script& script){return false;}
		bool operator!=(const Script& script){return false;}
	protected:
		List<Statement>* statements = nullptr;
		String m_name;
};

}

#endif