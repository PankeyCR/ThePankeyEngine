
#ifndef FixStateManager_h
#define FixStateManager_h

#include "PrimitiveList.h"
#include "AppStateManager.h"
#include "Map.h"
#include "KPMap.h"

class FixStateManager : public AppStateManager{
    public:
		FixStateManager();
		FixStateManager(Application *app);
		~FixStateManager();
		
		virtual void setApplication(Application *app);
		
		virtual AppState *add(String name,AppState *state);
		virtual AppState *get(String name);
		virtual AppState *remove(String name);
		virtual bool contain(String name);
		virtual void removeAll();
		virtual void removeDeleteAll();
		
		virtual void update()=0;
		
		//cppObject part
		virtual void onDelete();
		virtual String getClassName();
		virtual String toString();
		virtual FixStateManager *clone();
    
	private:
		Map<String,AppState> *appStateMap;
		Application *managerApp;
};

#endif
