
#ifndef TimerState_h
#define TimerState_h

#include "AppState.h"

class TimerState : public AppState, TimeElapsed{
	public:
	
		TimerState(Stream *port){
			serial = port;
		}
    ~TimerState(){}
   
		void initialize(Application *app){
      if(app->getTimeControl()->getClassName() == "SimpleTimer"){
        ((SimpleTimer*)app->getTimeControl())->add(this);
      }
		}
   
		void Play(TimeControl *t){
			serial->println(t->getMonkeyTime()->getScaleTime());
		}
    String getClassName(){
      return "TimerState";
    }
		
	private:
		Stream *serial=NULL;
};

#endif 
