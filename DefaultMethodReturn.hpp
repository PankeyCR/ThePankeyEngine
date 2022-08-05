
#include "ame_Enviroment.hpp"

#if defined(DISABLE_DefaultMethodReturn)
	#define DefaultMethodReturn_hpp
#endif

#ifndef DefaultMethodReturn_hpp
#define DefaultMethodReturn_hpp
#define DefaultMethodReturn_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{
	
template<class T, class R>
struct DefaultMethodReturn{
	static R* m_return_method;
	
	static void set(R a_r){
		if(m_return_method == nullptr){
			m_return_method = new R();
		}
		*m_return_method = a_r;
	}
	static R getReturn(){
		if(m_return_method == nullptr){
			return R();
		}
		*m_return_method;
	}
};

template<class T, class R> R* DefaultMethodReturn<T,R>::m_return_method = nullptr;

}

#endif