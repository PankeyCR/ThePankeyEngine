
#ifndef Script_hpp
#define Script_hpp

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
