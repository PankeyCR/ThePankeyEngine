	
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Environment)
	#define Environment_hpp
#endif

#ifndef Environment_hpp
#define Environment_hpp
#define Environment_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

// #include "Kernel.h"
#include "Token.hpp"
#include "AppSettings.hpp"

namespace ame{

class Environment : public AppSettings{
    public:
		Environment(){}
		virtual ~Environment(){}
		
		// virtual void setKernel(Kernel k){this->kernel = k;}
		// virtual Kernel getKernel(){return this->kernel;}
		
		virtual bool containVariable(Note var){
			return false;
		}
		virtual Token getToken(Note var){
			return Token();
		}
	protected:
		// Kernel kernel;
};

}

#endif