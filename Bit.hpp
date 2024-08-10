
#include "higgs_Enviroment.hpp"

#if defined(DISABLE_Bit)
	#define Bit_hpp
#endif

#ifndef Bit_hpp
#define Bit_hpp
#define Bit_AVAILABLE

#ifndef higgs_Enviroment_Defined

#endif

#ifdef higgs_Windows

#endif

#ifdef higgs_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Note.hpp"
#include "cppObject.hpp"
#include "Class.hpp"

namespace higgs{

class Bit : public cppObject{
    public:
		Bit(){}
		Bit(const Bit& a_bit){
			m_name = a_bit.m_name;
		}
		Bit(const Note& a_name){
			m_name = a_name;
		}
		Bit(const char* a_name){
			m_name = a_name;
		}
		virtual ~Bit(){}
		
		virtual void update(float tpc){}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<Bit>::classType || cls == Class<cppObject>::classType;
		}
		virtual void operator=(const Bit& a_bit){
			m_name = a_bit.m_name;
		}
		virtual bool operator==(const Bit& a_bit){
			return this->m_name == a_bit.m_name;
		}
		virtual bool operator!=(const Bit& a_bit){
			return this->m_name != a_bit.m_name;
		}
		virtual void operator=(const Note& a_name){
			m_name = a_name;
		}
		virtual bool operator==(Note a_name){
			return this->m_name == a_name;
		}
		virtual bool operator!=(Note a_name){
			return this->m_name != a_name;
		}
	protected:
		bool m_variable = false;
		Note m_name = "";
};

}

#endif
