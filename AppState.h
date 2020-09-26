

#ifndef AppState_h
#define AppState_h

#include "Arduino.h"
#include "cppObject.h"

class Application;

class AppState : public cppObject{
    public:
		virtual void initialize(Application *app);
		virtual void onEnable();
		virtual void onDisable();
		virtual String getId();
		virtual void update(float tpc);
		virtual void operator=(AppState b);
		virtual bool operator==(AppState b);
		virtual bool operator!=(AppState b);
	protected:
		String *id=nullptr;
};

#endif 
