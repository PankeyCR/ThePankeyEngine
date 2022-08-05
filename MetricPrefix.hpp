
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MetricPrefix)
	#define MetricPrefix_hpp
#endif

#ifndef MetricPrefix_hpp
#define MetricPrefix_hpp
#define MetricPrefix_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

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