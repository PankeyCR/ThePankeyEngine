
#ifndef cppObjectClass_hpp
	#define cppObjectClass_hpp

	namespace pankey{

		class cppObjectClass;

	}

	#include "CharArray.hpp"
	#include "Annotation.hpp"
	#include "Method.hpp"
	#include "Pointer.hpp"

	namespace pankey{
		
		template<class H, class A>
		class cppObjectClass{	
			public:
				cppObjectClass(){}
				cppObjectClass(char* c_name){m_name = c_name;}
				virtual ~cppObjectClass(){}
				
				virtual cppObjectClass* getClass(){return nullptr;}
				virtual bool instanceof(cppObjectClass* cls){return false;}
				
				virtual void setName(CharArray a_name){
					m_name = a_name;
				}
				
				virtual CharArray getName(){
					return m_name;
				}
				
				virtual long getType(){
					return -1;
				}
				
				Variable<H,A> newInstance(){
					return Variable<H,A>();
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
				
				virtual Method* getMethodByName(char* a_name){
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
				String m_name = nullptr;
		};

	}

#endif