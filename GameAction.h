

#ifndef GameAction_h
#define GameAction_h

#include "GameOn.h"

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
