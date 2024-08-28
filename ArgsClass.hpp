
#ifndef ArgsClass_hpp
#define ArgsClass_hpp
#define ArgsClass_AVAILABLE

#include "cppObject.hpp"
#include "ClassCount.hpp"
#include "TemplateArgsClass.hpp"

namespace pankey{

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