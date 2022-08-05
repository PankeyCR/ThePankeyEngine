
#include "ame_Enviroment.hpp"

#if defined(DISABLE_GameMind)
	#define GameMind_hpp
#endif

#ifndef GameMind_hpp
#define GameMind_hpp
#define GameMind_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "GameOn.hpp"

namespace ame{

class GameMind : public GameOn{
    public:
	
		virtual cppObjectClass* getClass(){
			return Class<GameMind>::classType;
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<GameMind>::classType || GameOn::instanceof(cls);
		}
	
		virtual void think();
		virtual bool doneThinking();
};

}

#endif