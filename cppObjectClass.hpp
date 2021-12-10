
#ifndef cppObjectClass_hpp
#define cppObjectClass_hpp

#include "Arduino.h"
#include "RawList.hpp"

#if defined(ame_untilLevel_10)
	#include "Annotation.hpp"
	#include "Method.hpp"
#endif 

namespace ame{

class cppObjectClass{	
	public:
		cppObjectClass(){}
		virtual ~cppObjectClass(){}
		
		virtual String getName(){
			return "cppObjectClass";
		}
		
		#if defined(ame_untilLevel_10)
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
		#endif 
		
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
