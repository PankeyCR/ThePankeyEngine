

#ifndef Environment_h
#define Environment_h

// #include "Kernel.h"
#include "Token.h"
#include "AppSettings.h"

namespace ame{

class Environment : public AppSettings{
    public:
		Environment(){}
		virtual ~Environment(){}
		
		// virtual void setKernel(Kernel k){this->kernel = k;}
		// virtual Kernel getKernel(){return this->kernel;}
		
		virtual bool containVariable(String var){
			return false;
		}
		virtual Token getToken(String var){
			return Token();
		}
	protected:
		// Kernel kernel;
};

}

#endif 
