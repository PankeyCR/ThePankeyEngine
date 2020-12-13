

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
#include "Listener.h"

template <int StatesSize, int SettingsSize>
class SimpleApplication : public Application{
    public:
		SimpleApplication(){
			states = new SimpleStateManager<StatesSize>();
			settings = new SimpleAppSettings<SettingsSize>();
			states->setApplication(this);
			//Log("println","Start SimpleApplication ");
		}
		void setSettings(AppSettings *set){
			if(this->settings != nullptr && this->settings != set){
				delete this->settings;
			}
			this->settings = set;
		}
		AppSettings *getSettings(){
			return settings;
		}
		void setStateManager(AppStateManager *manager){
			if(this->states != nullptr && this->states != manager){
				delete this->states;
			}
			this->states = manager;
		}
		AppStateManager *getStateManager(){
			return states;
		}
		
		void setListener(Listener* l){
			listener = l;
			listener->attach(this);
		}
		Listener* getListener(){
			return listener;
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
	AppStateManager *states = nullptr;
	AppSettings *settings = nullptr;
	Listener *listener = nullptr;
};

#endif 
