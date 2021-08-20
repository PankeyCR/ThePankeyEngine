
#ifndef Script_cpp
#define Script_cpp

#include "Script.h"

	
	ame::Script::Script(const String& name, ame::List<Statement>* s){
	}
	
	ame::Script::Script(const char* name, ame::List<Statement>* s){
	}
	
	ame::Script::~Script(){
	}
	
	void ame::Script::run(){
		
	}
	
	String ame::Script::name(){
		return m_name;
	}
	void ame::Script::operator=(const ame::Script& sct){}
	bool ame::Script::operator==(const ame::Script& sct){return false;}
	bool ame::Script::operator!=(const ame::Script& sct){return false;}
	
	
#endif 