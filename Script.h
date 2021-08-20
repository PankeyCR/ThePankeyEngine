
#ifndef Script_h
#define Script_h

#include "Statement.h"

namespace ame{

class Script{
    public:
		Script(const String& name, List<Statement>* s);
		Script(const char* name, List<Statement>* s);
		virtual ~Script();
		
		String name();
		void run();
		
		void operator=(const Script& script);
		bool operator==(const Script& script);
		bool operator!=(const Script& script);
	protected:
		List<Statement>* statements = nullptr;
		String m_name;
};

}

#endif 
