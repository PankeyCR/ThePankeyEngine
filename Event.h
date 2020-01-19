

#ifndef Event_h
#define Event_h

#include "Arduino.h"

template<class T>
class Event{
	protected:
		T var;
		using EventMethod = void (*)(T);
		
    public:
		Event();
		virtual ~Event();
		virtual void event();
		virtual void event(T c);
		virtual void setName(T n);
		virtual void add(EventMethod c);
		virtual void add(T name, EventMethod c);
		
};

#endif 
