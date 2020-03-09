
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
      if(app->getTimeControl()->getClassName() == "SimpleTimer"){
        ((SimpleTimer*)app->getTimeControl())->setScale(TimeScale::Second);
        ((SimpleTimer*)app->getTimeControl())->initialize(0.5f);//time is scaled for the timer
        ((SimpleTimer*)app->getTimeControl())->startInterrupt();
        ((SimpleTimer*)app->getTimeControl())->attachInterrupt();
        ((SimpleTimer*)app->getTimeControl())->getMonkeyTime()->start();
        serial->println("init start");
      }			
      App = app;
		}
    String getClassName(){
      return "StartState";
    }
    void update(){
      App->getTimeControl()->getMonkeyTime()->computeTime();
    }
   		
	private:
    Application *App;
    Stream *serial=NULL;
  
};

#endif 
