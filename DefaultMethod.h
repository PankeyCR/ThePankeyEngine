#ifndef DefaultMethod_h
#define DefaultMethod_h

#include "RawList.h"
#include "PrimitiveRawList.h"
#include "Annotation.h"
#include "Method.h"

template<class I, class R, class... Args>
struct MethodAnnotation{
	static RawList<Annotation>* annotations;
	static void add(Annotation* a){
		if(annotations == nullptr){
			return;
		}
		if(annotations->containByPointer(a)){
			return;
		}
		annotations->addPointer(a);
	}
};

template<class I, class R, class... Args> RawList<Annotation>* MethodAnnotation<I,R,Args...>::annotations = new PrimitiveRawList<Annotation>();

template<class I, class R, class... Args>
class DefaultMethod : public Method{
public:
	using MethodVar = R(I::*)(Args...);
	MethodVar m_var;
	
	DefaultMethod(){
	}
	
	DefaultMethod(String n){
		m_name = n;
	}
	
	DefaultMethod(String n, MethodVar v){
		m_var = v;
		m_name = n;
	}
	virtual ~DefaultMethod(){}
	
	virtual void setMethod(MethodVar v){
		m_var = v;
	}

	virtual R invokeMethod(I* i, Args... a){
		return (i->*m_var)(a...);
	}
		
	virtual RawList<Annotation>* getAnnotations(){
		return MethodAnnotation<I,R,Args...>::annotations;
	}
	
	virtual Annotation* getAnnotation(cppObjectClass* cls){
		RawList<Annotation>* list = MethodAnnotation<I,R,Args...>::annotations;
		for(int x = 0; x < list->getPosition(); x++){
			Annotation* a = list->getByPosition(x);
			if(a->getClass() == cls){
				return a;
			}
		}
		return nullptr;
	}
	virtual void operator=(DefaultMethod b){}
	virtual bool operator==(DefaultMethod b){return true;}
	virtual bool operator!=(DefaultMethod b){return false;}
		
protected:
};

#endif