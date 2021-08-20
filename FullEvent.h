

#ifndef FullEvent_h
#define FullEvent_h

#include "Event.h"
#include "List.h"
#include "Map.h"

namespace ame{

template<class T>
class FullEvent : public Event{
	protected:
		T var;
		List* list;
		Map* map;
    public:
		using EventMethod = void (*)(T);
		FullEvent();
		virtual ~FullEvent();
		virtual void event();
		virtual void event(T c);
		virtual void add(EventMethod c);
		virtual void add(T name, EventMethod c);
};

}

#endif 
