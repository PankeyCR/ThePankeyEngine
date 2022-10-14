
#ifndef BaseAppState_hpp
#define BaseAppState_hpp
#define BaseAppState_AVAILABLE

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

class BaseAppState : public AppState{
    public:
		BaseAppState(){}
		virtual ~BaseAppState(){}
		
		virtual void initialize(Application* app){
			BaseAppStateLog(ame_Log_StartMethod, "initialize", "println", "");
			m_app = app;
			m_init = true;
			initializeState(app);
			BaseAppStateLog(ame_Log_EndMethod, "initialize", "println", "");
		}
		
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
		
		virtual void initializeState(Application* app){}
		
		virtual void updateState(float tpc){}
		
		virtual Application* getApplication(){return m_app;}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<BaseAppState>::classType || cppObject::instanceof(cls);
		}
		virtual cppObjectClass* getClass(){return Class<BaseAppState>::classType;}
	protected:
		Application* m_app = nullptr;
		bool m_enable = false;
		bool m_init = false;
};

}

#endif
