
#ifndef Script_cpp
#define Script_cpp

#include "Script.h"

	
	Script::Script(const String& name, List<Statement>* s){
	}
	
	Script::Script(const char* name, List<Statement>* s){
	}
	
	Script::~Script(){
	}
	
	void Script::run(){
		
	}
	
	String Script::name(){
		return m_name;
	}
	void Script::operator=(const Script& script){}
	bool Script::operator==(const Script& script){return false;}
	bool Script::operator!=(const Script& script){return false;}
	
	
#endif 