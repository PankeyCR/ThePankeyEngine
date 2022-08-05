
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ArduinoMessageCommand)
	#define ArduinoMessageCommand_hpp
#endif

#ifndef ArduinoMessageCommand_hpp
#define ArduinoMessageCommand_hpp
#define ArduinoMessageCommand_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Annotation.hpp"

namespace ame{

class ArduinoMessageCommand : public Annotation{
    public:
		ArduinoMessageCommand(Note n, Note t, int p){
			m_name = n;
			m_type = t;
			m_par = p;
			ClassName<ArduinoMessageCommand>::className = "ArduinoMessageCommand";
		}
		virtual ~ArduinoMessageCommand(){}
		
		virtual Note name(){return m_name;}
		virtual Note type(){return m_type;}
		virtual int parameters(){return m_par;}
		virtual cppObjectClass* getClass(){return Class<ArduinoMessageCommand>::classType;}
		
	private:
		Note m_name;
		Note m_type;
		int m_par;
};

}

#endif
