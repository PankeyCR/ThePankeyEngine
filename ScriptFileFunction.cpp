
#ifndef ScriptFileFunction_cpp
#define ScriptFileFunction_cpp

#include "ScriptFileFunction.h"

	
	ScriptFileFunction::ScriptFileFunction(){
		
	}
	
	ScriptFileFunction::~ScriptFileFunction(){
		// if(this->fileFunctions != nullptr){
			// delete this->fileFunctions;
		// }
	}
	
	bool ScriptFileFunction::SaveFileFunction(MonkeyFile* file,cppObject* instance,String path,String key){
		
		
		return false;
	}
	
	cppObject* ScriptFileFunction::LoadFileFunction(MonkeyFile* file,cppObject* attachable,String path,String key){
		
		
		return nullptr;
	}
	
	bool ScriptFileFunction::DeleteFileFunction(MonkeyFile* file,cppObject* attachable,String path,String key){
		
		
		return false;
	}
#endif 