
#include "ame_Enviroment.hpp"

#if defined(DISABLE_)
	#define _hpp
#endif

#ifndef IFStatement_hpp
#define IFStatement_hpp
#define _AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "cppObject.hpp"
#include "Annotation.hpp"

namespace ame{

class IFStatement : public GameOn{
    public:		
		IFStatement();
		virtual ~IFStatement();
	protected:
};

}

#endif