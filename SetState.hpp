
#include "ame_Enviroment.hpp"

#if defined(DISABLE_SetState)
	#define SetState_hpp
#endif

#ifndef SetState_hpp
#define SetState_hpp
#define SetState_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Note.hpp"
#include "AppState.hpp"
#include "Class.hpp"

namespace ame{

class SetState : public AppState{
    public:
		SetState(){}
		virtual ~SetState(){}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<SetState>::classType || cls == Class<AppState>::classType;
		}
		
		virtual void initialize(Application *app){}
		virtual void onEnable(){}
		virtual void onDisable(){}
		
		virtual void update(float tpc){}
	protected:
	
};

}

#endif
