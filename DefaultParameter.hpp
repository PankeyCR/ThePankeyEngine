
#include "ame_Enviroment.hpp"

#if defined(DISABLE_DefaultParameter)
	#define DefaultParameter_hpp
#endif

#ifndef DefaultParameter_hpp
#define DefaultParameter_hpp
#define DefaultParameter_AVAILABLE

namespace ame{

template<class T>
class DefaultParameter{
public:
DefaultParameter(){}
virtual ~DefaultParameter(){}

virtual cppObjectClass* getClass(){return nullptr;}

virtual void operator=(DefaultParameter b){}
virtual bool operator==(DefaultParameter b){return true;}
virtual bool operator!=(DefaultParameter b){return false;}
protected:
};

}

#endif
