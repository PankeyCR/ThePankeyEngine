
#ifndef StartState_h
#define StartState_h

#include "AppState.h"
#include "Application.h"
#include "MetricScale.h"
#include "MetricPrefix.h"

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
   
		String getClassName(){
			return "StartState";
		}
   		
	private:
    Application *App;
    Stream *serial=NULL;
  
};

#endif 