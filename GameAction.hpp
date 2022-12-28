
#ifndef GameAction_hpp
#define GameAction_hpp
#define GameAction_AVAILABLE

#include "GameOn.hpp"

namespace ame{

class GameAction : public GameOn{
    public:
	
		virtual cppObjectClass* getClassName(){
			return Class<GameAction>::getClass();
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<GameAction>::getClass() || GameOn::instanceof(cls);
		}
	
		virtual void Action(){}
};

}

#endif