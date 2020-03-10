
#ifndef TimerState_h
#define TimerState_h

#include "AppState.h"

class TimerState : public AppState, TimeElapsed{
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
		
		String getClassName(){
		  return "TimerState";
		}
		
	private:
		Stream *serial=NULL;
};

#endif 