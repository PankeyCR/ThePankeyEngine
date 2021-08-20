
#ifndef ArduinoMessageCommand_h
#define ArduinoMessageCommand_h

#include "Annotation.h"

namespace ame{

class ArduinoMessageCommand : public Annotation{
    public:
		ArduinoMessageCommand(String n, String t, int p){
			m_name = n;
			m_type = t;
			m_par = p;
			ClassName<ArduinoMessageCommand>::className = "ArduinoMessageCommand";
		}
		virtual ~ArduinoMessageCommand(){}
		
		virtual String name(){return m_name;}
		virtual String type(){return m_type;}
		virtual int parameters(){return m_par;}
		virtual cppObjectClass* getClass(){return Class<ArduinoMessageCommand>::classType;}
		
	private:
		String m_name;
		String m_type;
		int m_par;
};

}

#endif 
