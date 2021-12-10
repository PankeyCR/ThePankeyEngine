
#ifndef MemoryManagerState_h
#define MemoryManagerState_h

#ifndef ame_Enviroment_Defined
	#include "Arduino.h"
#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "MemoryManager.hpp"
#include "ManegedMemory.hpp"
#include "DefaultMemoryManager.hpp"
#include "Application.hpp"
#include "AppState.hpp"
/*
namespace ame{

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

}
*/
#endif 
