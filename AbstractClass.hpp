
#ifndef DISABLE_AbstractClass_hpp
#define DISABLE_AbstractClass_hpp

	#if defined(DISABLE_cppObject) || defined(DISABLE_cppObjectClass) || defined(DISABLE_AbstractClass)
		#define AbstractClass_hpp
	#endif
#endif

#ifndef AbstractClass_hpp
#define AbstractClass_hpp
#define AbstractClass_AVAILABLE

#include "cppObject.hpp"
#include "ClassCount.hpp"

namespace ame{

template<class cls = cppObject>
struct AbstractClass{
	static cppObjectClass* classType;
	
	static cppObjectClass* getClass(){return classType;}
	
	static long getType(){
		return ClassCount<cls>::get();
	}
};

template<class cls> cppObjectClass* AbstractClass<cls>::classType = new cppObjectClass();

}

#endif