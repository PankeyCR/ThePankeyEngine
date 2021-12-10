
#ifndef RenderState_hpp
#define RenderState_hpp

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
