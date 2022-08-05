
#include "ame_Enviroment.hpp"

#if defined(DISABLE_GenericClass)
	#define GenericClass_hpp
#endif

#ifndef GenericClass_hpp
#define GenericClass_hpp
#define GenericClass_AVAILABLE

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

class GenericClass : public cppObjectClass{	
	public:
		GenericClass(){
			m_type = getGenericClassCount();
			annotationList = new PrimitiveRawList<Annotation>();
			methodList = new PrimitiveRawList<Method>();
		}
		GenericClass(Note c_note){
			m_type = getGenericClassCount();
			m_name = c_note;
			annotationList = new PrimitiveRawList<Annotation>();
			methodList = new PrimitiveRawList<Method>();
		}
		virtual ~GenericClass(){}
		
		virtual long getType(){
			return m_type;
		}
		
		virtual void setName(Note a_name){
			m_name = a_name;
		}
		
		virtual Note getName(){
			return m_name;
		}
		
		virtual void* newPointer(){
			return nullptr;
		}
		
		#ifdef Annotation_AVAILABLE
		virtual RawList<Annotation>* getAnnotations(){
			return annotationList;
		}
		
		virtual Annotation* getAnnotation(cppObjectClass* cls){
			RawList<Annotation>* list = annotationList;
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
			return methodList;
		}
		
		virtual Method* getMethod(Note namae){
			RawList<Method>* list = methodList;
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
			RawList<Method>* list = methodList;
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
	
	protected:
		
		long m_type = -1;
		Note m_name;
		RawList<Annotation>* annotationList = nullptr;
		RawList<Method>* methodList = nullptr;
};

}

#endif