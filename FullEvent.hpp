
#include "ame_Enviroment.hpp"

#if defined(DISABLE_FullEvent)
	#define FullEvent_hpp
#endif

#ifndef FullEvent_hpp
#define FullEvent_hpp
#define FullEvent_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

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