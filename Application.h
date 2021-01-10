

#ifndef Application_h
#define Application_h

#include "Arduino.h"
#include "AppStateManager.h"
#include "AppSettings.h"
#include "TimeControl.h"
#include "cppObject.h"
#include "Listener.h"

class Application : public cppObject{
    public:
		virtual ~Application(){}
		virtual void setSettings(AppSettings *setting)=0;
		
		virtual AppSettings *getSettings()=0;
		
		virtual void setStateManager(AppStateManager *appstate)=0;
		
		virtual AppStateManager *getStateManager()=0;
		
		virtual void setTimeControl(TimeControl *timecontrol)=0;
		
		virtual TimeControl *getTimeControl()=0;
		
	/*	virtual void setAssetManager(AssetManager *assets){
			
		}
		virtual AssetManager *getAssetManager(){
			
		}*/
		virtual Listener* setListener(Listener* listener)=0;
		
		virtual Listener* getListener()=0;
		
		virtual void update()=0;
    
	private:
};

#endif 
