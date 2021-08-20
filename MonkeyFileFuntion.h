

/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#ifndef MonkeyFileFuntion_h
#define MonkeyFileFuntion_h

#include "Arduino.h"
#include "cppObject.h"
#include "MonkeyFile.h"

namespace ame{

class MonkeyFileFunction{
    public:
		MonkeyFileFunction(){}
		virtual ~MonkeyFileFunction(){}
    	virtual bool SaveFileFunction(MonkeyFile* file, cppObject* instance,String path,String key){
			return false;
		}
    	virtual cppObject* LoadFileFunction(MonkeyFile* file, cppObject* attachable,String path,String key){
			return nullptr;
		}
    	virtual bool DeleteFileFunction(MonkeyFile* file, cppObject* attachable,String path,String key){
			return false;
		}
    	virtual bool operator==(const MonkeyFileFunction& b){
			return false;
		}
	protected:	
};

}

#endif 
