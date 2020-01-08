

#ifndef AnalogReadPIDState_h
#define AnalogReadPIDState_h
/*
#include "AppState.h"
#include "TimeControl.h"
#include "AnalogReadPID.h"
#include "ArrayList.h"

class AnalogReadPIDState : public AppState,public AnalogReadPID,TimeElapsed{
	public:
		Application *App = NULL;
    
		AnalogReadPIDState(){

		}
    
		virtual void Play(TimeControl *t){
			for(int x=0; x<input->getPos();x++){
				if(*startRecord->getByPos(x)){
					read = analogRead(*input->getByPos(x));
					reader->getByPos(x)->add(read);
					if(*startpid->getByPos(x)){
						pid->getByPos(x)->Compute(t->getTick());
					}
				}
			}
		}
    
		virtual void initialize(Application *app){
			App = app;
			App->getTimer()->add(this);
		}
    
		virtual void addTimer(){
			if(App!=NULL){
				App->getTimer()->add(this);				
			}
		}
		
		virtual void removeTimer(){
			if(App!=NULL){
				App->getTimer()->remove(this);				
			}
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
