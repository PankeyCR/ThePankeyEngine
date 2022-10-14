
#ifndef DefaultApplication_hpp
#define DefaultApplication_hpp
#define DefaultApplication_AVAILABLE

#include "Application.hpp"
#include "DefaultStateManager.hpp"
#include "SimpleTimer.hpp"
#include "DefaultSettings.hpp"

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
			AppStateManager* c_state_manager = this->setStateManager(new DefaultStateManager());
			c_state_manager->setApplication(this);
			this->setSettings(new DefaultSettings());
			this->setTimeControl(SimpleTimer::getInstance());
			DefaultApplicationLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		virtual ~DefaultApplication(){}

		virtual void update(){
			DefaultApplicationLog(ame_Log_StartMethod, "update", "println", "");
			AppStateManager* u_states = this->getStateManager();
			if(u_states == nullptr){
				return;
			}
			MemoryPool* u_pool = this->getMemoryPool();
			if(u_pool != nullptr){
				DefaultApplicationLog(ame_Log_Statement, "update", "println", "MemoryPool update");
				u_pool->update(u_states->tpc());
			}
			RenderManager* u_render = this->getRenderManager();
			if(u_render != nullptr){
				DefaultApplicationLog(ame_Log_Statement, "update", "println", "RenderManager update");
				u_render->update(u_states->tpc());
			}
			u_states->update();
			DefaultApplicationLog(ame_Log_EndMethod, "update", "println", "");
		}

		//cppObject part
		virtual cppObjectClass* getClass(){
			return Class<DefaultApplication>::classType;
		}

		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<DefaultApplication>::classType || Application::instanceof(cls);
		}

	protected:
};

}

#endif