
#ifndef StartState_h
#define StartState_h

#include "AppState.h"

class StartState : public AppState{
	public:
 
    StartState(){}
    ~StartState(){
      delete this->id;
    }
    StartState(String tid){
      this->id = new String(tid);
    }
   
    void initialize(Application *app){
//      if(app->getTimeControl()->getClassName() == "SimpleTimer"){
//        ((SimpleTimer*)app->getTimeControl())->initialize(500000);//time in nanos for the timer
//        ((SimpleTimer*)app->getTimeControl())->startInterrupt();
//        ((SimpleTimer*)app->getTimeControl())->attachInterrupt();
//        ((SimpleTimer*)app->getTimeControl())->getMonkeyTime()->setScale(TimeScale::CentiSecond);
//        ((SimpleTimer*)app->getTimeControl())->getMonkeyTime()->start();
//      }      
      App = app;
    }
    void onEnable(){
            
    }
    void onDesable(){
            
    }
    void setId(String tid){
      if(this->id != nullptr){
        delete this->id;
      }
      this->id = new String(tid);
    }
   		
    String getClassName(){
      return "StartState";
    }
    void update(){
      App->getTimeControl()->getMonkeyTime()->computeTime();
    }
	private:
    Application *App;
  
};

#endif 
