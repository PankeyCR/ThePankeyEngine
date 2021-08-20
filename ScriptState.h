

#ifndef ScriptState_h
#define ScriptState_h

#include "Arduino.h"
#include "Application.h"
#include "AppState.h"
#include "List.h"
#include "Script.h"
#include "PrimitiveList.h"

namespace ame{

class ScriptState : public AppState{
    public:
		ScriptState();
		virtual ~ScriptState();
		
		virtual void initialize(Application *app);
		virtual void update();
		
		virtual void addScript(Script* script);
		virtual void addLoopScript(Script* script);
		
		virtual void runScript(const String& c);
		virtual void runScript(const char* c);
		
		cppObjectClass* getClass();
		String toString();
		
	protected:
		List<Script>* scripts = nullptr;
		List<Script>* loopScripts = nullptr;
};

}

#endif 
