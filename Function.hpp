
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Function)
	#define Function_hpp
#endif

#ifndef Function_hpp
#define Function_hpp
#define Function_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "cppObject.hpp"

namespace ame{

template<class T,class... args>
class Function : public cppObject{
// #if defined(ame_upToLevel_6)
// class Function{
// #elif defined(ame_upToLevel_7)
// class Function : public cppObject{
// #endif
	public:
		Function(){}
		virtual ~Function(){}
		virtual T f(args... mf)=0;
	protected:
};

}

#endif