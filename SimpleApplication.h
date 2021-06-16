

#ifndef SimpleApplication_h
#define SimpleApplication_h

#include "Arduino.h"
#include "Application.h"
#include "AppStateManager.h"
#include "AppSettings.h"
#include "TimeControl.h"
#include "SimpleTimer.h"
#include "Logger.h"
#include "Listener.h"
#include "Node.h"
#include "DefaultSettings.h"
#include "RenderStateManager.h"

class SimpleApplication : public Application{
    public:
		SimpleApplication();
		virtual ~SimpleApplication();
		
		virtual void setSettings(AppSettings *setting);
		virtual AppSettings *getSettings();
		
		virtual void setStateManager(AppStateManager *appstate);
		virtual AppStateManager *getStateManager();
				
		virtual void setTimeControl(TimeControl *timecontrol);
		virtual TimeControl *getTimeControl();
		
		virtual Listener* setListener(Listener* l);
		virtual Listener* getListener();
		
		virtual void update();
		
		virtual Node* getRootNode();
		virtual Node* getGuiNode();
		
		//cppObject part
		virtual String getClassName();
		virtual String toString();
		virtual bool instanceof(String name);
		
	private:
		AppStateManager *states = nullptr;
		AppSettings *settings = nullptr;
		Listener *listener = nullptr;
		Node* rootNode = nullptr;
		Node* guiNode = nullptr;
};

#endif 
