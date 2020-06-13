

/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#ifndef ScriptFileFunction_h
#define ScriptFileFunction_h

#include "Arduino.h"
#include "cppObject.h"
#include "MonkeyFile.h"

class ScriptFileFunction : public MonkeyFileFunction{
    public:
		ScriptFileFunction();
		virtual ~ScriptFileFunction();
		
    	virtual bool SaveFileFunction(MonkeyFile* file,cppObject* instance,String path,String key);
    	virtual cppObject* LoadFileFunction(MonkeyFile* file,cppObject* attachable,String path,String key);
    	virtual bool DeleteFileFunction(MonkeyFile* file,cppObject* attachable,String path,String key);
		
	protected:
	
	
};

#endif 
