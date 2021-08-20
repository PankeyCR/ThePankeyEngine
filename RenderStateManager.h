
#ifndef RenderStateManager_h
#define RenderStateManager_h

#include "PrimitiveList.h"
#include "DefaultStateManager.h"
#include "List.h"
#include "RenderState.h"
#include "RenderManager.h"
#include "DefaultRenderManager.h"

namespace ame{

class RenderStateManager : public DefaultStateManager{
    public:
		RenderStateManager();
		virtual ~RenderStateManager();
		
		virtual void setApplication(Application* app);
		
		virtual AppState* add(AppState* state);
		virtual AppState* remove(cppObjectClass* cls);
		virtual AppState* remove(String appstateId, cppObjectClass* cls);
		virtual void removeAll();
		virtual void removeDeleteAll();
		virtual void update();
		
		//cppObject part
		virtual cppObjectClass* getClass();
		virtual String toString();
		virtual bool instanceof(cppObjectClass* cls);
    
	protected:
		List<RenderState>* appStateRenderList = nullptr;
		RenderManager* renderManager = nullptr;
};

}

#endif
