
#ifndef cppObjectClass_h
#define cppObjectClass_h

#include "Arduino.h"
#include "Annotation.h"
#include "RawList.h"
#include "Method.h"

namespace ame{

class cppObjectClass{	
	public:
		cppObjectClass(){}
		virtual ~cppObjectClass(){}
		
		virtual String getName(){
			return "cppObjectClass";
		}
		
		virtual RawList<Annotation>* getAnnotations(){
			return nullptr;
		}
		
		virtual Annotation* getAnnotation(cppObjectClass* cls){
			return nullptr;
		}
		
		virtual RawList<Method>* getMethods(){
			return nullptr;
		}
		
		virtual Method* getMethod(String namae){
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
};

}

#endif 
