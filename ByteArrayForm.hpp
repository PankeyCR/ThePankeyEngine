
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ByteArrayForm)
	#define ByteArrayForm_hpp
#endif

#ifndef ByteArrayForm_hpp
#define ByteArrayForm_hpp
#define ByteArrayForm_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "ByteArray.hpp"

namespace ame{
	
class ByteArrayForm{
public:
ByteArrayForm(){}
virtual ~ByteArrayForm(){}

virtual void setByteArray(const ByteArray& array){}

virtual ByteArray getByteArray(){return 0;}
};

}

#endif