

#ifndef Kernel_h
#define Kernel_h

#include "ByteArray.h"

class Kernel{
    public:
		Kernel(){}
		Kernel(const Kernel& k){}
		virtual ~Kernel(){}
		
		virtual void run(ByteArray array){}
		
		virtual void operator =(const Kernel& k){
			
		}
		virtual bool operator ==(const Kernel& k){
			return true;
		}
		virtual bool operator !=(const Kernel& k){
			return true;
		}
		
	protected:
};

#endif 
