
#include "ame_Enviroment.hpp"

#if defined(DISABLE_TemplateClass)
	#define TemplateClass_hpp
#endif

#ifndef TemplateClass_hpp
#define TemplateClass_hpp
#define TemplateClass_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Annotation.hpp"
#include "Method.hpp"
#include "cppObjectClass.hpp"
#include "ClassAnnotationList.hpp"
#include "ClassMethodList.hpp"
#include "RawList.hpp"
#include "PrimitiveRawList.hpp"
#include "ClassName.hpp"
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
		
		virtual void setName(Note a_name){
			ClassName<T>::className = a_name;
		}
		
		virtual Note getName(){
			return ClassName<T>::className;
		}
		
		virtual void* newPointer(){
			return nullptr;
		}
		
		#ifdef Annotation_AVAILABLE
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
		
		#ifdef Method_AVAILABLE
		virtual RawList<Method>* getMethods(){
			return ClassMethodList<T>::methods;
		}
		
		virtual Method* getMethod(Note namae){
			RawList<Method>* list = ClassMethodList<T>::methods;
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