

#ifndef AbstractRead_h
#define AbstractRead_h

#include "Arduino.h"

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
