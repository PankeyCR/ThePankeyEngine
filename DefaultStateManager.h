
#ifndef DefaultStateManager_h
#define DefaultStateManager_h

#include "PrimitiveList.h"
#include "AppStateManager.h"
#include "List.h"
#include "PrimitiveList.h"

namespace ame{

class DefaultStateManager : public AppStateManager{
    public:
		DefaultStateManager();
		virtual ~DefaultStateManager();
		
		virtual void setApplication(Application* app);
		
		virtual AppState* add(AppState* state);
		
		virtual AppState* get(cppObjectClass* cls);
		virtual AppState* get(String appstateId, cppObjectClass* cls);
		
		virtual AppState* remove(cppObjectClass* cls);
		virtual AppState* remove(String appstateId, cppObjectClass* cls);
		
		virtual bool contain(cppObjectClass* cls);
		virtual bool contain(String appstateId, cppObjectClass* cls);
		
		virtual void removeAll();
		virtual void removeDeleteAll();
		
		virtual void update();
		
		virtual float tpc();
		
		//cppObject part
		virtual cppObjectClass* getClass();
		virtual String toString();
		virtual bool instanceof(cppObjectClass* cls);
    
	protected:
		List<AppState> *appStateList;
		Application *managerApp;
		long now = 0;
		long prev = 0;
		float t = 0;
};

}

#endif
