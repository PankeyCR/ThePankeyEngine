
#ifndef cppObject_hpp
#define cppObject_hpp

#include "ame_Level.hpp"

#include "Arduino.h"
#include "Method.hpp"
#include "cppObjectClass.hpp"
#include "ClassType.hpp"

namespace ame{

#if defined(ame_untilLevel_10)

template<class cls>
struct Class{
	static ClassType<cls>* classType;
};

template<class cls> ClassType<cls>* Class<cls>::classType = new ClassType<cls>();

// #elif defined(ame_untilLevel_1)
#else

template<class cls>
struct Class{
	static cppObjectClass* classType;
};

template<class cls> cppObjectClass* Class<cls>::classType = new cppObjectClass();

#endif

class cppObject{
    public:
		cppObject(){}
		virtual ~cppObject(){}
		virtual void onDelete(){}
		virtual String toString(){return "cppObject";}
		virtual bool equal(cppObject *b){return this == b;}
		template<class T>
		bool instanceof(){
			return this->instanceof(Class<T>::classType);
		}
		virtual bool instanceof(cppObjectClass* cls){return cls == Class<cppObject>::classType;}
		
		virtual cppObjectClass* getClass(){return Class<cppObject>::classType;}
		
		virtual cppObject *clone(void){return nullptr;}
		virtual cppObject *clone(bool owningMemory){return nullptr;}
		
		virtual void invoke(String methodName){}
		
		virtual void operator=(cppObject b){}
		virtual bool operator==(cppObject b){return false;}
		virtual bool operator!=(cppObject b){return false;}
	private:
};

}

#endif 
