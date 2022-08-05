
#include "ame_Enviroment.hpp"

#if defined(DISABLE_cppObject)
	#define cppObject_hpp
#endif

#ifndef cppObject_hpp
#define cppObject_hpp
#define cppObject_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Note.hpp"

namespace ame{

class cppObjectClass;

class cppObject{
    public:
		cppObject(){}
		virtual ~cppObject(){}
		
		virtual void onDelete(){}
		virtual bool copy(cppObject* obj){return false;}
		virtual bool move(cppObject* obj){return false;}
		virtual bool equal(cppObject* obj){return this == obj;}
		
		virtual bool instanceof(cppObjectClass* cls){return false;}
		virtual cppObjectClass* getClass(){return nullptr;}

		virtual cppObject* clone(void){return nullptr;}
		virtual cppObject* clone(bool owningMemory){return nullptr;}

		virtual Note toNote(){return Note("cppObject");}
		virtual void invoke(Note methodName){}

		virtual void operator=(cppObject obj){}
		virtual bool operator==(cppObject obj){return false;}
		virtual bool operator!=(cppObject obj){return false;}
	private:
};

}

#endif