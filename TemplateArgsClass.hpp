
#ifndef DISABLE_TemplateArgsClass_hpp
#define DISABLE_TemplateArgsClass_hpp

	#if defined(DISABLE_cppObjectClass) || defined(DISABLE_TemplateArgsClass)
		#define TemplateArgsClass_hpp
	#endif
#endif

#ifndef TemplateArgsClass_hpp
#define TemplateArgsClass_hpp
#define TemplateArgsClass_AVAILABLE

#include "cppObject.hpp"
#include "ClassAnnotationList.hpp"
#include "ClassMethodList.hpp"
#include "PrimitiveRawList.hpp"
#include "ClassCount.hpp"

namespace ame{
	
template<class T>
class TemplateArgsClass : public cppObjectClass{	
	public:
		TemplateArgsClass(){}
		virtual ~TemplateArgsClass(){}
		
		virtual long getType(){
			return ClassCount<T>::get();
		}
		
		virtual cppObject* newInstance(){
			return nullptr;
		}
		
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