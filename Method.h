#ifndef Method_h
#define Method_h

#include "cppObject.h"

class Method{
public:
~Method(){}
template<class R, class Instance, class... Args>
static R invokeGlobal(Instance* methodClass, String method, Args... args){
	return methodClass->invokeGlobal(method, args...);
}
template<class R, class Instance, class... Args>
static R invoke(Instance* methodClass, String method, Args... args){
	return methodClass->invoke(method, args...);
}
// virtual cppObject* invokeGlobal(String method){return nullptr;}
// virtual cppObject* invokeGlobal(String method, String parameter1){return nullptr;}
// virtual cppObject* invokeGlobal(String method, String parameter1, String parameter2){return nullptr;}
// virtual cppObject* invoke(String method){return nullptr;}
// virtual cppObject* invoke(String method, String parameter1){return nullptr;}
// virtual cppObject* invoke(String method, String parameter1, String parameter2){return nullptr;}
// virtual void operator=(Method b){}
// virtual bool operator==(Method b){return true;}
// virtual bool operator!=(Method b){return false;}
		
protected:
};

#endif