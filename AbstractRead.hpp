
#include "ame_Enviroment.hpp"

#if defined(DISABLE_AbstractRead)
	#define AbstractRead_hpp
#endif

#ifndef AbstractRead_hpp
#define AbstractRead_hpp
#define AbstractRead_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif


namespace ame{
	
class AbstractRead{
	public:
		AbstractRead(){}
		virtual ~AbstractRead(){}
		virtual void Read(){}
		virtual float getReading(){
			return this->read;
		}
		virtual AbstractRead& operator=(AbstractRead b){return *this;}
		virtual bool operator==(AbstractRead b){return true;}
		virtual bool operator!=(AbstractRead b){return true;}
	protected:
		float read = 0;
};

}

#endif