
#ifndef StartState_h
#define StartState_h

#include "AppState.h"
#include "MetricScale.h"
#include "MetricPrefix.h"

class StartState : public AppState{
	public:
 
    StartState(){
		this->id = new String("tomaco");
    }
    
    ~StartState(){
		delete this->id;
    }
    
    StartState(String tid){
		this->id = new String(tid);
    }
   
    void initialize(Application *app){
		MetricScale scale;
		scale.setScaleTransform(MetricPrefix::micro , MetricPrefix::none);
		app->getTimeControl()->initialize(scale.getValue(2));// 2 seconds
		app->getTimeControl()->startInterrupt();
		app->getTimeControl()->attachInterrupt();
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
	
	private:
		Application *App;
  
};

#endif 
