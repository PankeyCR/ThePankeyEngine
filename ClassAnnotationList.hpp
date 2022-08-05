
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ClassAnnotationList)
	#define ClassAnnotationList_hpp
#endif

#ifndef ClassAnnotationList_hpp
#define ClassAnnotationList_hpp
#define ClassAnnotationList_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Annotation.hpp"
#include "RawList.hpp"
#include "PrimitiveRawList.hpp"

namespace ame{

template<class cls>
struct ClassAnnotationList{
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

template<class cls> RawList<Annotation>* ClassAnnotationList<cls>::annotations = new PrimitiveRawList<Annotation>();

}

#endif