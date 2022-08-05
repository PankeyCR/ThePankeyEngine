
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MapEvent)
	#define MapEvent_hpp
#endif

#ifndef MapEvent_hpp
#define MapEvent_hpp
#define MapEvent_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Event.hpp"
#include "Map.hpp"

namespace ame{
	
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

}

#endif