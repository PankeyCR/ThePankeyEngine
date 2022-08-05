
#include "ame_Enviroment.hpp"

#if defined(DISABLE_RenderState)
	#define RenderState_hpp
#endif

#ifndef RenderState_hpp
#define RenderState_hpp
#define RenderState_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "AppState.hpp"
#include "RenderManager.hpp"
#include "cppObjectClass.hpp"

namespace ame{

class RenderState : public AppState{
    public:
		RenderState(){}
		virtual ~RenderState(){}
		virtual bool instanceof(cppObjectClass* cls){
			return Class<RenderState>::classType || AppState::instanceof(cls);
		}
		virtual void RenderUpdate(RenderManager* manager){}
	protected:
};

}

#endif