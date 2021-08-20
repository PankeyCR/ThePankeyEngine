
#ifndef AppStateManager_h
#define AppStateManager_h

#include "AppState.h"
#include "cppObjectClass.h"
#include "ClassType.h"

namespace ame{

class Application;

class AppStateManager : public cppObject{
    public:
		virtual void setApplication(Application *app)=0;
		
		template<class T>
		T* addState(T* state){
			this->add(state);
			return state;
		}/*
		template<class T>
		T* getState(){
			return this->get(ClassType<T>::classType);
		}
		template<class T>
		T* removeState(){
			return this->remove(ClassType<T>::classType);
		}
		template<class T>
		void removeDeleteState(){
			AppState* s = this->remove(ClassType<T>::classType);
			if(s != nullptr){
				delete s;
			}
		}*/
		virtual AppState* add(AppState* state)=0;
		
		virtual AppState* get(cppObjectClass* cls)=0;
		virtual AppState* get(String appstateId, cppObjectClass* cls)=0;
		
		virtual AppState* remove(cppObjectClass* cls)=0;
		virtual AppState* remove(String appstateId,cppObjectClass* cls)=0;
		
		virtual void removeDelete(cppObjectClass* cls){
			AppState* appState = this->remove(cls);
			if(appState == nullptr){
				return;
			}
			delete appState;
		}
		virtual void removeDelete(String appstateId,cppObjectClass* cls){
			AppState* appState = this->remove(appstateId,cls);
			if(appState == nullptr){
				return;
			}
			delete appState;
		}
		virtual bool contain(cppObjectClass* cls)=0;
		virtual bool contain(String appstateId,cppObjectClass* cls)=0;
		virtual void removeAll()=0;
		virtual void removeDeleteAll()=0;
		
		virtual void update()=0;
		
		virtual float tpc()=0;
		
		virtual cppObjectClass* getClass(){
			return Class<AppStateManager>::classType;
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<AppStateManager>::classType;
		}
	private:
};

}

#endif
