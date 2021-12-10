
#ifndef MonkeyOS_hpp
#define MonkeyOS_hpp

#include "OS.hpp"
#include "Driver.hpp"
#include "ThreadControl.hpp"
#include "Kernel.hpp"
#include "MemoryManager.hpp"

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
