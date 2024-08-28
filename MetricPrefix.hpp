
#include "pankey_Enviroment.hpp"

#if defined(DISABLE_MetricPrefix)
	#define MetricPrefix_hpp
#endif

#ifndef MetricPrefix_hpp
#define MetricPrefix_hpp
#define MetricPrefix_AVAILABLE

#ifndef pankey_Enviroment_Defined

#endif

#ifdef pankey_Windows

#endif

#ifdef pankey_ArduinoIDE
	#include "Arduino.h"
#endif

namespace pankey{

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