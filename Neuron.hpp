
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Neuron)
	#define Neuron_hpp
#endif

#ifndef Neuron_hpp
#define Neuron_hpp
#define Neuron_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "DataSet.hpp"
#include "Function.hpp"
#include "Logger.hpp"

namespace ame{

class Neuron{
	public:
	
	Neuron(){}
	virtual ~Neuron(){}
	
	float weight = 1;
	float data = 1;
};

}

#endif