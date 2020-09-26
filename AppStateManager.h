
#ifndef AppStateManager_h
#define AppStateManager_h

#include "AppState.h"

class Application;

class AppStateManager : public cppObject{
    public:
		virtual void setApplication(Application *app)=0;
		
		virtual AppState* add(AppState* state)=0;
		virtual AppState* get(String classname)=0;
		virtual AppState* get(String appstateId,String classname)=0;
		virtual AppState* remove(String classname)=0;
		virtual AppState* remove(String appstateId,String classname)=0;
		virtual bool contain(String classname)=0;
		virtual bool contain(String appstateId,String classname)=0;
		virtual void removeAll()=0;
		virtual void removeDeleteAll()=0;
		
		virtual void update()=0;
	private:
};

#endif
