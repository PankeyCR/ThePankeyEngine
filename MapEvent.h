

#ifndef MapEvent_h
#define MapEvent_h

#include "Event.h"
#include "Map.h"

template<class T>
class MapEvent : public Event{
	protected:
		T var;
		Map* map;
    public:
		using EventMethod = void (*)(T);
		MapEvent();
		virtual ~MapEvent();
		virtual void event();
		virtual void event(T c);
		virtual void add(EventMethod c);
		virtual void add(T name, EventMethod c);
		
};

#endif 
