
#ifndef ScriptFileFunction_cpp
#define ScriptFileFunction_cpp

#include "ScriptFileFunction.h"

	
	ame::ScriptFileFunction::ScriptFileFunction(){
		
	}
	
	ame::ScriptFileFunction::~ScriptFileFunction(){
		// if(this->fileFunctions != nullptr){
			// delete this->fileFunctions;
		// }
	}
	
	bool ame::ScriptFileFunction::SaveFileFunction(ame::MonkeyFile* file, ame::cppObject* instance,String path,String key){
		
		
		return false;
	}
	
	ame::cppObject* ame::ScriptFileFunction::LoadFileFunction(ame::MonkeyFile* file, ame::cppObject* attachable,String path,String key){
		
		
		return nullptr;
	}
	
	bool ame::ScriptFileFunction::DeleteFileFunction(ame::MonkeyFile* file, ame::cppObject* attachable,String path,String key){
		
		
		return false;
	}
#endif 