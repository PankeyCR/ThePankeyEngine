

#ifndef RenderState_h
#define RenderState_h

#include "AppState.h"
#include "RenderManager.h"

class RenderState : public AppState{
    public:
		RenderState(){}
		virtual ~RenderState(){}
		virtual bool instanceof(cppObjectClass* cls){return Class<RenderState>::classType || AppState::instanceof(cls);}
		virtual void RenderUpdate(RenderManager* manager){}
	protected:
};

#endif 
