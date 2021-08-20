
#ifndef Method_h
#define Method_h

#include "RawList.h"
#include "MethodMap.h"
#include "Annotation.h"
#include "StaticMethodMap.h"
#include "TypeErasedInvoke.h"

namespace ame{

template<class T,class... Args>
struct StaticInvoker{
	static StaticMethodMap<String,Args...>* methods;
	static StaticMethodMap<String,Args...>* getMap(){
		return methods;
	}
	static void invoke(String n, Args... a){
		if(methods == nullptr){
			return;
		}
		methods->invoke(n,a...);
	}
};

template<class T,class... Args> StaticMethodMap<String,Args...>* StaticInvoker<T,Args...>::methods = new StaticMethodMap<String,Args...>();


template<class T, class R, class... Args>
struct Invoker{
	static MethodMap<T,R,Args...>* methods;
	static MethodMap<T,R,Args...>* getMap(){
		return methods;
	}
	static R invoke(String n, T* c, Args... a){
		if(methods == nullptr){
			return methods->r;
		}
		return methods->invoke(n,c,a...);
	}
	static R invoke(String n, T* c, R r, Args... a){
		if(methods == nullptr){
			return r;
		}
		return methods->invoke(n,c,r,a...);
	}
};

template<class T, class R, class... Args> MethodMap<T,R,Args...>* Invoker<T,R,Args...>::methods = new MethodMap<T,R,Args...>();


class Method{
public:
	Method(){
	}
	Method(String n){
		m_name = n;
	}
	virtual ~Method(){}
	
	void setName(String n){
		m_name = n;
	}
	String getName(){
		return m_name;
	}
	
	template<class T,class... Args>
	void staticInvoke(Args... a){
		StaticInvoker<T,Args...>::invoke(m_name,a...);
	}
	
	template<class T,class R,class... Args>
	R invoke(T* t, Args... a){
		return Invoker<T,R,Args...>::invoke(m_name,t,a...);
	}
	
	template<class T,class R,class... Args>
	R invoke(T* t, R r, Args... a){
		return Invoker<T,R,Args...>::invoke(m_name,t,r,a...);
	}
	
	template<class... Args>
	void invokeObject(const TypeErasedInvoke<Args...>& t, Args... a){
		t->invoke(m_name,a...);
	}
		
	virtual RawList<Annotation>* getAnnotations(){
		return nullptr;
	}
	
	virtual Annotation* getAnnotation(cppObjectClass* cls){
		return nullptr;
	}
	
	virtual void operator=(Method b){}
	virtual bool operator==(Method b){return true;}
	virtual bool operator!=(Method b){return false;}
		
protected:
	String m_name;
};

}

#endif