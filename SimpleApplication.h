

#ifndef SimpleApplication_h
#define SimpleApplication_h

#include "Arduino.h"
#include "Application.h"
#include "AppStateManager.h"
#include "AppSettings.h"
#include "TimeControl.h"
#include "SimpleTimer.h"
#include "SimpleAppSettings.h"
#include "SimpleStateManager.h"
#include "Logger.h"

template <int SettingsSize>
class SimpleApplication : public Application{
    public:
		SimpleApplication(){
			states = new SimpleStateManager<SettingsSize>();
			settings = new SimpleAppSettings<SettingsSize>();
			states->setApplication(this);
			//Log("println","Start SimpleApplication ");
		}
		void setSettings(AppSettings *setting){
			settings = setting;
		}
		AppSettings *getSettings(){
			return settings;
		}
		void setStateManager(AppStateManager *appstate){
			states = appstate;
		}
		AppStateManager *getStateManager(){
			return states;
		}
		void update(){
			//Log("println","update SimpleApplication ");
			states->update();
		}
		void setTimeControl(TimeControl *timecontrol){
		}
		TimeControl *getTimeControl(){
			return SimpleTimer::getInstance();
		}
		String getClassName(){
			return "SimpleApplication";
		}
		String toString(){
			return "SimpleApplication";
		}
    
	private:	
	AppStateManager *states;
	AppSettings *settings;
};

#endif 
