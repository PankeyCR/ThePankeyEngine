
#include "higgs_Enviroment.hpp"

#if defined(DISABLE_MetricPrefix)
	#define MetricPrefix_hpp
#endif

#ifndef MetricPrefix_hpp
#define MetricPrefix_hpp
#define MetricPrefix_AVAILABLE

#ifndef higgs_Enviroment_Defined

#endif

#ifdef higgs_Windows

#endif

#ifdef higgs_ArduinoIDE
	#include "Arduino.h"
#endif

namespace higgs{

enum class MetricPrefix {
	exa,
	peta,
	tera,
	giga,
	mega,
	kilo,
	hecto,
	deka,
	none,
	deci,
	centi,
	milli,
	micro,
	nano,
	pico,
	femto,
	atto
};

}

#endif