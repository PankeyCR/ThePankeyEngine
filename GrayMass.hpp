
#include "ame_Enviroment.hpp"

#if defined(DISABLE_GrayMass)
	#define GrayMass_hpp
#endif

#ifndef GrayMass_hpp
#define GrayMass_hpp
#define GrayMass_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

class GrayMass{
    public:
		GrayMass(){}
		GrayMass(const GrayMass& a_mass){
			m_variable = a_variable;
		}
		virtual ~GrayMass(){}
		
		template<class T>
		virtual void fillMass(int a_massSize){
			for(int x = 0; x < a_massSize; x++){
				m_grayMass.addPointer(new T());
			}
		}
		
		// virtual void addDataSet(DataSet a_set){}
		// virtual DataSet getDataSet(){}
		
		virtual GrayMass& operator=(const GrayMass& a_variable){
			return *this;
		}
	protected:
		PrimitiveList<Neuron> m_grayMass;
};

}

#endif