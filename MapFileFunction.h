

/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#ifndef MapFileFunction_h
#define MapFileFunction_h

#include "Arduino.h"
#include "cppObject.h"
#include "MonkeyFile.h"
#include "PrimitiveMap.h"
#include "Note.h"

template<class K,class V>
class MapFileFunction : public MonkeyFileFunction{
    public:
		MapFileFunction();
		virtual ~MapFileFunction();
		
    	virtual bool SaveFileFunction(MonkeyFile* file,cppObject* instance,String path,String key);
    	virtual cppObject* LoadFileFunction(MonkeyFile* file,cppObject* attachable,String path,String key);
    	virtual bool DeleteFileFunction(MonkeyFile* file,cppObject* attachable,String path,String key);
		
	protected:
	
	
};

#endif 
