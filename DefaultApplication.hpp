/*
The listener memory is not manged by this class

*/

#include "ame_Enviroment.hpp"

#if defined(DISABLE_Application) || defined(DISABLE_DefaultApplication)
	#define DefaultApplication_hpp
#endif

#ifndef DefaultApplication_hpp
#define DefaultApplication_hpp
#define DefaultApplication_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Application.hpp"
#include "AppStateManager.hpp"
#include "DefaultStateManager.hpp"
#include "TimeControl.hpp"
#include "SimpleTimer.hpp"
#include "Listener.hpp"
#include "AppSettings.hpp"
#include "DefaultSettings.hpp"
#include "MemoryPool.hpp"
#include "RenderManager.hpp"

#ifdef DefaultApplication_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define DefaultApplicationLog(location,method,type,mns) ame_Log(this,location,"DefaultApplication",method,type,mns)
	#define const_DefaultApplicationLog(location,method,type,mns) 
	#define StaticDefaultApplicationLog(pointer,location,method,type,mns) ame_Log(pointer,location,"DefaultApplication",method,type,mns)
#else
	#ifdef DefaultApplication_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define DefaultApplicationLog(location,method,type,mns) ame_LogDebug(this,location,"DefaultApplication",method,type)
		#define const_DefaultApplicationLog(location,method,type,mns) 
		#define StaticDefaultApplicationLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"DefaultApplication",method,type)
	#else
		#define DefaultApplicationLog(location,method,type,mns) 
		#define const_DefaultApplicationLog(location,method,type,mns) 
		#define StaticDefaultApplicationLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{

class DefaultApplication : public Application{
	public:
		DefaultApplication(){
			DefaultApplicationLog(ame_Log_StartMethod, "Constructor", "println", "");
			this->states = new DefaultStateManager();
			this->states->setApplication(this);
			#if defined(AppSettings_AVAILABLE)
			this->settings = new DefaultSettings();
			#endif
			DefaultApplicationLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		virtual ~DefaultApplication(){
			DefaultApplicationLog(ame_Log_StartMethod, "Destructor", "println", "");
			delete this->states;
			#if defined(AppSettings_AVAILABLE)
			delete this->settings;
			#endif
			DefaultApplicationLog(ame_Log_EndMethod, "Destructor", "println", "");
		}

		#if defined(AppSettings_AVAILABLE)
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

		#if defined(TimeControl_AVAILABLE)
		virtual void setTimeControl(TimeControl *timecontrol){}
		virtual TimeControl *getTimeControl(){
			return SimpleTimer::getInstance();
		}
		#endif

		#if defined(Listener_AVAILABLE)
		virtual Listener* setListener(Listener* l){
			listener = l;
			listener->attach(this);
			return l;
		}
		virtual Listener* getListener(){
			return listener;
		}
		#endif

		#if defined(RenderManager_AVAILABLE)
		virtual RenderManager* setRenderManager(RenderManager* r){
			render = r;
			return r;
		}
		virtual RenderManager* getRenderManager(){
			return render;
		}
		#endif

		#if defined(MemoryPool_AVAILABLE)
		virtual MemoryPool* setMemoryPool(MemoryPool* l){
			memory = l;
			return l;
		}
		virtual MemoryPool* getMemoryPool(){
			return memory;
		}
		#endif

		virtual void update(){
			// #if defined(DefaultApplication_LogApp_AVAILABLE)
			// ame_LogDebug(this,ame_Log_Error,"DefaultApplication","update", "println");
			// #endif
			DefaultApplicationLog(ame_Log_StartMethod, "update", "println", "");
			this->states->update();
			#if defined(Listener_AVAILABLE)
			#ifdef ame_Windows
			DefaultApplicationLog(ame_Log_Statement, "update", "println", "Windows update");

			#endif

			#ifdef ame_ArduinoIDE
			if(listener != nullptr){
				DefaultApplicationLog(ame_Log_Statement, "update", "println", "Listener update");
				listener->InterruptEvent(this->states->tpc());
			}
			#endif
			#endif
			#if defined(RenderManager_AVAILABLE)
			if(render != nullptr){
				DefaultApplicationLog(ame_Log_Statement, "update", "println", "Memory update");
				render->update(this->states->tpc());
			}
			#endif
			#if defined(MemoryPool_AVAILABLE)
			if(memory != nullptr){
				DefaultApplicationLog(ame_Log_Statement, "update", "println", "Memory update");
				memory->update(this->states->tpc());
			}
			#endif
			DefaultApplicationLog(ame_Log_EndMethod, "update", "println", "");

		}

		//cppObject part
		virtual cppObjectClass* getClass(){
			return Class<DefaultApplication>::classType;
		}
		virtual Note toNote(){
			return "DefaultApplication";
		}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<DefaultApplication>::classType || Application::instanceof(cls);
		}

	private:
		AppStateManager *states = nullptr;
		#if defined(AppSettings_AVAILABLE)
		AppSettings *settings = nullptr;
		#endif
		#if defined(Listener_AVAILABLE)
		Listener *listener = nullptr;
		#endif
		#if defined(MemoryPool_AVAILABLE)
		MemoryPool *memory = nullptr;
		#endif
		#if defined(RenderManager_AVAILABLE)
		RenderManager *render = nullptr;
		#endif
		
};

}

#endif