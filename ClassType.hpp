
#ifndef ClassType_hpp
#define ClassType_hpp

#if defined(ame_untilLevel_10)

#include "cppObjectClass.hpp"
#include "Method.hpp"
#include "Annotation.hpp"
#include "RawList.hpp"
#include "PrimitiveRawList.hpp"

namespace ame{

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
	static void add(String n){
		if(methods == nullptr){
			return;
		}
		methods->addPointer(new Method(n));
	}
	static void addOnce(String n){
		if(methods == nullptr){
			return;
		}
		if(methods->containByLValue(n)){
			return;
		}
		methods->addPointer(new Method(n));
	}
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

}

#endif

#endif 
