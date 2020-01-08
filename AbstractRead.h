

#ifndef AbstractRead_h
#define AbstractRead_h

#include "Arduino.h"

class AbstractRead{
	public:
		AbstractRead();
		virtual ~AbstractRead();
		virtual void Read();
		virtual float getReading();
		virtual void operator=(AbstractRead b);
		virtual bool operator==(AbstractRead b);
		virtual bool operator!=(AbstractRead b);
	protected:
		float read = 0;
};

#endif 
