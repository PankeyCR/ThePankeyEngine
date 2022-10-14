
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Serialization)
	#define Serialization_hpp
#endif

#ifndef Serialization_hpp
#define Serialization_hpp
#define Serialization_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "AppState.hpp"
#include "cppObjectClass.hpp"
#include "Class.hpp"
#include "Note.hpp"
#include "ByteArray.hpp"
#include "MessageDelivery.hpp"
#include "NetworkConnectivity.hpp"
#include "NetworkReliability.hpp"

namespace ame{

class Serialization : public AppState{	
    public:	
		Serialization(){}
		virtual ~Serialization(){}
		
		void disconect(Note a_name) {}
		
		virtual bool ping(Note a_name){
			return false;
		}
			
		virtual cppObjectClass* getClass(){
			return Class<Serialization>::classType;
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<Serialization>::getClass() || AppState::instanceof(cls);
		}
		
	protected:
};

}

#endif