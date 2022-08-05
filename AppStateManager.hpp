
#include "ame_Enviroment.hpp"

#if defined(DISABLE_AppStateManager)
	#define AppStateManager_hpp
#endif

#ifndef AppStateManager_hpp
#define AppStateManager_hpp
#define AppStateManager_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "AppState.hpp"
#include "cppObjectClass.hpp"
#include "Class.hpp"

namespace ame{

class Application;

class AppStateManager : public cppObject{
    public:
		virtual void setApplication(Application *app)=0;
		
		template<class T>
		T* addState(T* state){
			this->add(state);
			return state;
		}
		
		template<class T>
		T* getState(){
			AppState* state = this->get(Class<T>::classType);
			if(state->instanceof(Class<T>::classType)){
				return (T*)state;
			}
			return nullptr;
		}
		
		template<class T>
		T* getState(Note appstateId){
			AppState* state = this->get(appstateId, Class<T>::classType);
			if(state->instanceof(Class<T>::classType)){
				return (T*)state;
			}
			return nullptr;
		}
		/*
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
		virtual AppState* get(Note appstateId, cppObjectClass* cls)=0;
		
		virtual AppState* getInitializedState(cppObjectClass* cls)=0;
		virtual AppState* getInitializedState(Note appstateId, cppObjectClass* cls)=0;
		
		virtual AppState* getUnInitializedState(cppObjectClass* cls)=0;
		virtual AppState* getUnInitializedState(Note appstateId, cppObjectClass* cls)=0;
		
		virtual AppState* remove(cppObjectClass* cls)=0;
		virtual AppState* remove(Note appstateId,cppObjectClass* cls)=0;
		
		virtual void removeDelete(cppObjectClass* cls){
			AppState* appState = this->remove(cls);
			if(appState == nullptr){
				return;
			}
			delete appState;
		}
		virtual void removeDelete(Note appstateId,cppObjectClass* cls){
			AppState* appState = this->remove(appstateId,cls);
			if(appState == nullptr){
				return;
			}
			delete appState;
		}
		virtual bool contain(cppObjectClass* cls)=0;
		virtual bool contain(Note appstateId,cppObjectClass* cls)=0;
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
