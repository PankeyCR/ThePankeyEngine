

#ifndef AnalogReadState_h
#define AnalogReadState_h
/*
#include "AppState.h"
#include "TimeControl.h"
#include "AnalogRead.h"
#include "ArrayList.h"

class AnalogReadState : public AppState,public AnalogRead,TimeElapsed{
  public:
    Application *App;
    
    AnalogReadState():AnalogRead(){

    }
    
    virtual void Play(TimeControl *t){
        Read();
    }
    
    virtual void initialize(Application *app){
      App = app;
      App->getTimer()->add(this);
    }
    
	  virtual void onEnable(){

	  }
   
	  virtual void onDisable(){
      App->getTimer()->remove(this);
	  }
   
	  virtual void update(){
	    
	  }
    
	private:
};
*/
#endif 
