
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Statement)
	#define Statement_hpp
#endif

#ifndef Statement_hpp
#define Statement_hpp
#define Statement_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif


#include "GameObject.hpp"
#include "List.hpp"

namespace ame{

class Statement{
    public:
		Statement(){}
		virtual ~Statement(){}
		
		virtual void operator=(Statement b){}
		virtual bool operator==(Statement b){return false;}
		virtual bool operator!=(Statement b){return false;}
	protected:
		List<Note>* syntaxList = nullptr;
};

}

#endif