

#ifndef ListEvent_h
#define ListEvent_h

#include "Event.h"
#include "ArrayList.h"
#include "List.h"

namespace ame{

template<class T>
class ListEvent : public Event<T>{
	protected:
		using EventMethod = void (*)(T);
		List<EventMethod>* list;
    public:
		ListEvent();
		virtual ~ListEvent();
		virtual void event();
		virtual void event(T c);
		virtual void add(EventMethod c);
		virtual void add(T name, EventMethod c);
};

}

#endif 
