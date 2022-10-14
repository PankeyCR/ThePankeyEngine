
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