
#ifndef StartState_h
#define StartState_h

#include "AppState.h"
#include "Application.h"

class StartState : public AppState{
	public:
 
		StartState(){}
		StartState(Stream *port){
			serial = port;
		}
   
		void initialize(Application *app){
			app->getTimeControl()->setScale(TimeScale::Second);
			app->getTimeControl()->initialize(2);//time is scaled for the timer
			app->getTimeControl()->startInterrupt();
			app->getTimeControl()->attachInterrupt();
			serial->println("init start");
			App = app;
		}
   
		String getClassName(){
			return "StartState";
		}
   		
	private:
    Application *App;
    Stream *serial=NULL;
  
};

#endif 