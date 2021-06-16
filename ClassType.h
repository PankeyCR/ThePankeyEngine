
#ifndef ClassType_h
#define ClassType_h

#include "cppObjectClass.h"
#include "Method.h"
#include "DefaultMethod.h"
#include "Annotation.h"
#include "RawList.h"
#include "PrimitiveRawList.h"

template<class cls>
struct ClassAnnotation{
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

template<class cls> RawList<Annotation>* ClassAnnotation<cls>::annotations = new PrimitiveRawList<Annotation>();

template<class cls>
struct ClassName{
	static String className;
};

template<class cls> String ClassName<cls>::className = "Default";

template<class cls>
struct ClassMethod{
	static RawList<Method>* methods;
	static Method* getMethod(String n){
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

template<class cls> RawList<Method>* ClassMethod<cls>::methods = new PrimitiveRawList<Method>();

template<class cls, class R, class... Args>
struct MethodType{
	static RawList<DefaultMethod<cls,R,Args...>>* typeMethods;
	static void add(DefaultMethod<cls,R,Args...>* m){
		RawList<Method>* list = ClassMethod<cls>::methods;
		if(list == nullptr || typeMethods == nullptr){
			return;
		}
		list->addPointer(m);
		typeMethods->addPointer(m);
	}
	static DefaultMethod<cls,R,Args...>* getMethod(String n){
		if(typeMethods == nullptr){
			return nullptr;
		}
		for(int x = 0; x < typeMethods->getPosition(); x++){
			DefaultMethod<cls,R,Args...>* mm = typeMethods->getByPosition(x);
			if(mm->getName() == n){
				return mm;
			}
		}
		return nullptr;
	}
};

template<class cls, class R, class... Args> RawList<DefaultMethod<cls,R,Args...>>* MethodType<cls,R,Args...>::typeMethods = new PrimitiveRawList<DefaultMethod<cls,R,Args...>>();

template<class T>
class ClassType : public cppObjectClass{	
	public:
		ClassType(){}
		virtual ~ClassType(){}
		
		virtual String getName(){
			return ClassName<T>::className;
		}
		
		virtual RawList<Annotation>* getAnnotations(){
			return ClassAnnotation<T>::annotations;
		}
		
		virtual Annotation* getAnnotation(cppObjectClass* cls){
			RawList<Annotation>* list = ClassAnnotation<T>::annotations;
			for(int x = 0; x < list->getPosition(); x++){
				Annotation* a = list->getByPosition(x);
				if(a->getClass() == cls){
					return a;
				}
			}
			return nullptr;
		}
		
		virtual RawList<Method>* getMethods(){
			return ClassMethod<T>::methods;
		}
		
		virtual Method* getMethod(String namae){
			RawList<Method>* list = ClassMethod<T>::methods;
			if(list == nullptr){
				return nullptr;
			}
			for(int x = 0; x < list->getPosition(); x++){
				Method* m = list->getByPosition(x);
				if(m->getName() == namae){
					return m;
				}
			}
			return nullptr;
		}
};



template<class I,class R,class... Args>
R invoke(I* i, Method* mt, R r, Args... a){
	Method* m = ClassMethod<I>::getMethod(mt->getName());
	DefaultMethod<I,R,Args...>* dm = MethodType<I,R,Args...>::getMethod(mt->getName());
	if(dm == nullptr){
		return r;
	}
	if(dm == m){
		return dm->invokeMethod(i,a...);
	}
	return r;
}

template<class I,class R,class... Args>
R invoke(I* i, String n, R r, Args... a){
	Method* m = ClassMethod<I>::getMethod(n);
	DefaultMethod<I,R,Args...>* dm = MethodType<I,R,Args...>::getMethod(n);
	if(dm == nullptr){
		return r;
	}
	if(dm == m){
		return dm->invokeMethod(i,a...);
	}
	return r;
}

	
	
#endif 
