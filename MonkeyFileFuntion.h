

/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#ifndef MonkeyFileFuntion_h
#define MonkeyFileFuntion_h

#include "Arduino.h"
#include "cppObject.h"

template<class MFile>
class MonkeyFileFuntion : public cppObject{
    public:
		MonkeyFileFuntion(){}
		virtual ~MonkeyFileFuntion(){}
    	virtual bool SaveFileFuntion(MFile* file,cppObject* instance,String path,String key){
			return false;
		}
    	virtual cppObject* LoadFileFuntion(MFile* file,cppObject* attachable,String path,String key){
			return nullptr;
		}
    	virtual bool DeleteFileFuntion(MFile* file,cppObject* attachable,String path,String key){
			return false;
		}
		
		virtual String getClassName(){
			return "MonkeyFileFuntion";
		}
		virtual String toString(){
			return "MonkeyFileFuntion";
		}
	protected:
	
	
};

#endif 
