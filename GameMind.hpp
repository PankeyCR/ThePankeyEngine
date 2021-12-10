
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef GameMind_hpp
#define GameMind_hpp

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

#endif 
