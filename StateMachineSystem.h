
#ifndef StateMachineSystem_h
#define StateMachineSystem_h

#include "Application.h"
#include "AppState.h"
#include "List.h"
#include "Map.h"
#include "PrimitiveMap.h"
#include "PrimitiveList.h"
#include "MachineState.h"

template<class T>
class StateMachineSystem : public AppState{	
    public:
		Map<String,MachineState<T>>* states = nullptr;
		StateMachineSystem(){
			this->states = new PrimitiveMap<String,MachineState<T>>();
		}
		StateMachineSystem(String s){
			this->states = new PrimitiveMap<String,MachineState<T>>();
			this->id = new String(s);
		}
		StateMachineSystem(String s, T* t){
			this->states = new PrimitiveMap<String,MachineState<T>>();
			this->id = new String(s);
			this->system = t;
		}
		StateMachineSystem(String s, T* t, bool own){
			this->states = new PrimitiveMap<String,MachineState<T>>();
			this->id = new String(s);
			this->system = t;
			this->owner = own;
		}
		virtual ~StateMachineSystem(){
			delete this->states;
			if(this->id != nullptr){
				delete this->id;
			}
			if(this->owner){
				delete this->system;
			}
		}
		void setId(String s){
			if(this->id == nullptr){
				this->id = new String(s);
				return;
			}
			delete this->id;
			this->id = new String(s);
		}
		
		void setSystem(T* t){
			if(t == nullptr){
				return;
			}
			if(this->system != nullptr && this->system != t){
				if(this->owner){
					delete this->system;
				}
			}
			this->system = t;
		}
		
		void setState(String state){
			this->actualState = this->states->get(state);
			if(this->actualState == nullptr){
				return;
			}
			iterate(this->states){
				if(this->states->getPointer() == this->actualState){
					this->statePosition = this->states->getIteration();
					return;
				}
			}
		}
		
		void setState(int state){
			this->actualState = this->states->getByPos(state);
			if(this->actualState == nullptr){
				return;
			}
			this->statePosition = state;
		}
		
		void lastState(){
			this->statePosition--;
			this->actualState = this->states->getByPos(this->statePosition);
		}
		
		void nextState(){
			this->statePosition++;
			this->actualState = this->states->getByPos(this->statePosition);
		}
		
		MachineState<T>* getState(){
			return this->actualState;
		}
		
		int getStatePosition(){
			return this->statePosition;
		}
		
		int getStateSize(){
			return this->states->getPos();
		}
			
		virtual void initialize(Application *app){
			this->App = app;
		}
		
		Application* getApplication(){
			return this->App;
		}
		
		virtual void update(float tpc){
			if(this->actualState == nullptr){
				return;
			}
			this->actualState->update(this,this->system,tpc);
		}
	protected:
		int statePosition = 0;
		T* system = nullptr;
		bool owner = false;
		Application* App = nullptr;
		MachineState<T>* actualState = nullptr;
};
#endif 
