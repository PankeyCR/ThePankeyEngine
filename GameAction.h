

#ifndef GameAction_h
#define GameAction_h

#include "GameOn.h"

class GameAction : public GameOn{
    public:
	
		virtual String getClassName(){
			return "GameAction";
		}
		
		virtual bool instanceof(String s){
			return s == "GameAction" || GameOn::instanceof(s);
		}
	
		virtual Action();
};


#endif 
