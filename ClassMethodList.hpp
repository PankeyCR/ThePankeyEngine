
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ClassMethodList)
	#define ClassMethodList_hpp
#endif

#ifndef ClassMethodList_hpp
#define ClassMethodList_hpp
#define ClassMethodList_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "cppObjectClass.hpp"
#include "MethodType.hpp"
#include "PrimitiveRawList.hpp"

namespace ame{

template<class T>
struct ClassMethodList{
	static RawList<Method>* methods;
	
	static void add(Method* a_method){
		if(methods == nullptr || a_method == nullptr){
			return;
		}
		methods->addPointer(a_method);
	}
	
	static void add(cppObjectClass* cls, Note n, MethodType i_type){
		if(methods == nullptr){
			return;
		}
		methods->addPointer(new Method(cls, n, i_type));
	}
	
	// static void addOnce(Note n){
		// if(methods == nullptr){
			// return;
		// }
		// if(methods->containByLValue(n)){
			// return;
		// }
		// methods->addPointer(new Method(n));
	// }
	
	static Method* getMethod(Note n){
		if(methods == nullptr){
			return nullptr;
		}
		for(int x = 0; x < methods->getPosition(); x++){
			Method* mm = methods->getByPosition(x);
			if(mm->getName() == n){
				return mm;
			}
		}
		return nullptr;
	}
};

template<class cls> RawList<Method>* ClassMethodList<cls>::methods = new PrimitiveRawList<Method>();

}

#endif