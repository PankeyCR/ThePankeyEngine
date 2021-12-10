

#ifndef ScriptState_hpp
#define ScriptState_hpp

#ifndef ame_Enviroment_Defined
	#include "Arduino.h"
#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Application.hpp"
#include "AppState.hpp"
#include "List.hpp"
#include "Script.hpp"
#include "PrimitiveList.hpp"

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
