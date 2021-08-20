

#ifndef AnalogRead_h
#define AnalogRead_h

#include "Arduino.h"
#include "AbstractRead.h"

namespace ame{
	
class AnalogRead : public AbstractRead{
	public:
		AnalogRead(int pin);
		~AnalogRead();
		virtual void Read();
	private:
		int Rpin=0;
};

}

#endif 
