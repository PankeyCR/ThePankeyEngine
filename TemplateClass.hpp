
#ifndef TemplateClass_hpp
#define TemplateClass_hpp

#include "cppObject.hpp"
#include "ClassAnnotationList.hpp"
#include "ClassMethodList.hpp"
#include "PrimitiveRawList.hpp"
#include "ClassCount.hpp"

namespace ame{
	
template<class T>
class TemplateClass : public cppObjectClass{	
	public:
		TemplateClass(){}
		virtual ~TemplateClass(){}
		
		virtual long getType(){
			return ClassCount<T>::get();
		}
		
		#if defined(cppObject_AVAILABLE)
		virtual cppObject* newInstance(){
			return new T();
		}
		#endif
		
		virtual void* newPointer(){
			return nullptr;
		}
		
		#if defined(Annotation_AVAILABLE)
		virtual RawList<Annotation>* getAnnotations(){
			return ClassAnnotationList<T>::annotations;
		}
		
		virtual Annotation* getAnnotation(cppObjectClass* cls){
			RawList<Annotation>* list = ClassAnnotationList<T>::annotations;
			for(int x = 0; x < list->getPosition(); x++){
				Annotation* a = list->getByPosition(x);
				if(a->getClass() == cls){
					return a;
				}
			}
			return nullptr;
		}
		#endif
		
		#if defined(Method_AVAILABLE)
		virtual RawList<Method>* getMethods(){
			return ClassMethodList<T>::methods;
		}
		
		virtual Method* getMethod(cppObjectClass* cls){
			RawList<Method>* list = ClassMethodList<T>::methods;
			if(list == nullptr){
				return nullptr;
			}
			for(int x = 0; x < list->getPosition(); x++){
				Method* m = list->getByPosition(x);
				if(m->getClass() == cls){
					return m;
				}
			}
			return nullptr;
		}
		#endif
};

}

#endif