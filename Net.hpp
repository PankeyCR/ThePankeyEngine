
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Net)
	#define Net_hpp
#endif

#ifndef Net_hpp
#define Net_hpp
#define Net_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

class Net{
    public:
		Net(){}
		Net(const T& a_variable){
			m_variable = a_variable;
		}
		virtual ~Net(){}
		
		virtual void compute(Net<T>* a_Net){
			m_Net = a_Net;
		}
		
		virtual Net<T>& step(){
			return *m_Net;
		}
		
		virtual operator=(const T& a_variable){
			m_variable = a_variable;
		}
	protected:
		T m_variable;
		
		Net<T>* m_Net = nullptr;
};

}

#endif