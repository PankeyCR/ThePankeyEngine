
#include "ame_Enviroment.hpp"

#if defined(DISABLE_cppObjectClass)
	#define cppObjectClass_hpp
#endif

#ifndef cppObjectClass_hpp
#define cppObjectClass_hpp
#define cppObjectClass_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Annotation.hpp"
#include "Method.hpp"
#include "RawList.hpp"
#include "Note.hpp"

namespace ame{

class cppObjectClass{	
	public:
		cppObjectClass(){}
		virtual ~cppObjectClass(){}
		
		virtual void setName(Note a_name){
		}
		
		virtual long getType(){
			return -1;
		}
		
		virtual Note getName(){
			return "cppObjectClass";
		}
		
		virtual void* newPointer(){
			return nullptr;
		}
		
		#ifdef Annotation_AVAILABLE
		virtual RawList<Annotation>* getAnnotations(){
			return nullptr;
		}
		
		virtual Annotation* getAnnotation(cppObjectClass* cls){
			return nullptr;
		}
		#endif
		
		#ifdef Method_AVAILABLE
		virtual RawList<Method>* getMethods(){
			return nullptr;
		}
		
		virtual Method* getMethod(Note namae){
			return nullptr;
		}
		
		virtual Method* getMethod(cppObjectClass* cls){
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