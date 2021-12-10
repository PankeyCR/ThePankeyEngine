
#ifndef OS_hpp
#define OS_hpp

#include "Driver.hpp"
#include "ThreadControl.hpp"
#include "Kernel.hpp"
#include "MemoryManager.hpp"

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
		
		virtual void initialize()=0;
		
		virtual void update()=0;
		
		virtual void start()=0;
		
		virtual void stop()=0;
};

}

#endif 
