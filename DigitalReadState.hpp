

#ifndef DigitalReadState_hpp
#define DigitalReadState_hpp
/*
#include "AppState.hpp"
#include "TimeControl.h"
#include "DigitalRead.h"
#include "ArrayList.h"

class DigitalReadState : public AppState,public DigitalRead,TimeElapsed{
  public:
    Application *App;
    
    DigitalReadState():DigitalRead(){

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
