

#ifndef SimpleEvent_h
#define SimpleEvent_h

#include "Arduino.h"
#include "Event.h"

template<class T>
class SimpleEvent : public Event<T>{
	protected:
		using EventMethod = void (*)(T);
		EventMethod m = nullptr;
    public:
		SimpleEvent();
		virtual ~SimpleEvent();
		virtual void event();
		virtual void event(T c);
		virtual void add(EventMethod c);
		virtual void add(T name, EventMethod c);
		
};

#endif 
