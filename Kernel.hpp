
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Kernel)
	#define Kernel_hpp
#endif

#ifndef Kernel_hpp
#define Kernel_hpp
#define Kernel_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "Note.hpp"

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