
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef Event_hpp
#define Event_hpp

#include "Arduino.h"

namespace ame{

template<class T>
class Event{
	protected:
		T var;
		using EventMethod = void (*)(T);
		
    public:
		Event(){}
		virtual ~Event(){}
		virtual void event(){}
		virtual void event(T c){}
		virtual void setName(T n){}
		virtual void add(EventMethod c){}
		virtual void add(T name, EventMethod c){}
};

}

#endif 

#endif 
