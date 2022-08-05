
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Command)
	#define Command_hpp
#endif

#ifndef Command_hpp
#define Command_hpp
#define Command_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

template<class C>
class Command {
    private:
	
    public:
		Command(){}
		virtual ~Command(){}
		virtual void execute(C* c){
			
		}
		virtual void operator=(Command<C> b){
			
		}
		virtual bool operator==(Command<C> b){
			return true;
		}
		virtual bool operator!=(Command<C> b){
			return false;
		}
};

}

#endif