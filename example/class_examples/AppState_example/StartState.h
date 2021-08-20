
#ifndef StartState_h
#define StartState_h

#include "AppState.h"
#include "Application.h"
#include "MetricScale.h"
#include "MetricPrefix.h"

using namespace ame;

class StartState : public AppState{
	public:
 
		StartState(){}
		StartState(Stream *port){
			serial = port;
		}
   
		void initialize(Application *app){
			MetricScale scale;
			scale.setScaleTransform(MetricPrefix::micro , MetricPrefix::none);
			app->getTimeControl()->initialize(scale.getValue(2));// 2 seconds
			app->getTimeControl()->startInterrupt();
			app->getTimeControl()->attachInterrupt();
			serial->println("init start");
			App = app;
		}
   
    bool instanceof(cppObjectClass* cls){
      return cls == Class<StartState>::classType || AppState::instanceof(cls);
    }
   
    cppObjectClass* getClass(){
      return Class<StartState>::classType;
    }
   		
	private:
    Application *App;
    Stream *serial = nullptr;
  
};

#endif 