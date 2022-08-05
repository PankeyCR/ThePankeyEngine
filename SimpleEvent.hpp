
#include "ame_Enviroment.hpp"

#if defined(DISABLE_SimpleEvent)
	#define SimpleEvent_hpp
#endif

#ifndef SimpleEvent_hpp
#define SimpleEvent_hpp
#define SimpleEvent_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Event.hpp"

namespace ame{

template<class T>
class SimpleEvent : public Event<T>{
	protected:
		using EventMethod = void (*)(T);
		EventMethod m = nullptr;
    public:
		SimpleEvent(){}
		virtual ~SimpleEvent(){}
		
		virtual void event(){
			this->m(this->var);
		}
		
		virtual void event(T c){
			if(this->var != c){
				this->var = c;
				this->m(this->var);
			}
		}
		
		virtual void add(EventMethod c){
			this->m = c;
		}
		virtual void add(T name, EventMethod c){}
};

}

#endif