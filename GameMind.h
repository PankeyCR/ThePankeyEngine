

#ifndef GameMind_h
#define GameMind_h

#include "GameOn.h"

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
