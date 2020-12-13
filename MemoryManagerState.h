
#ifndef MemoryManagerState_h
#define MemoryManagerState_h

#include "MessageProtocol.h"
#include "MemoryManager.h"
#include "ManegedMemory.h"
#include "DefaultMemoryManager.h"
#include "Application.h"
#include "AppState.h"
#include "Arduino.h"

template<class T>
class MemoryManagerState : public AppState{	
    public:
		MemoryManagerState(){
		}
		MemoryManagerState(MemoryManager* m){
			manager = m;
		}
		virtual ~MemoryManagerState(){
		}
		void setId(String s){
			if(this->id == nullptr){
				this->id = new String(s);
				return;
			}
			delete this->id;
			this->id = new String(s);
		}
		
		virtual void initialize(Application *app){
			if(manager == nullptr){
				manager = new DefaultMemoryManager<T>();
			}
			if(Memory<T>::manager == nullptr){
				Memory<T>::manager = manager;
			}
		}
		
		virtual void update(float tpc){
			if(manager != nullptr){
				manager->maintain(tpc);
			}
		}
		
		virtual MemoryManager* getMemoryManager(){
			return manager;
		}

		
	protected:
		MemoryManager* manager = nullptr;
};
#endif 
