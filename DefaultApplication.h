/*
The listener memory is not manged by this class

*/
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

namespace ame{
	
class DefaultApplication : public Application{
	public:
		DefaultApplication();
		virtual ~DefaultApplication();

		virtual void setSettings(AppSettings *setting);
		virtual AppSettings *getSettings();

		virtual void setStateManager(AppStateManager *appstate);
		virtual AppStateManager *getStateManager();
				
		virtual void setTimeControl(TimeControl *timecontrol);
		virtual TimeControl *getTimeControl();

		virtual Listener* setListener(Listener* l);
		virtual Listener* getListener();

		virtual MemoryPool* setMemoryPool(MemoryPool* memory);
		virtual MemoryPool* getMemoryPool();

		virtual void update();

		//cppObject part
		virtual cppObjectClass* getClass();
		virtual String toString();
		virtual bool instanceof(cppObjectClass* cls);

	private:
		AppStateManager *states = nullptr;
		AppSettings *settings = nullptr;
		Listener *listener = nullptr;
		MemoryPool *memory = nullptr;
};

}

#endif 
