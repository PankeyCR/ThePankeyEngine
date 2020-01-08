
#ifndef DefaultStateManager_h
#define DefaultStateManager_h

#include "PrimitiveList.h"
#include "AppStateManager.h"
#include "List.h"
#include "PrimitiveList.h"

class DefaultStateManager : public AppStateManager{
    public:
		DefaultStateManager();
		virtual ~DefaultStateManager();
		
		virtual void setApplication(Application *app);
		
		virtual AppState *add(AppState *state);
		virtual AppState *get(String classname);
		virtual AppState *get(String appstateId,String classname);
		virtual AppState *remove(String classname);
		virtual AppState *remove(String appstateId,String classname);
		virtual bool contain(String classname);
		virtual bool contain(String appstateId,String classname);
		virtual void removeAll();
		virtual void removeDeleteAll();
		
		virtual void update();
		
		//cppObject part
		virtual String getClassName();
		virtual String toString();
    
	private:
		List<AppState> *appStateList;
		Application *managerApp;
};

#endif
