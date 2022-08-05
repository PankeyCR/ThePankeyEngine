
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Parameter)
	#define Parameter_hpp
#endif

#ifndef Parameter_hpp
#define Parameter_hpp
#define Parameter_AVAILABLE

namespace ame{

class Parameter{
public:
Parameter(){}
virtual ~Parameter(){}

virtual cppObjectClass* getClass(){return nullptr;}

virtual void operator=(Parameter b){}
virtual bool operator==(Parameter b){return true;}
virtual bool operator!=(Parameter b){return false;}
protected:
};

}

#endif
