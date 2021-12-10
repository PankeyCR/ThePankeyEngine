
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef FullEvent_hpp
#define FullEvent_hpp

#include "Event.hpp"
#include "List.hpp"
#include "Map.hpp"

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

#endif 
