
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Application)
	#define Application_hpp
#endif

#ifndef Application_hpp
#define Application_hpp
#define Application_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "AppStateManager.hpp"
#include "AppSettings.hpp"
#include "TimeControl.hpp"
#include "MemoryPool.hpp"
#include "Listener.hpp"

#include "cppObject.hpp"

namespace ame{

class Application : public cppObject{
    public:
		virtual ~Application(){}
		
		virtual void setStateManager(AppStateManager *appstate)=0;
		
		virtual AppStateManager *getStateManager()=0;
		
		#if defined(AppSettings_AVAILABLE)
		virtual void setSettings(AppSettings *setting)=0;
		
		virtual AppSettings *getSettings()=0;
		#endif 
		
		#if defined(TimeControl_AVAILABLE)
		virtual void setTimeControl(TimeControl *timecontrol)=0;
		
		virtual TimeControl *getTimeControl()=0;
		#endif 
		
	/*	virtual void setAssetManager(AssetManager *assets){
			
		}
		virtual AssetManager *getAssetManager(){
			
		}*/
		
		#if defined(Listener_AVAILABLE)
		virtual Listener* setListener(Listener* listener)=0;
		
		virtual Listener* getListener()=0;
		#endif 
		#if defined(MemoryPool_AVAILABLE)
		virtual MemoryPool* setMemoryPool(MemoryPool* memory)=0;
		
		virtual MemoryPool* getMemoryPool()=0;
		#endif 
		
		virtual void initialize(){}
		
		virtual void update()=0;
    
	private:
};

}

#endif
