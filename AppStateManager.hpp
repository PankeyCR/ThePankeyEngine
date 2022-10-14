
#ifndef AppStateManager_hpp
#define AppStateManager_hpp
#define AppStateManager_AVAILABLE

#include "Note.hpp"
#include "AppState.hpp"
#include "AbstractClass.hpp"

namespace ame{

class AppStateManager : public cppObject{
    public:
		virtual ~AppStateManager(){}
		
		virtual void setApplication(Application *app){
			this->m_application = app;
		}
		
		virtual Application* getApplication(){return this->m_application;}
		
		template<class T>
		T* addState(T* state){
			this->add(state);
			return state;
		}
		
		template<class T>
		T* getState(){
			AppState* state = this->get(Class<T>::classType);
			if(state == nullptr){
				return nullptr;
			}
			return (T*)state;
		}
		
		template<class T>
		T* getState(Note appstateId){
			AppState* state = this->get(appstateId, Class<T>::classType);
			if(state == nullptr){
				return nullptr;
			}
			return (T*)state;
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
		virtual AppState* add(Note a_id, AppState* state){
			if(state == nullptr){
				return nullptr;
			}
			state->setId(a_id);
			return add(state);
		}
		
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
			return AbstractClass<AppStateManager>::classType;
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == AbstractClass<AppStateManager>::classType;
		}
	protected:
		Application* m_application = nullptr;
};

}

#endif
