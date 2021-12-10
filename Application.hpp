
#include "ame_Level.hpp"

#if defined(ame_untilLevel_5)

#ifndef Application_hpp
#define Application_hpp

#if defined(ame_untilLevel_5)
#include "AppStateManager.hpp"
#endif 
#if defined(ame_untilLevel_7)
#include "AppSettings.hpp"
#endif 
#if defined(ame_untilLevel_6)
#include "TimeControl.h"
#endif 
#if defined(ame_untilLevel_8)
#include "MemoryPool.hpp"
#endif 
#include "cppObject.hpp"
#if defined(ame_untilLevel_6)
#include "Listener.hpp"
#endif 

namespace ame{

class Application : public cppObject{
    public:
		virtual ~Application(){}
		
		virtual void setStateManager(AppStateManager *appstate)=0;
		
		virtual AppStateManager *getStateManager()=0;
		
		#if defined(ame_untilLevel_7)
		virtual void setSettings(AppSettings *setting)=0;
		
		virtual AppSettings *getSettings()=0;
		#endif 
		
		#if defined(ame_untilLevel_6)
		virtual void setTimeControl(TimeControl *timecontrol)=0;
		
		virtual TimeControl *getTimeControl()=0;
		#endif 
		
	/*	virtual void setAssetManager(AssetManager *assets){
			
		}
		virtual AssetManager *getAssetManager(){
			
		}*/
		
		#if defined(ame_untilLevel_6)
		virtual Listener* setListener(Listener* listener)=0;
		
		virtual Listener* getListener()=0;
		#endif 
		#if defined(ame_untilLevel_8)
		virtual MemoryPool* setMemoryPool(MemoryPool* memory)=0;
		
		virtual MemoryPool* getMemoryPool()=0;
		#endif 
		
		virtual void initialize(){}
		
		virtual void update()=0;
    
	private:
};

}

#endif 

#endif 
