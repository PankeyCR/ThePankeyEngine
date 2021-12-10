/*
The listener memory is not manged by this class

*/

#include "ame_Level.hpp"

#if defined(ame_untilLevel_5)

#ifndef DefaultApplication_hpp
#define DefaultApplication_hpp

	#include "Arduino.h"
#if defined(ame_untilLevel_5)
	#include "Application.hpp"
	#include "AppStateManager.hpp"
	#include "DefaultStateManager.hpp"
#endif 
#if defined(ame_untilLevel_6)
	#include "TimeControl.h"
	#include "SimpleTimer.h"
#endif 
#if defined(ame_untilLevel_6)
	#include "Listener.hpp"
#endif 
#if defined(ame_untilLevel_7)
	#include "AppSettings.hpp"
	#include "DefaultSettings.hpp"
#endif 
#if defined(ame_untilLevel_8)
	#include "MemoryPool.hpp"
#endif 

namespace ame{
	
class DefaultApplication : public Application{
	public:
		DefaultApplication(){
			this->states = new DefaultStateManager();
			this->states->setApplication(this);
			#if defined(ame_untilLevel_7)
			this->settings = new DefaultSettings();
			#endif 
		}
		virtual ~DefaultApplication(){
			delete this->states;
			#if defined(ame_untilLevel_7)
			delete this->settings;
			#endif 
		}

		#if defined(ame_untilLevel_7)
		virtual void setSettings(AppSettings *set){
			if(set != nullptr && this->settings != set){
				delete this->settings;
			}
			this->settings = set;
		}
		virtual AppSettings *getSettings(){
			return this->settings;
		}
		#endif 

		virtual void setStateManager(AppStateManager *manager){
			if(manager != nullptr && this->states != manager){
				delete this->states;
			}
			this->states = manager;
		}
		virtual AppStateManager *getStateManager(){
			return this->states;
		}
				
		#if defined(ame_untilLevel_6)
		virtual void setTimeControl(TimeControl *timecontrol){}
		virtual TimeControl *getTimeControl(){
			return SimpleTimer::getInstance();
		}
		#endif 

		#if defined(ame_untilLevel_6)
		virtual Listener* setListener(Listener* l){
			listener = l;
			listener->attach(this);
			return l;
		}
		virtual Listener* getListener(){
			return listener;
		}
		#endif 

		#if defined(ame_untilLevel_8)
		virtual MemoryPool* setMemoryPool(MemoryPool* l){
			memory = l;
			return l;
		}
		virtual MemoryPool* getMemoryPool(){
			return memory;
		}
		#endif 

		virtual void update(){
			this->states->update();
			#if defined(ame_untilLevel_6)
			if(listener != nullptr){
				listener->InterruptEvent(this->states->tpc());
			}
			#endif
			#if defined(ame_untilLevel_8)
			if(memory != nullptr){
				memory->update(this->states->tpc());
			}
			#endif
		}

		//cppObject part
		virtual cppObjectClass* getClass(){
			return Class<DefaultApplication>::classType;
		}
		virtual String toString(){
			return "DefaultApplication";
		}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<DefaultApplication>::classType || Application::instanceof(cls);
		}

	private:
		AppStateManager *states = nullptr;
		#if defined(ame_untilLevel_7)
		AppSettings *settings = nullptr;
		#endif
		#if defined(ame_untilLevel_6)
		Listener *listener = nullptr;
		#endif
		#if defined(ame_untilLevel_8)
		MemoryPool *memory = nullptr;
		#endif
};

}

#endif 

#endif 
