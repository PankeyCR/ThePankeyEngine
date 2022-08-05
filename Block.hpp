
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Block)
	#define Block_hpp
#endif

#ifndef Block_hpp
#define Block_hpp
#define Block_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Environment.hpp"

namespace ame{

class Block{
    public:
		Block(){}
		virtual ~Block(){}
		
		virtual void setCode(Note c){code = c;}
		virtual Block* run(<T,args...>(Environment* e){return nullptr;}
		
		virtual void operator=(Block b){code = b.code;}
		virtual bool operator==(Block b){code == b.code;}
		virtual bool operator!=(Block b){code != b.code;}
	protected:
		Note code;
};

}

#endif
