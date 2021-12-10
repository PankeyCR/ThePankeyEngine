
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef GameAction_hpp
#define GameAction_hpp

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

#endif 
