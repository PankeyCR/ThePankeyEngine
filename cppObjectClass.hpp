
#ifndef cppObjectClass_hpp
#define cppObjectClass_hpp
#define cppObjectClass_AVAILABLE

#include "Annotation.hpp"
#include "Method.hpp"

namespace ame{

class cppObjectClass{	
	public:
		cppObjectClass(){}
		virtual ~cppObjectClass(){}
		
		virtual cppObjectClass* getClass(){return nullptr;}
		virtual bool instanceof(cppObjectClass* cls){return false;}
		
		virtual void setName(char* a_name){
			m_name = a_name;
		}
		
		virtual char* getName(){
			return m_name;
		}
		
		virtual long getType(){
			return -1;
		}
		
		virtual cppObject* newInstance(){
			return nullptr;
		}
		
		virtual void* newPointer(){
			return nullptr;
		}

		virtual Annotation* addAnnotation(Annotation* a_annotation){
			RawPointerList<Annotation>* i_annotations = this->getAnnotations();
			if(i_annotations == nullptr || a_annotation == nullptr){
				return nullptr;
			}
			return i_annotations->addPointer(a_annotation);
		}

		virtual RawPointerList<Annotation>* getAnnotations(){
			return nullptr;
		}
		
		virtual Annotation* getAnnotation(cppObjectClass* cls){
			return nullptr;
		}

		virtual Method* addMethod(Method* a_method){
			RawPointerList<Method>* i_methods = this->getMethods();
			if(i_methods == nullptr || a_method == nullptr){
				return nullptr;
			}
			return i_methods->addPointer(a_method);
		}

		virtual RawPointerList<Method>* getMethods(){
			return nullptr;
		}
		
		virtual Method* getMethod(cppObjectClass* cls){
			return nullptr;
		}
		
		virtual void operator=(cppObjectClass b){
			
		}
		virtual bool operator==(cppObjectClass b){
			return false;
		}
		virtual bool operator!=(cppObjectClass b){
			return false;
		}
	protected:
		char* m_name = nullptr;
};

}

#endif