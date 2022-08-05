
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Object)
	#define Object_hpp
#endif

#ifndef Object_hpp
#define Object_hpp
#define Object_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Note.hpp"
#include "cppObject.hpp"
#include "cppObjectClass.hpp"

namespace ame{

class Object : public cppObject{
    public:
		Object(void* c_pointer, cppObjectClass* c_class){
			m_pointer = c_pointer;
			m_class = c_class;
		}
		Object(const Object& m_object){
			m_pointer = m_object.m_pointer;
			m_class = m_object.m_class;
		}
		Object(){}
		virtual ~Object(){}
		
		virtual void onDelete(){}
		virtual bool equal(Object *b){return this == b;}
		
		virtual bool instanceof(cppObjectClass* cls){return false;}
		virtual cppObjectClass* getClass(){return nullptr;}

		virtual Object *clone(void){return nullptr;}
		virtual Object *clone(bool owningMemory){return nullptr;}

		virtual Note toNote(){return Note("Object");}
		virtual void invoke(Note methodName){}

		virtual void operator=(Object b){}
		virtual bool operator==(Object b){return false;}
		virtual bool operator!=(Object b){return false;}
	private:
		void* m_pointer = nullptr;
		cppObjectClass* m_class = nullptr;
};

}

#endif