

#ifndef Environment_hpp
#define Environment_hpp

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
