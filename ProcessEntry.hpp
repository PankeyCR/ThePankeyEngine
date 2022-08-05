
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ProcessEntry)
	#define ProcessEntry_hpp
#endif

#ifndef ProcessEntry_hpp
#define ProcessEntry_hpp
#define ProcessEntry_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Processing.hpp"

namespace ame{

template<class P, class V>
class ProcessEntry{
	public:
		ProcessEntry(P key, Processing<V>* value){
			this->key = key;
			this->value = value;
		}
		
		virtual ~ProcessEntry(){
			
		}
			
		
		virtual P getKey(){
			return this->key;
		}
		
		virtual Processing<V>* getValue(){
			return this->value;
		}
		
	protected:
		P key;
		Processing<V>* value;
};

}

#endif