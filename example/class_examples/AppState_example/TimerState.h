
#ifndef TimerState_h
#define TimerState_h

#include "AppState.h"

using namespace ame;

class TimerState : public AppState, public TimeElapsed{
	public:
	
		TimerState(Stream *port){
			serial = port;
		}
   
		void initialize(Application *app){
		  app->getTimeControl()->add(this);
		}
   
		void Play(TimeControl *t){
			serial->println(t->getTime());
		}
   
    bool instanceof(cppObjectClass* cls){
      return cls == Class<TimerState>::classType || AppState::instanceof(cls);
    }
   
    cppObjectClass* getClass(){
      return Class<TimerState>::classType;
    }
		
	private:
		Stream *serial = nullptr;
};

#endif 