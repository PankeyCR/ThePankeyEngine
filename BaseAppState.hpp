
#ifndef CONFIGURATION_BaseAppState_hpp
#define CONFIGURATION_BaseAppState_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_BaseAppState)
		#define BaseAppState_hpp

		#define IMPLEMENTATION_BaseAppState
		#define IMPLEMENTING_BaseAppState
	#else
		#if defined(DISABLE_IMPLEMENTATION_BaseAppState)
			#define IMPLEMENTATION_BaseAppState
			#define IMPLEMENTING_BaseAppState
		#endif
	#endif
#endif

#ifndef BaseAppState_hpp
#define BaseAppState_hpp
#define BaseAppState_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_BaseAppState
	#define IMPLEMENTATION_BaseAppState IMPLEMENTATION(public BaseAppState)
	#define IMPLEMENTING_BaseAppState IMPLEMENTING(public BaseAppState)
#endif

#include "Application.hpp"
#include "Class.hpp"

#ifdef BaseAppState_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define BaseAppStateLog(location,method,type,mns) ame_Log(this,location,"BaseAppState",method,type,mns)
#else
	#ifdef BaseAppState_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define BaseAppStateLog(location,method,type,mns) ame_LogDebug(this,location,"BaseAppState",method,type)
	#else
		#define BaseAppStateLog(location,method,type,mns) 
	#endif
#endif

namespace ame{

/*
*	Class Configuration:
*	DISABLE_IMPLEMENTATION_AppState
*/
class BaseAppState IMPLEMENTATION_AppState {
    public:
		BaseAppState(){}
		virtual ~BaseAppState(){}
		
		#if defined(Application_AVAILABLE)
		virtual void initialize(Application* app){
			BaseAppStateLog(ame_Log_StartMethod, "initialize", "println", "");
			m_app = app;
			m_init = true;
			initializeState(app);
			BaseAppStateLog(ame_Log_EndMethod, "initialize", "println", "");
		}
		
		virtual void initializeState(Application* app){}
		virtual Application* getApplication(){return m_app;}
		#endif
		
		virtual bool hasInitialize(){return m_init;}
		
		virtual void onEnable(){m_enable = true;}
		virtual void onDisable(){m_enable = false;}
		
		virtual bool isEnable(){return m_enable;}
		
		
		virtual void update(float tpc){
			if(!m_enable){
				return;
			}
			updateState(tpc);
		}
		
		virtual void updateState(float tpc){}
		
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){return Class<BaseAppState>::getClass();}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<BaseAppState>::getClass() || AppState::instanceof(cls);
		}
		#endif
	protected:
		Application* m_app = nullptr;
		bool m_enable = false;
		bool m_init = false;
};

}

#endif
