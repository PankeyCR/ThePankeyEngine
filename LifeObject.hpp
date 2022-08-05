
#include "ame_Enviroment.hpp"

#if defined(DISABLE_LifeObject)
	#define LifeObject_hpp
#endif

#ifndef LifeObject_hpp
#define LifeObject_hpp
#define LifeObject_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "ByteArray.hpp"

namespace ame{

class LifeObject{
	public:
		LifeObject(){}
		virtual ~LifeObject(){}

		virtual void setCells(ByteArray c){
			
		}

		virtual ByteArray getCells(){
			return ByteArray();
		}

	protected:
};

}

#endif