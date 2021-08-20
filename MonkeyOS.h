

#ifndef MonkeyOS_h
#define MonkeyOS_h

#include "OS.h"
#include "Driver.h"
#include "ThreadControl.h"
#include "Kernel.h"
#include "MemoryManager.h"

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
		
		virtual MemoryManager* setMemoryManager(MemoryManager* memory){}
		
		virtual MemoryManager* getMemoryManager(){}
		
		virtual void initialize(){}
		
		virtual void update(){}
		
		virtual void start(){}
		
		virtual void stop(){}
		
	protected:
		// PrimitiveRawList<Driver> drivers;
};

}

#endif 
