

#ifndef Statement_h
#define Statement_h

#ifndef ame_Enviroment_Defined
	#include "Arduino.h"
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
		List<String>* syntaxList = nullptr;
};

}

#endif 