
#ifndef MemoryManagerState_h
#define MemoryManagerState_h

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
		MemoryManagerState(MemoryManager<T>* m){
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
				manager->maintain(tpc,Memory<T>::objSize_t);
			}
		}
		
		virtual MemoryManager<T>* getMemoryManager(){
			return manager;
		}

		
	protected:
		MemoryManager<T>* manager = nullptr;
};
#endif 
