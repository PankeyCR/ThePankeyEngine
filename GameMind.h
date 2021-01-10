

#ifndef GameMind_h
#define GameMind_h

#include "GameOn.h"

class GameMind : public GameOn{
    public:
	
		virtual String getClassName(){
			return "GameMind";
		}
		
		virtual bool instanceof(String s){
			return s == "GameMind" || GameOn::instanceof(s);
		}
	
		virtual void think();
		virtual bool doneThinking();
};


#endif 
