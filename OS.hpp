
#include "ame_Enviroment.hpp"

#if defined(DISABLE_OS)
	#define OS_hpp
#endif

#ifndef OS_hpp
#define OS_hpp
#define OS_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Driver.hpp"
#include "ThreadControl.hpp"
#include "Kernel.hpp"
#include "MemoryManager.hpp"
#include "Application.hpp"
#include "UUID.hpp"

namespace ame{

class OS{
    public:
		virtual ~OS(){}
		
		virtual void addDriver(Driver* driver)=0;
		
		virtual Driver* getDriver(cppObjectClass* cls)=0;
		
		virtual void setThreadControl(ThreadControl* threadcontrol)=0;
		
		virtual ThreadControl* getThreadControl()=0;
		
		virtual Kernel* setKernel(Kernel* kernel)=0;
		
		virtual Kernel* getKernel()=0;
		
		virtual MemoryManager* setMemoryManager(MemoryManager* memory)=0;
		
		virtual MemoryManager* getMemoryManager()=0;
		
		virtual Application* addApp(Application* app)=0;
		
		virtual Application* removeApp(UUID& uuid)=0;
		
		virtual void removeDeleteApp(UUID& uuid)=0;
		
		virtual Application* getApp(UUID& uuid)=0;
		
		virtual void initialize()=0;
		
		virtual void update()=0;
		
		virtual void maintain()=0;
		
		virtual void sync()=0;
		
		virtual void recycle()=0;
		
		virtual void start()=0;
		
		virtual void stop()=0;
		
		virtual void run(const Note& note)=0;
};

}

#endif