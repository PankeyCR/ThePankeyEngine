
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MonkeyOS)
	#define MonkeyOS_hpp
#endif

#ifndef MonkeyOS_hpp
#define MonkeyOS_hpp
#define MonkeyOS_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "OS.hpp"
#include "Driver.hpp"
#include "ThreadControl.hpp"
#include "Kernel.hpp"
#include "MemoryManager.hpp"

#ifdef MonkeyOSLogApp
	#include "Logger.hpp"
	#define MonkeyOSLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define MonkeyOSLog(name,method,type,mns) 
#endif

namespace ame{

class MonkeyOS : public OS{
    public:
		MonkeyOS(){}
		virtual ~MonkeyOS(){}
		
		virtual void addDriver(Driver* driver){
			// drivers->add(driver);
		}
		
		virtual Driver* getDriver(cppObjectClass* cls){}
		
		virtual void setThreadControl(ThreadControl* threadcontrol){}
		
		virtual ThreadControl* getThreadControl(){}
		
		virtual Kernel* setKernel(Kernel* kernel){}
		
		virtual Kernel* getKernel(){}
		
		virtual MemoryManager* setMemoryManager(MemoryManager* memory){
			m_manager = memory;
		}
		
		virtual MemoryManager* getMemoryManager(){return m_manager;}
		
		virtual Application* addApplication(Application* app){
			return nullptr;
		}
		
		virtual Application* removeApplication(UUID& uuid){
			return nullptr;
		}
		
		virtual void removeDeleteApplication(UUID& uuid){}
		
		virtual Application* getApplication(UUID& uuid){
			return nullptr;
		}
		
		virtual void initialize(){}
		
		virtual void update(){}
		
		virtual void maintain(){}
		
		virtual void sync(){}
		
		virtual void recycle(){}
		
		virtual void start(){}
		
		virtual void stop(){}
		
		virtual void run(const Note& note){}
		
	protected:
		// PrimitiveRawList<Driver> drivers;
		MemoryManager* m_manager = nullptr;
};

}

#endif