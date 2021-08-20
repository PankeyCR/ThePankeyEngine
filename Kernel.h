

#ifndef Kernel_h
#define Kernel_h

#include "Note.h"

namespace ame{
	
class OS;

class Kernel{
    public:
		Kernel(){}
		virtual ~Kernel(){}
		
		void setOS(OS* m){
			os = m;
		}
		
		virtual void run(Note cmd){
		}
		
		virtual void initialize(){}
		
		virtual void update(){}
	protected:
		OS* os = nullptr;
};

}

#endif 
