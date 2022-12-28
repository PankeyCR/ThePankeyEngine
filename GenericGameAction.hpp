
#include "ame_Enviroment.hpp"

#if defined(DISABLE_GameAction)
	#define GameAction_hpp
#endif

#ifndef GameAction_hpp
#define GameAction_hpp
#define GameAction_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "GameOn.hpp"

namespace ame{

class GameAction : public GameOn{
    public:
	
		virtual cppObjectClass* getClassName(){
			return Class<GameAction>::classType;
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<GameAction>::classType || GameOn::instanceof(cls);
		}
	
		virtual Action();
};

}

#endif