

#ifndef DefaultApplication_h
#define DefaultApplication_h

#include "Arduino.h"
#include "Application.h"
#include "AppStateManager.h"
#include "AppSettings.h"
#include "TimeControl.h"
#include "SimpleTimer.h"
#include "DefaultSettings.h"
#include "DefaultStateManager.h"
#include "Listener.h"

class DefaultApplication : public Application{
    public:
		DefaultApplication();
		~DefaultApplication();
		
		virtual void setSettings(AppSettings *setting);
		virtual AppSettings *getSettings();
		
		virtual void setStateManager(AppStateManager *appstate);
		virtual AppStateManager *getStateManager();
				
		virtual void setTimeControl(TimeControl *timecontrol);
		virtual TimeControl *getTimeControl();
		
		virtual Listener* setListener(Listener* l);
		virtual Listener* getListener();
		
		virtual void update();
		
		//cppObject part
		virtual String getClassName();
		virtual String toString();
		
	private:
		AppStateManager *states = nullptr;
		AppSettings *settings = nullptr;
		Listener *listener = nullptr;
};

#endif 
