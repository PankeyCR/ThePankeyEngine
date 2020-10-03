#ifndef Method_h
#define Method_h

#include "cppObject.h"

class Method{
public:
~Method(){}
template<class Instance, class... Args>
static cppObject* invoke(Instance* methodClass, String method, Args... args){
	if(methodClass == nullptr){
		return nullptr;
	}
	return methodClass->invoke(method, args...);
}
virtual cppObject* invoke(String method){return nullptr;}
virtual cppObject* invoke(String method, String parameter){return nullptr;}
virtual cppObject* invoke(String method, String parameter, String parameter2){return nullptr;}
virtual void operator=(Method b){}
virtual bool operator==(Method b){return true;}
virtual bool operator!=(Method b){return false;}
		
protected:
};

#endif