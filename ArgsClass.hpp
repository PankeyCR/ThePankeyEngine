
#ifndef DISABLE_ArgsClass_hpp
#define DISABLE_ArgsClass_hpp

	#if defined(DISABLE_cppObject) || defined(DISABLE_cppObjectClass) || defined(DISABLE_ArgsClass)
		#define ArgsClass_hpp
	#endif
#endif

#ifndef ArgsClass_hpp
#define ArgsClass_hpp
#define ArgsClass_AVAILABLE

#include "cppObject.hpp"
#include "ClassCount.hpp"
#include "TemplateArgsClass.hpp"

namespace ame{

template<class cls = cppObject>
struct ArgsClass{
	static cppObjectClass* classType;
	
	static cppObjectClass* getClass(){return classType;}
	
	static long getType(){
		return ClassCount<cls>::get();
	}
};

template<class cls> cppObjectClass* ArgsClass<cls>::classType = new TemplateArgsClass<cls>();

}

#endif